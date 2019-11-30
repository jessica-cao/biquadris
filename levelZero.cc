#include "levelZero.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

unique_ptr<Piece> LevelZero::create() {
    // read in from sequence1.txt and sequence2.txt
    // loop if game is not over by EOF!!

    // check if last read in was EOF, then restart
    // else, generate appropriate block according to what was last read in

    PieceType curPiece = this->playPieces.back();
    this->playPieces.pop_back();
    this->playPieces.emplace(this->playPieces.begin(), curPiece);
    unique_ptr<Piece> nPiece;
    nPiece->setPiece(curPiece);
    return nPiece;

}

/*
string LevelZero::getFile() {
//    return pieceIs;
}
*/

void LevelZero::setFile(string fn) {
    if (fn == this->fileName) {
        return;  // don't recreate the vector
    }
    this->fileName = fn;
    this->playPieces.clear();
    string pieceInputs;
    ifstream ifs(fn);
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
