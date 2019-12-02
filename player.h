#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "grid.h"
#include "pieces.h"
#include "levelZero.h"

#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"

class Player {
    int score = 0;
    bool effect = false;
    bool blind = false;
    int heavy = 0;

    std::unique_ptr<Piece> curPiece;
    std::unique_ptr<Piece> nextPiece;
    std::vector<Piece> playerPieces;


    public: // sorry probably bad practice a gain
    
    Player();
    std::unique_ptr<Grid> theGrid{new Grid()};

    std::unique_ptr<Levels> pLevel{new LevelZero()};
    int nLevel = 0;
    int getScore(); // returns the score
    void incrementScoreBy(int); // increments the score by a certain number
    void clearScore(); // resets the score to zero

    Piece * getCur();
    std::unique_ptr<Piece> createPiece();
    void setCurrPiece();
    Piece * getNext();
    void setNextPiece();

    // for the special actions
    bool canEffect(); // get effect
    void setEffect(bool effectIs);
    bool isBlind(); // get blind
    void setBlind(bool blindness);
    int getHeavy();
    void setHeavy(int heaviness);

    // for command stuff
    void move(std::string);
    void drop();
    void rotate(std::string);
    void randomness(std::string);
    void levelup();
    void leveldown();
    void sequence();
    void restart();
    void setSpecificPieceType(PieceType);
};

#endif
