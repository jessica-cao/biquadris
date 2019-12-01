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

//
std::unique_ptr<Piece> Player::createPiece() {
    return std::move(this->pLevel->create());
}

void Player::setCurrPiece(std::unique_ptr<Piece> nPiece) { // you want to be able to set a specific piece
    this->curPiece.reset();
    this->curPiece = std::move(nPiece);
    this->curPiece->setLevel(this->nLevel);
    this->curPiece->attach(this->theGrid.get());
    this->theGrid->attach(this->curPiece.get());
}

std::unique_ptr<Piece> Player::getNext() {

    return std::move(this->nextPiece);
}

void Player::setNextPiece() { // should only ever run after setCurrPiece
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

void Player::setSpecificPieceType(PieceType pt) {
    std::unique_ptr<Piece> p {new Piece(theGrid.get())};
    p->setPiece(pt);
    setCurrPiece(std::move(p));

}

void Player::move(std::string cmd) {
    if (cmd == "left") {
        this->curPiece->move_l();
    } else if (cmd == "right") {
        this->curPiece->move_r(); 
    } else if (cmd == "down") {
        this->curPiece->move_d();
    } else if (cmd == "drop") {
        this->curPiece->drop();
    }
}

void Player::rotate(std::string cmd) {
    if (cmd == "clockwise") {
        this->curPiece->rotate_cw();
    } else if (cmd == "counterclockwise") {
        this->curPiece->rotate_ccw();
    }
}

void Player::randomness(std::string cmd) {
    if (cmd == "random") {
        // do this thing
    } else if (cmd == "norandom") {
        // do this other thing
    }
}

void Player::sequence() {
    // do something
}