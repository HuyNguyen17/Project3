#include "game.h"

#include <utility>

bool game::operator==(const game &other) const {
    return other.id == this->id;
}

// Getters
vector<Company> game::getCompanies() const {
    return companies;
}

vector<Genre> game::getGenres() const {
    return genres;
}

int game::getID() const {
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

game::game(int ID, string gameName, string gameReleaseDate,
           vector<Genre>& genres, vector<Company>& companies, vector<int>& similarGames) :
        id(ID), name(std::move(gameName)), releaseDate(std::move(gameReleaseDate)),
        genres(genres), companies(companies), similarGamesIDs(similarGames) {
}

game::~game() = default;

size_t gameHash::operator()(const game &game) const {
    return game.getID();
}
