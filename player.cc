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

bool Player::isBlind() {
    return this->blind;
}

void Player::setBlind(bool blindness) {
    this->blind = blindness;
}

int Player::getHeavy() {
    return this->heavy;
}

void Player::setHeavy(int heaviness) {
    this->heavy = heaviness;
}