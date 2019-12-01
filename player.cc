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

std::unique_ptr<Piece> Player::getCur() {
    return std::move(this->curPiece);
}

void Player::setCur() {
    this->curPiece = this->pLevel->create();
}

std::unique_ptr<Piece> Player::getNext() {
    return std::move(this->nextPiece);
}

void Player::setNext() { // should only ever run after setCur!
    this->nextPiece = this->pLevel->create();
}

bool Player::canEffect() {
    return this->effect;
}

void Player::setEffect(bool effectIs) {
    this->effect = effectIs;
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

void Player::restart() {
    this->theGrid->clear();
    this->clearScore();
}
