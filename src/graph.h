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
#include "game.h"
using namespace std;

class graph {
private:
    unordered_map<game, vector<game>> List; // Stores adjacency list of games

public:
    graph() = default; // Default constructor

    // Adds an edge between two games, creating a bidirectional link
    void addEdge(const game, const game);

    // Recursively connects all games that are similar to each other
    void connectSimilarGames(const game& startGame, const vector<game>& similarGames);

    // Connects all games within the same genre
    void connectSimilarGenres(const string genre);

    // Connects all games released in the same year
    void connectSameReleaseDate(int year);

    // Connects all games developed by the same company
    void connectCompanyGames(string company);
};

#endif //PROJECT3_GRAPH_H

