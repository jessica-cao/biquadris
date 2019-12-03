#include "levelZero.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

bool LevelZero::isRandom() {
    return false;
}

void LevelZero::setRandom(bool randomness) {
    return;
}

int LevelZero::getLevel() {
    return 0;
}

unique_ptr<Piece> LevelZero::create(Grid * grid) {
    // read in from sequence1.txt and sequence2.txt
    // loop if game is not over by EOF!!

    // check if last read in was EOF, then restart
    // else, generate appropriate block according to what was last read in
    PieceType curPiece = this->playPieces.back();
    this->playPieces.pop_back();
    this->playPieces.emplace(this->playPieces.begin(), curPiece);
    unique_ptr<Piece> nPiece {new Piece(grid, curPiece)};
    // nPiece->setPiece(curPiece);
    return nPiece;

}

/*
string LevelZero::getFile() {
//    return pieceIs;
}
*/

void LevelZero::setFile(string fn) {
    cout<<fn<<endl;
    if (fn == this->fileName) {
        return;  // don't recreate the vector
    }
    string pieceInputs;
    ifstream ifs(fn);
    if (!ifs) {
        if (this->playPieces.size() == 0) {
            this->playPieces.emplace(this->playPieces.begin(), PieceType::IBlock);
            this->playPieces.emplace(this->playPieces.begin(), PieceType::JBlock);
            this->playPieces.emplace(this->playPieces.begin(), PieceType::LBlock);
            this->playPieces.emplace(this->playPieces.begin(), PieceType::TBlock);
            this->playPieces.emplace(this->playPieces.begin(), PieceType::ZBlock);
            this->playPieces.emplace(this->playPieces.begin(), PieceType::SBlock);
            this->playPieces.emplace(this->playPieces.begin(), PieceType::OBlock);
        }
        return;
    }
    this->fileName = fn;
    this->playPieces.clear();
    while (getline(ifs, pieceInputs)) {
        istringstream piecesString(pieceInputs);
        string newPiece;
        while (piecesString >> newPiece) {
            if (newPiece == "I") {
                this->playPieces.emplace(this->playPieces.begin(), PieceType::IBlock);
            } else if (newPiece == "J") {
                this->playPieces.emplace(this->playPieces.begin(), PieceType::JBlock);
            } else if (newPiece == "L") {
                this->playPieces.emplace(this->playPieces.begin(), PieceType::LBlock);
            } else if (newPiece == "T") {
                this->playPieces.emplace(this->playPieces.begin(), PieceType::TBlock);
            } else if (newPiece == "Z") {
                this->playPieces.emplace(this->playPieces.begin(), PieceType::ZBlock);
            } else if (newPiece == "S") {
                this->playPieces.emplace(this->playPieces.begin(), PieceType::SBlock);
            } else if (newPiece == "O") {
                this->playPieces.emplace(this->playPieces.begin(), PieceType::OBlock);
            }
        }
    }
}
