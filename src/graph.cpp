//
// Created by gator on 4/15/2024.
//

#include "graph.h"

void graph::addGame(const shared_ptr<game>& game) {
    nodes[game->getID()] = game;
    nameIndex[game->getName()] = game; // Index the game by name as well
    for(auto c: game->getCompanies())
    {
        company[c.name].push_back(game->getID());
    }
    release_date[to_string(game->getReleaseDate())].push_back(game->getID());
}

void graph::addEdge(int gameId1, int gameId2) {
    edges[gameId1].push_back(gameId2);
    edges[gameId2].push_back(gameId1); // Assuming bidirectional relationship
}

std::shared_ptr<game> graph::findByName(const string& name) {
    auto it = nameIndex.find(name);
    if (it != nameIndex.end()) {
        return it->second; // Return the game if found
    } else {
        return nullptr; // Return nullptr if not found
    }
}