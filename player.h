#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "grid.h"
#include "pieces.h"
#include "levelZero.h"

class Player {
    int score = 0;

    public: // sorry probably bad practice again
    std::unique_ptr<Grid> theGrid;
    Levels * pLevel = new LevelZero();
    std::string nLevel = "0";
    int getScore();
    void incrementScore();


    // for the special actions
    bool blind = false;
    bool heavy = false;

    // for command stuff
};

#endif
