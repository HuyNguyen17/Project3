#include "game.h"

bool game::operator==(const game &other) const {
    return other.id == this->id;
}

size_t gameHash::operator()(const game &game) const {
    return game.getID();
}
