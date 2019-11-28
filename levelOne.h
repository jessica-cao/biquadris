#ifndef _LEVELONE_H_
#define _LEVELONE_H_
#include "levels.h"

class AbsPiece;

class LevelOne : Levels {
    public:
    AbsPiece * create() override;
};

#endif
