#include "game.h"

bool game::operator==(const game &other) const {
    return other.id == this->id;
}

// Getters
vector<Company> game::getCompanies() const {
    return companies;
}

set<Genre> game::getGenres() const {
    return genres;
}

unsigned int game::getID() const {
    return id;
}

string game::getName() const {
    return name;
}

string game::getReleaseDate() const {
    return releaseDate;
}

vector<int> game::getSimilarGames() const {
    return similarGamesIDs;
}

game::game() {

}

game::game(int ID, string gameName, string gameReleaseDate, vector<int> &similarGames) :
        id(ID), name(gameName), releaseDate(gameReleaseDate), similarGamesIDs(similarGames) {
}

game::~game() = default;

size_t gameHash::operator()(const game &game) const {
    return game.getID();
}
