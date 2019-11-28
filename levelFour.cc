#include "levelFour.h"
#include <cstdlib>

AbsPiece * LevelFour::create() {
    // 2/9 chance for S and Z, 1/9 for everything else
    // all blocks should be heavy!! nBlock->heavy() ?
    // every 5 turns, drop 1x1 block in middle column (column 6 if counting from 1)
        // this counter is probably gonna be in main, but will need to drop from here; if else block?
    int prob = rand() % 9 + 1;
    AbsPiece * nBlock;
    if (prob == 1 || prob == 2) {
        nBlock = new AbsPiece::SBlock;
    } else if (prob == 3 || prob == 4) {
        nBlock = new AbsPiece::ZBlock;
    } else if (prob == 5) {
        nBlock = new AbsPiece::IBlock;
    } else if (prob == 6) {
        nBlock = new AbsPiece::JBlock;
    } else if (prob == 7) {
        nBlock = new AbsPiece::LBlock;
    } else if (prob == 8) {
        nBlock = new AbsPiece::OBlock;
    } else {
        nBlock = new AbsPiece::TBlock;
    }
    return nBlock;
}
