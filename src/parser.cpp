#include <unordered_map>
#include <vector>
#include <iomanip>
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <cstdio>
#include <chrono>
#include "rapidjson/document.h"
#include <fstream>
#include <iostream>
#include "graph.h"
#include "game.h"
#include "parser.h"

using namespace rapidjson;

bool parseJSONFromFile(const string& filename, rapidjson::Document& d)
{
    // Open the file
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return false;
    }

    // Read the entire file into a string
    string jsonStr((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
    ifs.close();

    d.Parse(jsonStr.c_str());

    // Check if parsing succeeded
    if (d.HasParseError()) {
        cerr << "Error parsing JSON: " << rapidjson::GetParseErrorFunc(d.GetParseError()) << endl;
        return false;
    }
    return true;
}

string timestampToDate(long long timestamp) {
    // Convert timestamp to time_point
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(timestamp);

    // Convert time_point to time_t
    time_t tt = std::chrono::system_clock::to_time_t(tp);

    // Convert time_t to struct tm
    tm* t = localtime(&tt);

    // Format struct tm to a string
    char buffer[80]; // Buffer for the formatted string
    strftime(buffer, 80, "%m-%d-%Y", t); // Format: YYYY-MM-DD HH:MM:SS

    return string(buffer);
}

shared_ptr<game> parseGame(const rapidjson::Value::ConstValueIterator mainIter) {
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
            const rapidjson::Value &gameArray = mainIter->GetObject()["genres"];
            cout << "Genre: ";
            for (rapidjson::Value::ConstValueIterator genreIter = gameArray.Begin(); genreIter != gameArray.End(); ++genreIter)
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
            const rapidjson::Value &involvedCoArray = mainIter->GetObject()["involved_companies"];
            cout << "\nInvolved Companies\n";
            for (rapidjson::Value::ConstValueIterator involvedCoIter = involvedCoArray.Begin(); involvedCoIter != involvedCoArray.End(); ++involvedCoIter) {
                cout << involvedCoIter->GetObject()["id"].GetInt() << "- ";

                // Involved Companies Iterate
                if (involvedCoIter->GetObject()["company"].IsObject())
                {
                    const rapidjson::Value& individualCo = involvedCoIter->GetObject()["company"];
                    rapidjson::Value::ConstMemberIterator individualCoIter = individualCo.FindMember("id");
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
            const rapidjson::Value &similarGamesArray = mainIter->GetObject()["similar_games"];
            cout << "Similar Games: ";
            for (rapidjson::SizeType i = 0; i < similarGamesArray.Size(); i++)
            {
                cout << similarGamesArray[i].GetInt() << ", ";
                similarGames.push_back(similarGamesArray[i].GetInt());
            }
        }
    }
    cout << "\n";
    return make_shared<game>(gameID, gameName, gameReleaseDate, similarGames); // can add more but these are good for now
}

void parseJSONData(const std::string& filename) {
    rapidjson::Document d;
    bool parsed = parseJSONFromFile(filename, d);

    vector<shared_ptr<game>> gamePointers;

    if (!parsed)
    {
        return;
    }
    else
    {
        for (rapidjson::Value::ConstValueIterator mainIter = d.Begin(); mainIter != d.End(); ++mainIter)
        {
            gamePointers.push_back(parseGame(mainIter));
        }
        // Really want to do funky and unique stuff with this graph
        graph gamesGraph;
        vector<pair<int, int>> edges; // need to add the similar games after we're all done
        // but for now, just add all the games into it
        for(auto ptr : gamePointers)
        {
            gamesGraph.addGame(ptr);
            for(auto similarGame : ptr->getSimilarGames())
            {
                edges.push_back(pair<int,int>(ptr->getID(), similarGame));
            }
        }
        // add similar games as edges to graph
        for(auto edge : edges)
        {
            gamesGraph.addEdge(edge);
        }

        // testing to see if findbyname works
        auto testVector = gamesGraph.findByName("Doesn't Exist");
        if(testVector.empty())
        {
            cout << '\n' << "Doesn't break when finding invalid game!" << '\n';
        }
        testVector = gamesGraph.findByName("Minecraft");
        if(!testVector.empty())
        {
            for (const auto& gamePtr : testVector)
            {
                cout << "Game: " << gamePtr->getName() << ", Released " << gamePtr->getReleaseDate() << '\n';
            }
        }

        cout << gamesGraph.getNumNodes() << " nodes in graph!" << '\n';
        cout << gamesGraph.getNumEdges() <<" edges in graph!" << '\n';
    }
}