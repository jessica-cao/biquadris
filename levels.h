#ifndef _LEVELS_H_
#define _LEVELS_H_

#include "abspieces.h"

class Levels {
    public:
    virtual AbsPieces * create() = 0;
};

#endif
