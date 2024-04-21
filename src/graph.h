//
// Created by gator on 4/15/2024.
//

#ifndef PROJECT3_GRAPH_H
#define PROJECT3_GRAPH_H

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include<memory>
#include "game.h"
#include "unordered_set"
#include <QStringList>
using namespace std;

class graph {
private:
    unordered_map<game, vector<game>, gameHash> List; // Stores adjacency list of games, Leaving here for now.
    
    unordered_map<int, shared_ptr<game>> nodes; // Maps game ID to game object
    unordered_multimap<string, shared_ptr<game>> nameIndex; // Maps game names to game objects for quick lookup
    unordered_map<int, vector<int>> edges; // Adjacency list for similar games

    //The idea is to parse through the data and store all the information in this graph to enable visualization later based on search criteria.
    unordered_map<string, vector<int>> genre; //string will be the genre title and int will be gameID
    unordered_map<string, vector<int>> company; //string will be the company title and int will be gameID
    unordered_map<string, vector<int>> release_date; //string will be the release date and int will be gameID
    QStringList qStringListNames;
    QStringList qStringListBFSGameNames;
    QStringList dfsStringListGameNames;
    vector<shared_ptr<game>> names;

    int numEdges = 0;
public:
    graph() = default; // Default constructor
    void addGame(const shared_ptr<game>& game);
    void addEdge(int gameId1, int gameId2);
    void addEdge(pair<int,int>& gamePair);
    void connectNodes();

    // add game name to QStringList
    void addGameToQString(QString qString);
    // return game StringList
    QStringList getQStringGameNames() {return qStringListNames; }
    QStringList getQStringBFSGameNames() {return qStringListBFSGameNames; }

    std::vector<std::shared_ptr<game>> findByName(const string& name); // Method to find a game by name
    shared_ptr<game> findByID(const int ID); // find a gameby its id

    // checks if a game exists in the graph
    bool gameExists(const int ID) const;
    bool gameExists(const string& name) const;

    int getNumEdges() const;
    int getNumNodes() const;
    int getIDfromSearching(string &_name);

    // Todo: Cyrus to add return vectors
    // maxDepth default is 1; change to show others not so related
    void BFSprintConnectedGames(string _name, int maxDepth);
    void DFSprintConnectedGames(string _name, int maxDepth);
    // searchPath =  0 is BFS and 1 is DFS
    // name1 is the main search, name2 is the connected search
    bool gamesConnected(string &_name1, string &_name2, int searchPath);
};

#endif //PROJECT3_GRAPH_H
