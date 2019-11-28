#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_
#include "levels.h"

class AbsPiece;

class LevelTwo : Levels {
    public:
    AbsPiece * create() override;
};

#endif
