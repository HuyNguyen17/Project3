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
#include <game.h>
using namespace std;

class graph {
private:
    unordered_map<game, vector<game>> List;
public:
    graph() = default;
    void addEdge(const game, const game);

};


#endif //PROJECT3_GRAPH_H
