//
// Created by gator on 4/15/2024.
//

#include "graph.h"
#include<queue>

//Build game Object and add all relevant data to the maps.
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
        // go through each node in the graph and adds its similar games as edges
        for(auto similarGame : node.second->getSimilarGames())
        {
            addEdge(node.second->getID(), similarGame);
        }
    }
}

int graph::getIDfromSearching(std::string &_name)
{
    names = findByName(_name);
    int _id; //id to find
    if(names.empty())
    {
        cout << "Game was not found. Try again" << endl;
    }
    if(names.size() < 2)
    {
        for (const auto& gamePtr : names)
        {
            _id =  gamePtr->getID();
            names.clear();
            return _id;
        }
    }
    else
    {
        //Implement Later, we will have the user select the game they want to search in the GUI
        cout << "there is more than one game" << endl;
        for (const auto& gamePtr: names)
        {
            cout << "Game: " << gamePtr->getName() << ", Released " << gamePtr->getReleaseDate() << '\n';
        }
        return -1; //TODO fix this later, add a way for the user to specify which game when there are two names that are equal
    }
    names.clear();
    return -1; //return -1 when there was no game found.
}

void graph::printConnectedGames(std::string _name) {
    int _gameID = getIDfromSearching(_name);
    if (_gameID != -1) {
        std::queue<int> queue;
        std::unordered_set<int> visited;

        queue.push(_gameID);
        visited.insert(_gameID);

        while (!queue.empty()) {
            int currentID = queue.front();
            queue.pop();

            // Access the game using the ID and print its name
            auto gameIterator = nodes.find(currentID);
            if (gameIterator != nodes.end()) {
                std::cout << gameIterator->second->getName() << std::endl;
            }

            // Traverse all adjacent games
            auto neighbours = edges[currentID];
            for (int neighbourID : neighbours) {
                if (visited.find(neighbourID) == visited.end()) {
                    queue.push(neighbourID);
                    visited.insert(neighbourID);
                }
            }
        }
    } else {
        std::cout << "Game not found." << std::endl;
    }
};
