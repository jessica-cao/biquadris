#include "levelTwo.h"
#include <cstdlib>

using namespace std;

bool LevelTwo::isRandom() {
    return true;
}

void LevelTwo::setRandom(bool randomness) {
    return;
}

int LevelTwo::getLevel() {
    return 2;
}

unique_ptr<Piece> LevelTwo::create(Grid * grid) {
    // 1/12 chance of S and Z, 1/6 for all others

    int prob = rand() % 7;
    PieceType curPiece;
    if (prob == 0) {
        curPiece = PieceType::SBlock;
    } else if (prob == 1) {
        curPiece = PieceType::ZBlock;
    } else if (prob == 2) {
        curPiece = PieceType::IBlock;
    } else if (prob == 3) {
        curPiece = PieceType::JBlock;
    } else if (prob == 4) {
        curPiece = PieceType::LBlock;
    } else if (prob == 5) {
        curPiece = PieceType::OBlock;
    } else {
        curPiece = PieceType::TBlock;
    }
    unique_ptr<Piece> nPiece {new Piece(grid, curPiece)};
    return nPiece;
}


void LevelTwo::setFile(string fn) {
    return;
}

