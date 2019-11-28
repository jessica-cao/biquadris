#include "levelOne.h"
#include <cstdlib>

AbsPieces * LevelOne::create() {
    // 1/12 chance of S and Z, 1/6 for all others
    int prob = rand() % 12 + 1;
    AbsPieces * nBlock;
    if (prob == 1) {
        nBlock = new SBlock();
    } else if (prob == 2) {
        nBlock = new ZBlock();
    } else if (prob == 3 || prob == 4) {
        nBlock = new IBlock();
    } else if (prob == 5 || prob == 6) {
        nBlock = new JBlock();
    } else if (prob == 7 || prob == 8) {
        nBlock = new LBlock();
    } else if (prob == 9 || prob == 10) {
        nBlock = new OBlock();
    } else {
        nBlock = new TBlock();
    }
    return nBlock;
}

