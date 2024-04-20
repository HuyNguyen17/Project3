#include <unordered_map>
#include <vector>
#include <iomanip>
//#include "rapidjson/filereadstream.h"
//#include "rapidjson/stringbuffer.h"
//#include "rapidjson/writer.h"
//#include <cstdio>
//#include <chrono>
//#include "rapidjson/document.h"
#include <fstream>
#include <iostream>
#include "graph.h"
#include "game.h"
#include "parser.h"

using namespace rapidjson;

Parser::Parser()
{

}

Parser::~Parser()
{

}

bool Parser::parseJSONFromFile(const string& filename, rapidjson::Document& d)
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

string Parser::timestampToDate(long long timestamp) {
    // Convert timestamp to time_point
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(timestamp);

    // Convert time_point to time_t
    time_t tt = std::chrono::system_clock::to_time_t(tp);

    // Convert time_t to struct tm
    tm* t = localtime(&tt);

    // Format struct tm to a string
    char buffer[80]; // Buffer for the formatted string
    strftime(buffer, 80, "%m-%d-%Y", t); // Format: MM-DD-YYYY

    return string(buffer);
}

void Parser::parseGame(const rapidjson::Value::ConstValueIterator mainIter, graph& gamesGraph) {
    // main game info
    int gameID;
    string gameName;
    string gameReleaseDate;
    vector<int> similarGames;
    vector<Genre> genres;
    vector<Company> companies;

    gameID = mainIter->GetObject()["id"].GetInt();
    gameName = mainIter->GetObject()["name"].GetString();
    cout << "Game ID: "  << gameID << "\n";
    cout << "Game Name: "  << gameName << "\n";

    bool hasReleaseDate = mainIter->GetObject().HasMember("first_release_date");
    if (hasReleaseDate)
    {
        gameReleaseDate = timestampToDate(mainIter->GetObject()["first_release_date"].GetInt());
//        cout << "Game Release Date: " << gameReleaseDate << "\n";
    }

    // Iterate through the Genres
    bool hasGenre = (mainIter->GetObject().HasMember("genres"));
    if (hasGenre)
    {
        if (mainIter->GetObject()["genres"].IsArray())
        {
            const rapidjson::Value &gameArray = mainIter->GetObject()["genres"];
//            cout << "Genre: ";
            for (rapidjson::Value::ConstValueIterator genreIter = gameArray.Begin(); genreIter != gameArray.End(); ++genreIter)
            {
//                cout << genreIter->GetObject()["id"].GetInt() << " " << genreIter->GetObject()["name"].GetString() << ", ";
                // add genre to vector
                genres.emplace_back(genreIter->GetObject()["id"].GetInt(), genreIter->GetObject()["name"].GetString());
            }
        }
    }

    // Iterate through Involved Companies
    if (mainIter->GetObject().HasMember("involved_companies"))
    {
        if (mainIter->GetObject()["involved_companies"].IsArray()) {
            const rapidjson::Value &involvedCoArray = mainIter->GetObject()["involved_companies"];
//            cout << "\nInvolved Companies\n";
            for (rapidjson::Value::ConstValueIterator involvedCoIter = involvedCoArray.Begin(); involvedCoIter != involvedCoArray.End(); ++involvedCoIter) {
//                cout << involvedCoIter->GetObject()["id"].GetInt() << "- ";

                // Involved Companies Iterate
                if (involvedCoIter->GetObject()["company"].IsObject())
                {
                    int companyId;
                    string companyName;

                    const rapidjson::Value& individualCo = involvedCoIter->GetObject()["company"];
                    rapidjson::Value::ConstMemberIterator individualCoIter = individualCo.FindMember("id");

                    companyId = individualCoIter-> value.GetInt();
//                    cout << companyId << " - ";
                    individualCoIter = individualCo.FindMember("name");
                    companyName = individualCoIter->value.GetString();
//                    cout << companyName << "\n";
                    companies.emplace_back(companyId, companyName);
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
//            cout << "Similar Games: ";
            for (rapidjson::SizeType i = 0; i < similarGamesArray.Size(); i++)
            {
//                cout << similarGamesArray[i].GetInt() << ", ";
                similarGames.push_back(similarGamesArray[i].GetInt());
            }
        }
    }
//    cout << "\n";
    // insert into graph
    gamesGraph.addGame(make_shared<game>(gameID, gameName, gameReleaseDate,
                                                genres, companies, similarGames));
    // Add games name to a QStringList for autocompletion
    QString qStringGameName = QString::fromStdString(gameName);
    gamesGraph.addGameToQString(qStringGameName);
}

void Parser::parseJSONData(const std::string& filename, graph &gamesGraph) {
    rapidjson::Document d;
    bool parsed = parseJSONFromFile(filename, d);

    if (!parsed)
    {
        return;
    }
    else
    {
        for (rapidjson::Value::ConstValueIterator mainIter = d.Begin(); mainIter != d.End(); ++mainIter)
        {
            // parse game and add it to the graph
            parseGame(mainIter, gamesGraph);
        }
        gamesGraph.connectNodes();

        // testing to see if findbyname works
        auto testVector= gamesGraph.findByName("Doesn't Exist");
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

graph Parser::parseToGraph(const std::string& filename) {
    rapidjson::Document d;
    bool parsed = parseJSONFromFile(filename, d);

    if (!parsed)
    {
        graph fail;
        return fail;
    }
    else
    {
        graph gamesGraph;
        for (rapidjson::Value::ConstValueIterator mainIter = d.Begin(); mainIter != d.End(); ++mainIter)
        {
            // parse game and add it to the graph
            parseGame(mainIter, gamesGraph);
        }
        gamesGraph.connectNodes();

        return gamesGraph;

//        // testing to see if findbyname works
//        auto testVector= gamesGraph.findByName("Doesn't Exist");
//        if(testVector.empty())
//        {
//            cout << '\n' << "Doesn't break when finding invalid game!" << '\n';
//        }
//        testVector = gamesGraph.findByName("Minecraft");
//        if(!testVector.empty())
//        {
//            for (const auto& gamePtr : testVector)
//            {
//                cout << "Game: " << gamePtr->getName() << ", Released " << gamePtr->getReleaseDate() << '\n';
//            }
//        }
//
//        cout << gamesGraph.getNumNodes() << " nodes in graph!" << '\n';
//        cout << gamesGraph.getNumEdges() <<" edges in graph!" << '\n';
    }
}