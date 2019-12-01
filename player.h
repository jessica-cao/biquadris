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

    std::unique_ptr<Piece> curPiece;
    std::unique_ptr<Piece> nextPiece;

    std::vector<Piece> playerPieces;
    public: // sorry probably bad practice again
    std::unique_ptr<Grid> theGrid;
    std::unique_ptr<Levels> pLevel{new LevelZero()};
    int nLevel = 0;
    int getScore(); // returns the score
    void incrementScoreBy(int); // increments the score by a certain number
    void clearScore(); // resets the score to zero

    std::unique_ptr<Piece> getCur();
    void setCur();
    std::unique_ptr<Piece> getNext();
    void setNext();

    // for the special actions
    bool canEffect(); // get effect
    void setEffect(bool effectIs);
    bool isBlind(); // get blind
    void setBlind(bool blindness);
    int getHeavy();
    void setHeavy(int heaviness);

    // for command stuff
    void levelup();
    void leveldown();
    void random();
    void norandom();
    void restart();
    void I();
    void J();
    void L();
    void O();
    void S();
    void Z();
    void T();
};

#endif
