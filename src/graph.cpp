//
// Created by gator on 4/15/2024.
//

#include "graph.h"
#include<queue>
#include<stack>

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

vector<shared_ptr<game>> graph::findByName(const string& name) {
    // pair of iterators that repesent the range of games with the same name
    auto range = nameIndex.equal_range(name);

    vector<shared_ptr<game>> games;
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

int graph::getIDfromSearching(string &_name) {
    auto names = findByName(_name);
    int _id = -1; // Initialize ID to -1 to indicate not found

    if (names.empty()) {
        cout << "Game was not found." << endl;
        return _id;
    }

    if (names.size() == 1) {
        _id = names.front()->getID();
    } else {
        cout << "Multiple games found. Please select one:" << endl;
        for (const auto& gamePtr : names) {
            cout << "Game: " << gamePtr->getName() << ", Released " << gamePtr->getReleaseDate() << ", ID: " << gamePtr->getID() << '\n';
        }
        cout << "Enter the ID of the game you want to select: ";
        cin >> _id;
        cin.ignore(); // Clear the newline character from the buffer
    }
    return _id;
}

void graph::BFSprintConnectedGames(string _name, int maxDepth) {
    int _gameID = getIDfromSearching(_name);
    if (_gameID != -1) {
        queue<pair<int, int>> queue; // Store game ID and depth
        unordered_set<int> visited;

        queue.push({_gameID, 0});
        visited.insert(_gameID);

        while (!queue.empty()) {
            auto current = queue.front();
            int currentID = current.first;
            int currentDepth = current.second;
            queue.pop();

            // Access the game using the ID and print its name
            auto gameIterator = nodes.find(currentID);
            if (gameIterator != nodes.end()) {
                cout << gameIterator->second->getName() << endl;
                // Add the game to a QStringList
                qStringListBFSGameNames << QString::fromStdString(gameIterator->second->getName());
            }

            // Stop BFS if depth exceeds maxDepth
            if (currentDepth >= maxDepth) continue;

            // Traverse all adjacent games
            auto neighbours = edges[currentID];
            for (int neighbourID : neighbours) {
                if (visited.find(neighbourID) == visited.end()) {
                    queue.push({neighbourID, currentDepth + 1});
                    visited.insert(neighbourID);
                }
            }
        }
    }
}

void graph::DFSprintConnectedGames(string _name, int maxDepth) {
    int _gameID = getIDfromSearching(_name);
    if (_gameID != -1) {
        stack<pair<int, int>> stack;  // Use a stack to manage the DFS
        unordered_set<int> visited;

        stack.push({_gameID, 0});
        visited.insert(_gameID);

        while (!stack.empty()) {
            auto current = stack.top();
            stack.pop();
            int currentID = current.first;
            int currentDepth = current.second;

            // Access the game using the ID and print its name
            auto gameIterator = nodes.find(currentID);
            if (gameIterator != nodes.end()) {
                cout << gameIterator->second->getName() << endl;
            }

            // Stop DFS if depth exceeds maxDepth
            if (currentDepth >= maxDepth) continue;

            // Traverse all adjacent games
            auto neighbours = edges[currentID];
            for (int neighbourID : neighbours) {
                if (visited.find(neighbourID) == visited.end()) {
                    stack.push({neighbourID, currentDepth + 1});
                    visited.insert(neighbourID);
                }
            }
        }
    }
}

bool graph::gamesConnected(string &_name1, string &_name2, int searchPath) {
    int startID = getIDfromSearching(_name1);
    int targetID = getIDfromSearching(_name2);

    if (startID == -1 || targetID == -1) {
        cout << "One or both games not found." << endl;
        return false;
    }

    unordered_set<int> visited;
    if (searchPath == 0) {  // BFS
        queue<pair<int, int>> queue;
        queue.push({startID, 0});
        visited.insert(startID);

        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop();
            int currentID = current.first;
            int currentDepth = current.second;

            if (currentID == targetID) {
                cout << "[" << _name2 << "] is " << currentDepth << " games away from [" << _name1 << "]." << endl;
                return true;
            }

            for (int neighbourID : edges[currentID]) {
                if (visited.find(neighbourID) == visited.end()) {
                    queue.push({neighbourID, currentDepth + 1});
                    visited.insert(neighbourID);
                }
            }
        }
    } else if (searchPath == 1) {  // DFS
        stack<pair<int, int>> stack;
        stack.push({startID, 0});
        visited.insert(startID);

        while (!stack.empty()) {
            auto current = stack.top();
            stack.pop();
            int currentID = current.first;
            int currentDepth = current.second;

            if (currentID == targetID) {
                cout << "[" << _name2 << "] is " << currentDepth << " games away from [" << _name1 << "]." << endl;
                return true;
            }

            for (int neighbourID : edges[currentID]) {
                if (visited.find(neighbourID) == visited.end()) {
                    stack.push({neighbourID, currentDepth + 1});
                    visited.insert(neighbourID);
                }
            }
        }
    }

    cout << _name2 << " is not reachable from " << _name1 << endl;
    return false;
}

