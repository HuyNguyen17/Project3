//
// Created by gator on 4/15/2024.
//

#include "graph.h"

void graph::addGame(const shared_ptr<game>& game) {
    nodes[game->getID()] = game;
    nameIndex.emplace(game->getName(), game); // Index the game by name as well
    for(auto c: game->getCompanies())
    {
        company[c.name].push_back(game->getID());
    }
    for(auto g: game->getGenres())
    {
        genre[g.name].push_back(game->getID());
    }
    release_date[(game->getReleaseDate())].push_back(game->getID());
}

void graph::addEdge(int gameId1, int gameId2) {
    // need to make sure the nodes exist in the graph
    if (gameExists(gameId1) && gameExists(gameId2)) {
        edges[gameId1].push_back(gameId2);
        edges[gameId2].push_back(gameId1); // Assuming bidirectional relationship
        numEdges++;
    }
}

void graph::addEdge(pair<int,int>& gamePair) {
    //makes it easier to directly add a pair for a graph
    addEdge(gamePair.first, gamePair.second);
}

std::vector<std::shared_ptr<game>> graph::findByName(const string& name) {
    // pair of iterators that repesent the range of games with the same name
    auto range = nameIndex.equal_range(name);

    std::vector<std::shared_ptr<game>> games;
    // check that the range exists
    if (range.first != nameIndex.end()) {
        // iterate through this range and add it to the vector
        for(auto it = range.first; it != range.second; it++)
        {
            games.push_back(it->second);
        }
    }
    // return empty vector if name not found
    return games;
}

shared_ptr<game> graph::findByID(const int ID) {
    auto it = nodes.find(ID);
    // make sure the ID is in the graph
    if (it != nodes.end()) {
        return it->second;
    }
    else {
        return nullptr;
    }
}

bool graph::gameExists(const int ID) const{
    // if game exists, then the count in the map will not be 0
    return(nodes.count(ID) != 0);
}

bool graph::gameExists(const string &name) const{
    // if game exists, then the count in the map will not be 0
    return(nameIndex.count(name) != 0);
}

int graph::getNumEdges() const {
    return numEdges;
}

int graph::getNumNodes() const {
    return nodes.size();
}

// uses the edges stored in each game to add to the adjacency list
void graph::connectNodes() {
    for(auto node: nodes)
    {
        // go through each node in the gragh and adds its similar games as edges
        for(auto similarGame : node.second->getSimilarGames())
        {
            addEdge(node.second->getID(), similarGame);
        }
    }
}

void graph::addGameToQString(QString qString)
{
    qStringList << qString;
}