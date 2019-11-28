#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_
#include "levels.h"

class AbsPiece;

class LevelFour : Levels {
    public:
    AbsPiece * create() override;
};

#endif
