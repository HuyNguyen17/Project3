//
// Created by gator on 4/15/2024.
//

#include "graph.h"

void graph::connectSimilarGames(const game &startGame, const vector<game>& similarGames) {
    for(const game& similarGame : similarGames)
    {
        addEdge(startGame, similarGame);
        addEdge(similarGame, startGame);
        /*
        if (List[similarGame].empty())
        {
            connectSimilarGames(similarGame,similarGame.similarGamesIDs);
        }
         */
    }

}