#include <unordered_map>
#include <vector>
#include <iomanip>
#include "rapidjson/filereadstream.h"
#include <cstdio>
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

bool Parser::parseJSONFromFile(std::string filename, rapidjson::Document& d)
{
    FILE* fp = fopen(filename.c_str(), "rb");
    char readBuffer[65536];

    FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    d.ParseStream(is);

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
    strftime(buffer, 80, "%Y", t); // Format: MM-DD-YYYY

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

    bool hasReleaseDate = mainIter->GetObject().HasMember("first_release_date");
    if (hasReleaseDate)
    {
        gameReleaseDate = timestampToDate(mainIter->GetObject()["first_release_date"].GetInt());
    }

    // Iterate through the Genres
    bool hasGenre = (mainIter->GetObject().HasMember("genres"));
    if (hasGenre)
    {
        if (mainIter->GetObject()["genres"].IsArray())
        {
            const rapidjson::Value &gameArray = mainIter->GetObject()["genres"];

            for (rapidjson::Value::ConstValueIterator genreIter = gameArray.Begin(); genreIter != gameArray.End(); ++genreIter)
            {
                // add genre to vector
                genres.emplace_back(genreIter->GetObject()["id"].GetInt(), genreIter->GetObject()["name"].GetString());
            }
        }
    }
    else
    {
        //if no genres, then create a dummy None genre
        genres.emplace_back(-1, "None"); //give the NONE genre an id of -1
    }

    // Iterate through Involved Companies
    bool hasCompany = mainIter->GetObject().HasMember("involved_companies");
    if (hasCompany)
    {
        if (mainIter->GetObject()["involved_companies"].IsArray()) {
            const rapidjson::Value &involvedCoArray = mainIter->GetObject()["involved_companies"];

            for (rapidjson::Value::ConstValueIterator involvedCoIter = involvedCoArray.Begin(); involvedCoIter != involvedCoArray.End(); ++involvedCoIter) {

                // Involved Companies Iterate
                if (involvedCoIter->GetObject()["company"].IsObject())
                {
                    int companyId;
                    string companyName;

                    const rapidjson::Value& individualCo = involvedCoIter->GetObject()["company"];
                    rapidjson::Value::ConstMemberIterator individualCoIter = individualCo.FindMember("id");

                    companyId = individualCoIter-> value.GetInt();

                    individualCoIter = individualCo.FindMember("name");
                    companyName = individualCoIter->value.GetString();

                    companies.emplace_back(companyId, companyName);
                }
            }
        }
    }
    else
    {
        //if no companies, then create a dummy None company
        companies.emplace_back(-1, "None"); //give the NONE company an id of -1
    }

    // Iterate through similar games
    if (mainIter->GetObject().HasMember("similar_games"))
    {
        if (mainIter->GetObject()["similar_games"].IsArray())
        {
            const rapidjson::Value &similarGamesArray = mainIter->GetObject()["similar_games"];
            for (rapidjson::SizeType i = 0; i < similarGamesArray.Size(); i++)
            {
                similarGames.push_back(similarGamesArray[i].GetInt());
            }
        }
    }

    // insert into graph
    gamesGraph.addGame(make_shared<game>(gameID, gameName, gameReleaseDate,
                                                genres, companies, similarGames));
    // Add games name to a QStringList for autocompletion
    QString qStringGameName = QString::fromStdString(gameName);
    gamesGraph.addGameToQString(qStringGameName);
}

graph Parser::parseToGraph(std::string filename) {
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

        // Add to autocomplete - possible add to queue set
        gamesGraph.addAllGenresToQString();
        gamesGraph.addAllCompaniesToQString();
        return gamesGraph;
    }
}