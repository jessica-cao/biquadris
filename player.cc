#include "player.h"

// returns this player's score
int Player::getScore() {
    return this->score;
}

// increments this player's score by one
void Player::incrementScore() {
    ++this->score;
}

// reset this player's score to 0
void Player::clearScore() {
    this->score = 0; 
}
