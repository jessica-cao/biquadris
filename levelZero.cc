#include "levelZero.h"
#include <iostream>

using namespace std;

AbsPieces * LevelZero::create() {
    // read in from sequence1.txt and sequence2.txt
    // loop if game is not over by EOF!!

    // check if last read in was EOF, then restart
    // else, generate appropriate block according to what was last read in

    string curPiece = this->getPiece();
    AbsPieces * nBlock;
    if (curPiece == "S") {
        nBlock = new SBlock();
    } else if (curPiece == "Z") {
        nBlock = new ZBlock();
    } else if (curPiece == "I") {
        nBlock = new IBlock();
    } else if (curPiece == "J") {
        nBlock = new JBlock();
    } else if (curPiece == "L") {
        nBlock = new LBlock();
    } else if (curPiece == "O") {
        nBlock = new OBlock();
    } else {
        nBlock = new TBlock();
    }
    return nBlock;
}


string LevelZero::getPiece() {
    return pieceIs;
}

void LevelZero::setPiece(string newPiece) {
    if (newPiece != "S" && newPiece != "Z" && newPiece != "I" && newPiece != "J"
        && newPiece != "L" && newPiece != "O" && newPiece != "T") {
            // throw an exception? since the piece is invalid sorry incomplete for now, will edit when doing main
        }
    pieceIs = newPiece;
}
