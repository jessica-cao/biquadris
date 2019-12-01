#include "player.h"

int Player::getScore() {
    return this->score;
}

void Player::incrementScore() {
    ++this->score;
}
