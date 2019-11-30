#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "grid.h"
#include "pieces.h"

class Player {
    std::unique_ptr<Grid> theGrid;
    int score = 0;

    // for the special actions
    bool blind = false;
    bool heavy = false;

    // for command stuff
};

#endif