void graph::addGameToQString(QString qString)
{
    qStringListNames << qString;
}

void graph::searchByGenre(string _genre) {
    auto it = genre.find(_genre);
    if (it == genre.end())
    {
        cout << "No games found for the genre: " << _genre << endl;
        return;
    }
    const auto& gameIDs = it->second;
    for (auto id : gameIDs)
    {
        auto gameIt =nodes.find(id);
        if (gameIt != nodes.end())
        {
            shared_ptr<game> game = gameIt->second;
            cout << "Game ID: " << game->getID() << ", Name: " << game->getName()
                 << ", Released: " << game->getReleaseDate() << endl;
        }
    }
}

void graph::printAllGenre() {
    if (genre.empty()) {
        cout << "No genres available." << endl;
        return;
    }

    cout << "Available Genres:" << endl;
    for (const auto& pair : genre) {
        cout << pair.first << endl;
    }
}

void graph::searchByCompany(std::string _company) {
    auto it = company.find(_company);
    if (it == company.end())
    {
        cout << "No games found for " << _company << endl;
        return;
    }
    const auto& gameIDs = it->second;
    for (auto id : gameIDs)
    {
        auto gameIt =nodes.find(id);
        if (gameIt != nodes.end())
        {
            shared_ptr<game> game = gameIt->second;
            cout << "Game ID: " << game->getID() << ", Name: " << game->getName()
                 << ", Released: " << game->getReleaseDate() << endl;
        }
    }
    cout << endl;
}

void graph::printAllCompany() {
    if (company.empty()) {
        cout << "No company available." << endl;
        return;
    }

    cout << "Available Companies:" << endl;
    for (const auto& pair : company) {
        cout << pair.first << endl;
    }
}

void graph::searchByReleaseDate(string _releaseDate) {
    auto it = release_date.find(_releaseDate);
    if (it == release_date.end())
    {
        cout << "No games found for release date " << _releaseDate << endl;
        return;
    }
    const auto& gameIDs = it->second;
    for (auto id : gameIDs)
    {
        auto gameIt = nodes.find(id);
        if (gameIt != nodes.end())
        {
            shared_ptr<game> game = gameIt->second;
            cout << "Game ID: " << game->getID() << ", Name: " << game->getName()
                 << ", Released: " << game->getReleaseDate() << endl;
        }
    }
    cout << endl;
}

