#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_
#include "levels.h"

class AbsPiece;

class LevelThree : Levels {
    public:
    AbsPiece * create() override;
};

#endif
