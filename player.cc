#include "player.h"
#include <iostream>
using namespace std;

Player::Player() {
    // cout << "hell o" << endl;
    this->theGrid->init();
    theGrid->setPlayer(this);
}

Player::~Player(){
    for(auto &piece: playerPieces){
        theGrid->detach(piece.get());
    }
    this->playerPieces.clear();
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
    this->playerPieces.push_back(std::move(this->curPiece));
    this->curPiece.reset();
    this->curPiece = std::move(this->nextPiece);
    this->curPiece->setLevel(this->nLevel);
    this->curPiece->attach(this->theGrid.get());
    this->theGrid->attach(this->curPiece.get());
    this->curPiece->placePiece();
}

Piece * Player::getNext() {
    return this->nextPiece.get();
}

void Player::setNextPiece() { // should only ever run after setCurrPiece
    cout << "gets to next piece" << endl;
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
    for(auto &piece: playerPieces){
        theGrid->detach(piece.get());
    }
    this->playerPieces.clear();
    this->nextPiece.reset();
    this->theGrid->clear();
    this->clearScore();
    this->pLevel.reset();
    this->pLevel = std::unique_ptr<LevelZero>(new LevelZero());
//    this->pLevel->setFile
    this->nLevel = 0;
    this->theGrid->init();
    cout << "Grid has restarted" << endl;
}

void Player::setSpecificPieceType(PieceType pt) { // new Piece constructor takes in a grid and a PieceType
    cout << "HEYYYYYYYYYYYYYYYY" << endl;
    cout << this->curPiece->getInfo().base_col << endl;
    cout << this->curPiece->getInfo().base_row << endl;
    cout << "YYYYYYYYYYYYYYYYEH" << endl;
    std::unique_ptr<Piece> p {new Piece(theGrid.get(), pt)};
//    this->theGrid->detach(this->curPiece.get());            // AM I DETACHING CORRECTLY HERE
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
        std::cout << "before moving right\n";
        this->curPiece->move_r(); 
        std::cout << this->curPiece->getInfo().base_col << std::endl;
        std::cout << "after moving right \n";
    } else if (cmd == "down") {
        this->curPiece->move_d();
    }
}

void Player::drop() {
    this->curPiece->drop();
    this->setCurrPiece();
    this->setNextPiece();
}

void Player::rotate(std::string cmd) {
    if (cmd == "clockwise") {
        this->curPiece->rotate_cw();
    } else if (cmd == "counterclockwise") {
        this->curPiece->rotate_ccw();
    }
}

void Player::randomness(std::string cmd, std::string fn) {
    if (cmd == "random") {
        // do this thing
        this->pLevel->setRandom(true);
    } else if (cmd == "norandom") {
        // do this other thing
        this->pLevel->setRandom(false);
        this->pLevel->setFile(fn); //need file name
    }
}

void Player::sequence(std::string currComm, int multiplier) {

    if (currComm == "left" || currComm == "right" || currComm == "down") {
        this->move(currComm);
//                        cout << "hola i'm the right command\n" << endl;
        for (int i = 0; i < multiplier; ++i) {
            this->move(currComm);
        }
    } else if (currComm == "drop") {
        for (int i = 0; i < multiplier; ++i) {
//          cout << "inside the loop of the drop command, player1\n";
            this->drop();
        }
//      cout << "inside the loop of the drop command, player2\n";
    } else if (currComm == "clockwise" || currComm == "counterclockwise") {
        for (int i = 0; i < multiplier; ++i) {
            this->rotate(currComm);
        }

    } else if (currComm == "levelup") {
        int desiredLvl;
        desiredLvl = multiplier + this->nLevel;
        
        if (desiredLvl <= MAXLVL) {
            this->pLevel.reset();
                            
            if (desiredLvl == 1) {
                this->pLevel = make_unique<LevelOne>();
                this->setHeavy(0);
            } else if (desiredLvl == 2) {
                this->pLevel = make_unique<LevelTwo>();
                this->setHeavy(0);
            } else if (desiredLvl == 3) {
                this->pLevel = make_unique<LevelThree>();
                this->setHeavy(1);
            } else if (desiredLvl == 4) {
                this->pLevel = make_unique<LevelFour>();
                this->setHeavy(1);
            }
            this->nLevel = desiredLvl;
            } else {
                if (this->nLevel != MAXLVL) {
                    this->pLevel.reset();
                    this->pLevel = make_unique<LevelFour>();
                    this->setHeavy(1);
                }          
                this->nLevel = MAXLVL;
            }
        } else if (currComm == "leveldown") {
            int desiredLvl;
            desiredLvl = this->nLevel - multiplier;
            
            if (desiredLvl >= MINLVL) {
                this->pLevel.reset();
                            
                if (desiredLvl == 0) {
                    this->pLevel = make_unique<LevelZero>();
                    this->setHeavy(0);
                } else if (desiredLvl == 1) {
                    this->pLevel = make_unique<LevelOne>();
                    this->setHeavy(0);
                } else if (desiredLvl == 2) {
                    this->pLevel = make_unique<LevelTwo>();
                    this->setHeavy(0);
                } else if (desiredLvl == 3) {
                    this->pLevel = make_unique<LevelThree>();
                    this->setHeavy(1);
                }
                this->nLevel = desiredLvl;
                            
            } else {
                if (this->nLevel != MINLVL) {
                    this->pLevel.reset();
                    this->pLevel = make_unique<LevelZero>();
                    this->setHeavy(0);
                }
                            
                this->nLevel = MINLVL;
            }
        } else if (currComm == "random") { // no multiplier
                this->randomness(currComm, "");

        } else if (currComm == "norandom") { // no multiplier
            string fn;
            while(!(cin >> fn)) {
                cout << "\nPlease provide a file name." << endl;
            }
            this->randomness(currComm, fn);
            /* } else if (currComm == "sequence") { // reads in a file name, eh
                    string fn;
                    if (countTurns % 2 == 0) {
                        this->sequence(fn, countTurns);
                    } else {
                        player2->sequence(fn, countTurns);
                    } no idea how this works tbh*/
        // the case of restart is handled in main
        } else if (currComm == "I") { // replace current block w the I block
            this->setSpecificPieceType(PieceType::IBlock);
        
        } else if (currComm == "J") {
            this->setSpecificPieceType(PieceType::JBlock);

        } else if (currComm == "L") {
            this->setSpecificPieceType(PieceType::LBlock);

        } else if (currComm == "O") {
            this->setSpecificPieceType(PieceType::OBlock);
            
        } else if (currComm == "S") {
            this->setSpecificPieceType(PieceType::SBlock);

        } else if (currComm == "Z") {
            this->setSpecificPieceType(PieceType::ZBlock);

        } else if (currComm == "T") {
            this->setSpecificPieceType(PieceType::TBlock);
        }
}
