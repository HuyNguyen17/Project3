// Code goes here
#include <iostream>
#include <fstream>
#include "rapidjson/document.h"
#include <chrono>
#include <cstdio>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <iomanip>
#include <vector>
#include <unordered_map>
using namespace rapidjson;
#include "game.h"

bool parseJSONFromFile(const std::string& filename, Document& d)
{
    // Open the file
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return false;
    }

    // Read the entire file into a string
    std::string jsonStr((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    ifs.close();

    d.Parse(jsonStr.c_str());

    // Check if parsing succeeded
    if (d.HasParseError()) {
        std::cerr << "Error parsing JSON: " << GetParseErrorFunc(d.GetParseError()) << std::endl;
        return false;
    }
    return true;
}

std::string timestampToDate(long long timestamp) {
    // Convert timestamp to time_point
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(timestamp);

    // Convert time_point to time_t
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);

    // Convert time_t to struct tm
    std::tm* t = std::localtime(&tt);

    // Format struct tm to a string
    char buffer[80]; // Buffer for the formatted string
    std::strftime(buffer, 80, "%m-%d-%Y", t); // Format: YYYY-MM-DD HH:MM:SS

    return std::string(buffer);
}

game parseGame(const Value::ConstValueIterator mainIter) {
    cout << "\n";
    // main game info
    int gameID;
    string gameName;
    string gameReleaseDate;
    vector<int> similarGames;

    gameID = mainIter->GetObject()["id"].GetInt();
    gameName = mainIter->GetObject()["name"].GetString();
    cout << "Game ID: "  << gameID << "\n";
    cout << "Game Name: "  << gameName << "\n";

    bool hasReleaseDate = mainIter->GetObject().HasMember("first_release_date");
    if (hasReleaseDate)
    {
        gameReleaseDate = timestampToDate(mainIter->GetObject()["first_release_date"].GetInt());
        cout << "Game Release Date: " << gameReleaseDate << "\n";
    }

    // Iterate through the Genres
    bool hasGenre = (mainIter->GetObject().HasMember("genres"));
    unordered_map<int, string> genre;
    if (hasGenre)
    {
        if (mainIter->GetObject()["genres"].IsArray())
        {
            const Value &gameArray = mainIter->GetObject()["genres"];
            cout << "Genre: ";
            for (Value::ConstValueIterator genreIter = gameArray.Begin(); genreIter != gameArray.End(); ++genreIter)
            {
                cout << genreIter->GetObject()["id"].GetInt() << " " << genreIter->GetObject()["name"].GetString() << ", ";
                // add genre to map: id / genre name
                genre.insert(pair<int, string>(genreIter->GetObject()["id"].GetInt(), genreIter->GetObject()["name"].GetString()));
            }
        }
    }

    // Iterate through Involved Companies
    if (mainIter->GetObject().HasMember("involved_companies"))
    {
        if (mainIter->GetObject()["involved_companies"].IsArray()) {
            const Value &involvedCoArray = mainIter->GetObject()["involved_companies"];
            cout << "\nInvolved Companies\n";
            for (Value::ConstValueIterator involvedCoIter = involvedCoArray.Begin(); involvedCoIter != involvedCoArray.End(); ++involvedCoIter) {
                cout << involvedCoIter->GetObject()["id"].GetInt() << "- ";

                // Involved Companies Iterate
                if (involvedCoIter->GetObject()["company"].IsObject())
                {
                    const Value& individualCo = involvedCoIter->GetObject()["company"];
                    Value::ConstMemberIterator individualCoIter = individualCo.FindMember("id");
                    cout << individualCoIter->value.GetInt() << " - ";
                    individualCoIter = individualCo.FindMember("name");
                    cout << individualCoIter->value.GetString() << "\n";
                    // Do we want a vector<int, map<int, string>>
                }
            }
        }
    }

    // Iterate through similar games
    if (mainIter->GetObject().HasMember("similar_games"))
    {
        if (mainIter->GetObject()["similar_games"].IsArray())
        {
            const Value &similarGamesArray = mainIter->GetObject()["similar_games"];
            cout << "Similar Games: ";
            for (SizeType i = 0; i < similarGamesArray.Size(); i++)
            {
                cout << similarGamesArray[i].GetInt() << ", ";
                similarGames.push_back(similarGamesArray[i].GetInt());
            }
        }
    }
    cout << "\n";
    return game(gameID, gameName, gameReleaseDate, similarGames); // can add more but these are good for now
}

int main()
{
    // use smalldata for testing
    //const std::string filename = "../data/data.json";
    const std::string filename = "../data/smalldata.json";

    Document d;
    bool parsed = parseJSONFromFile(filename, d);

    if (!parsed)
    {
        return -1;
    }
    else
    {
        for (Value::ConstValueIterator mainIter = d.Begin(); mainIter != d.End(); ++mainIter)
        {
            parseGame(mainIter);
        }
        return 0;
    }

}