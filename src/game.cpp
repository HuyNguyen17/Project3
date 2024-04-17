#include "game.h"

bool game::operator==(const game &other) const {
    return other.id == this->id;
}
