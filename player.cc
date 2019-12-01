#include "player.h"

// returns this player's score
int Player::getScore() {
    return this->score;
}

// increments this player's score by one
void Player::incrementScoreBy(int sc) {
    this->score += sc;
}

// reset this player's score to 0
void Player::clearScore() {
    this->score = 0; 
}

bool isBlind() {
    return this->blind;
}

void setBlind(bool blindness) {
    this->setBlind = blindness;
}
