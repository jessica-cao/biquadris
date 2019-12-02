#include "levelFour.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

bool LevelFour::isRandom() {
    return this->random;
}

void LevelFour::setRandom(bool randomness) {
    this->random = randomness;
}

int LevelFour::getLevel() {
    return 4;
}

unique_ptr<Piece> LevelFour::create(Grid * grid) {
    // 2/9 chance for S and Z, 1/9 for everything else
    // all blocks should be heavy!! nBlock->heavy() ?
    // every 5 turns, drop 1x1 block in middle column (column 6 if counting from 1)
        // this counter is probably gonna be in main, but will need to drop from here; if else block?
    if (this->isRandom()) {
        int prob = rand() % 9 + 1;
        PieceType curPiece;
        if (prob == 1 || prob == 2) {
            curPiece = PieceType::SBlock;
        } else if (prob == 3 || prob == 4) {
            curPiece = PieceType::ZBlock;
        } else if (prob == 5) {
            curPiece = PieceType::IBlock;
        } else if (prob == 6) {
            curPiece = PieceType::JBlock;
        } else if (prob == 7) {
            curPiece = PieceType::LBlock;
        } else if (prob == 8) {
            curPiece = PieceType::OBlock;
        } else {
            curPiece = PieceType::TBlock;
        }
        unique_ptr<Piece> nPiece {new Piece(grid, curPiece)};
        return nPiece;
    } else {
        PieceType curPiece = this->playPieces.back();
        this->playPieces.pop_back();
        this->playPieces.emplace(this->playPieces.begin(), curPiece);
        unique_ptr<Piece> nPiece {new Piece(grid, curPiece)};
        // nPiece->setPiece(curPiece);
        return nPiece;
    }
}

void LevelFour::setFile(string fn) {
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


/*
AbsPieces * LevelFour::create() {
    // 2/9 chance for S and Z, 1/9 for everything else
    // all blocks should be heavy!! nBlock->heavy() ?
    // every 5 turns, drop 1x1 block in middle column (column 6 if counting from 1)
        // this counter is probably gonna be in main, but will need to drop from here; if else block?
    int prob = rand() % 9 + 1;
    AbsPiece * nBlock;
    if (prob == 1 || prob == 2) {
        nBlock = new SBlock();
    } else if (prob == 3 || prob == 4) {
        nBlock = new ZBlock();
    } else if (prob == 5) {
        nBlock = new IBlock();
    } else if (prob == 6) {
        nBlock = new JBlock();
    } else if (prob == 7) {
        nBlock = new LBlock();
    } else if (prob == 8) {
        nBlock = new OBlock();
    } else {
        nBlock = new TBlock();
    }
    return nBlock;
} */
