#include "levelTwo.h"
#include <cstdlib>

AbsPieces * LevelTwo::create() {
    // 1/7 chance of any piece
    int prob = rand() % 7;
    AbsPiece * nBlock;
    if (prob == 0) {
        nBlock = new SBlock();
    } else if (prob == 1) {
        nBlock = new ZBlock();
    } else if (prob == 2) {
        nBlock = new IBlock();
    } else if (prob == 3) {
        nBlock = new JBlock();
    } else if (prob == 4) {
        nBlock = new LBlock();
    } else if (prob == 5) {
        nBlock = new OBlock();
    } else {
        nBlock = new TBlock();
    }
    return nBlock;
}
