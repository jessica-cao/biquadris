#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "grid.h"
#include "pieces.h"
#include "levelZero.h"

class Player {
    public: // sorry probably bad practice again
    std::unique_ptr<Grid> theGrid;
    int score = 0;
    Levels * pLevel = new LevelZero();
    string nLevel = "0";

    // for the special actions
    bool blind = false;
    bool heavy = false;

    // for command stuff
};

#endif
