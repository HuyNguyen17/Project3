//
// Created by gator on 4/15/2024.
//

#include "graph.h"

void graph::addGame(const std::shared_ptr<game>& game) {
    nodes[game->getID()] = game;
    nameIndex[game->getName()] = game; // Index the game by name as well
}

void graph::addEdge(int gameId1, int gameId2) {
    edges[gameId1].push_back(gameId2);
    edges[gameId2].push_back(gameId1); // Assuming bidirectional relationship
}

std::shared_ptr<game> graph::findByName(const std::string& name) {
    auto it = nameIndex.find(name);
    if (it != nameIndex.end()) {
        return it->second; // Return the game if found
    } else {
        return nullptr; // Return nullptr if not found
    }
}