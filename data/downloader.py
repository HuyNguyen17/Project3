from igdb.wrapper import IGDBWrapper
import json
import os
import time

CLIENT_ID = "f9qxelmgxgbdzt6ur2j8ktck77y6oj"
CLIENT_SECRET = "rib423zqh61fslfsawigdw4vxqzb70"

#Used following CURL command to get the CLIENT_SECRET:
# curl -i -X POST -H "Content-Type:application/json" -d  "{\"client_id\": \"f9qxelmgxgbdzt6ur2j8ktck77y6oj\", \"client_secret\": \"rib423zqh61fslfsawigdw4vxqzb70\", \"grant_type\": \"client_credentials\"}" https://id.twitch.tv/oauth2/token

ACCESS_TOKEN = "uphihrazcweww9vl729ro989lyms13"

DATA_FILE = "data.json"

# starting here
start_time = time.time()
wrapper = IGDBWrapper(CLIENT_ID, ACCESS_TOKEN)

'''With a wrapper instance already created, we just need to use it to access the API'''
print("Downloading data for game 1")

# JSON API request
byte_array = wrapper.api_request(
            'games',
            'fields id, name, first_release_date, involved_companies.company.name, genres.name, similar_games; where version_parent = null & id = 1;'
          )
# parse into JSON
games_data = json.loads(byte_array.decode())

invalid_games = 0
valid_games = 1
#write to file
with open(DATA_FILE, 'w', encoding='UTF-8') as f:
  json.dump(games_data, f, ensure_ascii=False)

# now append after the first iteration
# seems like 1 in 10 might be invalid, but bump up to 140k to be safe
for i in range(2, 140000):
    try:
        print(f"Downloading data for game {i}")
        # JSON API request
        byte_array = wrapper.api_request(
                    'games',
                    f'fields id, name, first_release_date, involved_companies.company.name, genres.name,similar_games; where version_parent = null & id = {i};'
                  )
        # append the JSON data...
        games_data = json.loads(byte_array.decode())
        game_string = json.dumps(games_data, ensure_ascii=False)
        # need to check that the string we want to write is not empty
        if game_string != "[]":
            # need to remove the last character from the old JSON
            with open(DATA_FILE, 'rb+') as f:
                f.seek(-1, os.SEEK_END)
                f.truncate()

            with open(DATA_FILE, 'a', encoding='UTF-8') as f:
                f.write(',')
                f.write(game_string[1:]) # don't need the first character

            valid_games += 1

        else:
            print(f'Error with game {i}, skipping...')
            invalid_games += 1
    # if any errors occur, skipping the game
    except Exception:
        print(f'Error with game {i}, skipping...')
        invalid_games += 1


end_time = time.time()
print(f"Download completed in {end_time - start_time:.0f} s!")
print(f"{valid_games} games succesfully downloaded")
print(f"{invalid_games} games skipped")