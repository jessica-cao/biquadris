#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "grid.h"
#include "pieces.h"
#include "levelZero.h"

class Player {
    int score = 0;
    bool effect = false;
    bool blind = false;
    int heavy = 0;

    std::vector<Piece> playerPieces;
    public: // sorry probably bad practice again
    std::unique_ptr<Grid> theGrid;
    std::unique_ptr<Levels> pLevel{new LevelZero()};
    int nLevel = 0;
    int getScore(); // returns the score
    void incrementScoreBy(int); // increments the score by a certain number
    void clearScore(); // resets the score to zero

    Piece * next; // Sorry im completely unfunctional rn, EDIT!!!!!!!!!!!
                  // assuming that we are creating all pieces in player, this is fine

    // for the special actions
    bool canEffect(); // get effect
    void setEffect(bool effectIs);
    bool isBlind(); // get blind
    void setBlind(bool blindness);
    int getHeavy();
    void setHeavy(int heaviness);

    // for command stuff
};

#endif
