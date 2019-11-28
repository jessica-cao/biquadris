#ifndef _LEVELZERO_H_
#define _LEVELZERO_H_
#include "levels.h"

class AbsPiece;

class LevelZero : Levels {
    public:
    AbsPiece * create() override;
};

#endif
