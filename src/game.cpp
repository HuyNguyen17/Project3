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

unsigned int game::getReleaseDate() const {
    return release_date;
}

vector<unsigned int> game::getSimilarGames() const {
    return similarGamesIDs;
}

game::game() {

}

game::game(string data) {

}

game::~game() = default;

size_t gameHash::operator()(const game &game) const {
    return game.getID();
}
