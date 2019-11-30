#ifndef _LEVELS_H_
#define _LEVELS_H_

#include "pieces.h"

class Levels {
    public:
    virtual Piece * create() = 0;
    virtual string getPiece() = 0;  // soley for LevelZero
    virtual void setPiece(string newPiece) = 0;  
};

#endif