QVector<shared_ptr<game>> graph::getConnectedGamesBFS(string _name, int maxDepth) {
    QVector<shared_ptr<game>> connectedGames;

    int _gameID = getIDfromSearching(_name);

    if (_gameID == -1) {
        return connectedGames; // Return empty vector if no game is found
    }

    queue<pair<int, int>> queue; // Store game ID and depth
    unordered_set<int> visited;

    queue.push({_gameID, 0});
    visited.insert(_gameID);

    while (!queue.empty()) {
        auto current = queue.front();
        int currentID = current.first;
        int currentDepth = current.second;
        queue.pop();

        // Access the game using the ID and collect it
        auto gameIterator = nodes.find(currentID);
        if (gameIterator != nodes.end()) {
            connectedGames.push_back(gameIterator->second);
        }

        // Stop BFS if depth exceeds maxDepth
        if (currentDepth >= maxDepth) continue;

        // Traverse all adjacent games
        auto neighbours = edges[currentID];
        for (int neighbourID : neighbours) {
            if (visited.find(neighbourID) == visited.end()) {
                queue.push({neighbourID, currentDepth + 1});
                visited.insert(neighbourID);
            }
        }
    }
    return connectedGames;
}

QVector<shared_ptr<game>> graph::getConnectedGamesDFS(string _name, int maxDepth) {
    QVector<shared_ptr<game>> connectedGames;
    int _gameID = getIDfromSearching(_name);

    if (_gameID == -1) {
        return connectedGames; // Return empty vector if no game is found
    }

    stack<pair<int, int>> stack; // Use a stack to manage the DFS
    unordered_set<int> visited;

    stack.push({_gameID, 0});
    visited.insert(_gameID);

    while (!stack.empty()) {
        auto current = stack.top();
        stack.pop();
        int currentID = current.first;
        int currentDepth = current.second;

        // Access the game using the ID and collect it
        auto gameIterator = nodes.find(currentID);
        if (gameIterator != nodes.end()) {
            connectedGames.push_back(gameIterator->second);
        }

        // Stop DFS if depth exceeds maxDepth
        if (currentDepth >= maxDepth) continue;

        // Traverse all adjacent games in reverse to maintain typical DFS order
        auto neighbours = edges[currentID];
        for (auto it = neighbours.rbegin(); it != neighbours.rend(); ++it) {
            int neighbourID = *it;
            if (visited.find(neighbourID) == visited.end()) {
                stack.push({neighbourID, currentDepth + 1});
                visited.insert(neighbourID);
            }
        }
    }

    return connectedGames;
}

QVector<shared_ptr<game>> graph::getGamesByGenre(string _genre) {
    QVector<shared_ptr<game>> gamesByGenre;
    auto it = genre.find(_genre);
    if (it == genre.end()) {
        // Optionally handle the case where no games are found for the genre
        cout << "No games found for the genre: " << _genre << endl;
        return gamesByGenre; // Return an empty vector
    }

    const auto& gameIDs = it->second;
    for (auto id : gameIDs) {
        auto gameIt = nodes.find(id);
        if (gameIt != nodes.end()) {
            gamesByGenre.push_back(gameIt->second);
        }
    }
    return gamesByGenre;
}

QVector<shared_ptr<game>> graph::getGamesByCompany(string _company) {
    QVector<shared_ptr<game>> gamesByCompany;
    auto it = company.find(_company);
    if (it == company.end()) {
        // Optionally handle the case where no games are found for the company
        cout << "No games found for " << _company << endl;
        return gamesByCompany; // Return an empty vector
    }

    const auto& gameIDs = it->second;
    for (auto id : gameIDs) {
        auto gameIt = nodes.find(id);
        if (gameIt != nodes.end()) {
            gamesByCompany.push_back(gameIt->second);
        }
    }
    return gamesByCompany;
}

QVector<shared_ptr<game>> graph::getGamesByReleaseDate(string _releaseDate) {
    QVector<shared_ptr<game>> gamesByReleaseDate;
    auto it = release_date.find(_releaseDate);
    if (it == release_date.end()) {
        // Optionally handle the case where no games are found for the release date
        cout << "No games found for release date " << _releaseDate << endl;
        return gamesByReleaseDate; // Return an empty vector
    }

    const auto& gameIDs = it->second;
    for (auto id : gameIDs) {
        auto gameIt = nodes.find(id);
        if (gameIt != nodes.end()) {
            gamesByReleaseDate.push_back(gameIt->second);
        }
    }
    return gamesByReleaseDate;
}