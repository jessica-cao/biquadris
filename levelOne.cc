#include "levelOne.h"
#include <cstdlib>

AbsPiece * LevelOne::create() {
    // 1/12 chance of S and Z, 1/6 for all others
    int prob = rand() % 12 + 1;
    AbsPiece * nBlock;
    if (prob == 1) {
        nBlock = new AbsPiece::SBlock;
    } else if (prob == 2) {
        nBlock = new AbsPiece::ZBlock;
    } else if (prob == 3 || prob == 4) {
        nBlock = new AbsPiece::IBlock;
    } else if (prob == 5 || prob == 6) {
        nBlock = new AbsPiece::JBlock;
    } else if (prob == 7 || prob == 8) {
        nBlock = new AbsPiece::LBlock;
    } else if (prob == 9 || prob == 10) {
        nBlock = new AbsPiece::OBlock;
    } else {
        nBlock = new AbsPiece::TBlock;
    }
    return nBlock;
}

