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
#include "game.h"
#include "graph.h"
#include "parser.h"

int main()
{

    // use smalldata for testing
    //const std::string filename = "../data/data.json";
    const string filename = "../data/smalldata.json";
    graph gamesGraph;
    parseJSONData(filename, gamesGraph);
    gamesGraph.printConnectedGames("Need for Speed: Most Wanted");

}

