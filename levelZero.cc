#include "levelZero.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Piece * LevelZero::create() {
    // read in from sequence1.txt and sequence2.txt
    // loop if game is not over by EOF!!

    // check if last read in was EOF, then restart
    // else, generate appropriate block according to what was last read in

    string curPiece = this->playPieces.back();
    this->playPieces.pop_back();
    this->playPieces.emplace(this->playPieces.begin(), curPiece);
    Piece * nPiece;
    // not sure how to create a Piece * with the type: ask tmr!!
    // setPiece
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
            if (newPiece != "I" && newPiece != "J" && newPiece != "L" && newPiece != "T" &&
                newPiece != "Z" && newPiece != "S" && newPiece != "O") {
                    // ignore: invalid piece type
            } else {
                this->playPieces.emplace(this->playPieces.begin(), newPiece);
            }
        }
    }
}
