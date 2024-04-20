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

int main() {

    // use smalldata for testing
    //const std::string filename = "../data/data.json";
    const string filename = "../data/data.json";
    graph gamesGraph;
    parseJSONData(filename, gamesGraph);
    int option;
    cout << "Option 1: Search Similar Games" << endl;
    cout << "Option 2: Search if Two Games Are Connected" << endl;
    cout << "Enter Number: ";
    cin >> option;
    cout << endl;
    bool go = true;
    if (option == 1) {
        while (go) {
            string _name;
            cout << "Enter 'stop' to end program" << endl;
            cout << "Enter game you want to search: ";
            getline(cin, _name);
            cout << endl;

            if (_name == "stop") {
                go = false;
                continue; // Ensures the rest of the loop is skipped
            }

            cout << "BFS: " << endl;
            gamesGraph.BFSprintConnectedGames(_name, 1);
            cout << endl;
            cout << "DFS: " << endl;
            gamesGraph.DFSprintConnectedGames(_name, 1);
        }
    } else if (option == 2) {
        while (go) {
            string _name1;
            string _name2;
            cout << "Enter 'stop' to end program" << endl;
            cout << "Enter first game: ";
            getline(cin, _name1);
            cout << endl;
            if (_name1 == "stop") {
                go = false;
                continue; // Ensures the rest of the loop is skipped
            }
            cout << "Enter second game: ";
            getline(cin, _name2);
            cout << endl;
            gamesGraph.gamesConnected(_name1, _name2, 0);
        }


    }
}

