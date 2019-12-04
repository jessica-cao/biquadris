#include "levelOne.h"
#include <cstdlib>


using namespace std;

bool LevelOne::isRandom() {
    return true;
}

void LevelOne::setRandom(bool randomness) {
    return;
}

int LevelOne::getLevel() {
    return 1;
}

unique_ptr<Piece> LevelOne::create(Grid * grid) {
    // 1/12 chance of S and Z, 1/6 for all others
    int prob = rand() % 12 + 1;
    PieceType curPiece;
    if (prob == 1) {
        curPiece = PieceType::SBlock;
    } else if (prob == 2) {
        curPiece = PieceType::ZBlock;
    } else if (prob == 3 || prob == 4) {
        curPiece = PieceType::IBlock;
    } else if (prob == 5 || prob == 6) {
        curPiece = PieceType::JBlock;
    } else if (prob == 7 || prob == 8) {
        curPiece = PieceType::LBlock;
    } else if (prob == 9 || prob == 10) {
        curPiece = PieceType::OBlock;
    } else {
        curPiece = PieceType::TBlock;
    }
    unique_ptr<Piece> nPiece {new Piece(grid, curPiece)};
    return nPiece;
}


void LevelOne::setFile(string fn) {
    return;
}

