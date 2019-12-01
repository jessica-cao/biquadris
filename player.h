#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "grid.h"
#include "pieces.h"
#include "levelZero.h"

class Player {
    int score = 0;
    bool blind = false;

    public: // sorry probably bad practice again
    std::unique_ptr<Grid> theGrid;
    std::unique_ptr<Levels> pLevel{new LevelZero()};
    int nLevel = 0;
    int getScore(); // returns the score
    void incrementScoreBy(int); // increments the score by a certain number
    void clearScore(); // resets the score to zero


    // for the special actions
    bool isBlind(); // get blind
    void setBlind(bool blindness);

    bool heavy = false;

    // for command stuff
};

#endif
