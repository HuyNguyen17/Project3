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

int main()
{
    const std::string filename = "../data/data.json";

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
            std::cout << "\n";
            // main game info
            int gameID;
            std::string gameName;
            std::string gameReleaseDate;
            std::cout << "Game ID: "  << mainIter->GetObject()["id"].GetInt() << "\n";
            std::cout << "Game Name: "  << mainIter->GetObject()["name"].GetString() << "\n";
            gameID = mainIter->GetObject()["id"].GetInt();
            gameName = mainIter->GetObject()["name"].GetString();

            bool hasReleaseDate = mainIter->GetObject().HasMember("first_release_date");
            if (hasReleaseDate)
            {
                std::cout << "Game Release Date: " << timestampToDate(mainIter->GetObject()["first_release_date"].GetInt()) << "\n";
                gameReleaseDate = timestampToDate(mainIter->GetObject()["first_release_date"].GetInt());
            }

            // Iterate through the Genres
            bool hasGenre = (mainIter->GetObject().HasMember("genres"));
            std::unordered_map<int, std::string> genre;
            if (hasGenre)
            {
                if (mainIter->GetObject()["genres"].IsArray())
                {
                    const Value &gameArray = mainIter->GetObject()["genres"];
                    std::cout << "Genre: ";
                    for (Value::ConstValueIterator genreIter = gameArray.Begin(); genreIter != gameArray.End(); ++genreIter)
                    {
                        std::cout << genreIter->GetObject()["id"].GetInt() << " " << genreIter->GetObject()["name"].GetString() << ", ";
                        // add genre to map: id / genre name
                        genre.insert(std::pair<int, std::string>(genreIter->GetObject()["id"].GetInt(), genreIter->GetObject()["name"].GetString()));
                    }
                }
            }

            // Iterate through Involved Companies
            if (mainIter->GetObject().HasMember("involved_companies"))
            {
                if (mainIter->GetObject()["involved_companies"].IsArray()) {
                    const Value &involvedCoArray = mainIter->GetObject()["involved_companies"];
                    std::cout << "\nInvolved Companies\n";
                    for (Value::ConstValueIterator involvedCoIter = involvedCoArray.Begin(); involvedCoIter != involvedCoArray.End(); ++involvedCoIter) {
                        std::cout << involvedCoIter->GetObject()["id"].GetInt() << "- ";

                        // Involved Companies Iterate
                        if (involvedCoIter->GetObject()["company"].IsObject())
                        {
                            const Value& individualCo = involvedCoIter->GetObject()["company"];
                            Value::ConstMemberIterator individualCoIter = individualCo.FindMember("id");
                            std::cout << individualCoIter->value.GetInt() << " - ";
                            individualCoIter = individualCo.FindMember("name");
                            std::cout << individualCoIter->value.GetString() << "\n";
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
                    std::cout << "Similar Games: ";
                    for (SizeType i = 0; i < similarGamesArray.Size(); i++)
                    {
                        std::cout << similarGamesArray[i].GetInt() << ", ";
                    }
                }
            }
            std::cout << "\n";
        }
        return 0;
    }

}