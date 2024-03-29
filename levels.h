#ifndef _LEVELS_H_
#define _LEVELS_H_
//#include "grid.h"
#include "pieces.h"
#include "state.h"
#include <string>

class Levels {
    public:
    virtual bool isRandom() = 0;
    virtual void setRandom(bool randomness) = 0;
    
    virtual int getLevel() = 0;
    virtual std::unique_ptr<Piece> create(Grid * grid) = 0;
    virtual void setFile(std::string fn) = 0;  
};

#endif
