#include "levelTwo.h"
#include <cstdlib>

AbsPiece * LevelTwo::create() {
    // 1/7 chance of any piece
    int prob = rand() % 7;
    AbsPiece * nBlock;
    if (prob == 0) {
        nBlock = new AbsPiece::SBlock;
    } else if (prob == 1) {
        nBlock = new AbsPiece::ZBlock;
    } else if (prob == 2) {
        nBlock = new AbsPiece::IBlock;
    } else if (prob == 3) {
        nBlock = new AbsPiece::JBlock;
    } else if (prob == 4) {
        nBlock = new AbsPiece::LBlock;
    } else if (prob == 5) {
        nBlock = new AbsPiece::OBlock;
    } else {
        nBlock = new AbsPiece::TBlock;
    }
    return nBlock;
}
