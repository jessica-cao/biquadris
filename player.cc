#include "player.h"
#include <iostream>
using namespace std;

Player::Player() {
    // cout << "hello" << endl;
    this->theGrid->init();
}

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

Piece * Player::getCur() {
    return this->curPiece.get();
}

//
std::unique_ptr<Piece> Player::createPiece() {
    return std::move(this->pLevel->create(this->theGrid.get()));
}


void Player::setCurrPiece() { // you want to be able to set a specific piece
    this->curPiece.reset();
    this->curPiece = std::move(this->nextPiece);
    this->curPiece->setLevel(this->nLevel);
    this->curPiece->attach(this->theGrid.get());
    std::cout << "HELLOOOOOOOOOOOOOOOOOOOOOO" << std::endl;
    std::cout << this->theGrid->getInfo().base_row << " hey" << std::endl;
    this->theGrid->attach(this->curPiece.get());
    this->curPiece->placePiece();
}

Piece * Player::getNext() {
    return this->nextPiece.get();
}

void Player::setNextPiece() { // should only ever run after setCurrPiece
    this->nextPiece = this->pLevel->create(this->theGrid.get());
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
    this->pLevel.reset();
    this->pLevel = std::unique_ptr<LevelZero>(new LevelZero());
//    this->pLevel->setFile
    this->nLevel = 0;
}

void Player::setSpecificPieceType(PieceType pt) { // new Piece constructor takes in a grid and a PieceType
    std::unique_ptr<Piece> p {new Piece(theGrid.get(), pt)};
    this->curPiece.reset();
    this->curPiece = std::move(p);
    this->curPiece->setLevel(this->nLevel);
    this->curPiece->attach(this->theGrid.get());
    this->theGrid->attach(this->curPiece.get());
    this->curPiece->placePiece();
}

void Player::move(std::string cmd) {
    if (cmd == "left") {
        this->curPiece->move_l();
    } else if (cmd == "right") {
        cout << "Right command" << endl;
        cout << this->curPiece->getInfo().base_row << endl;
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