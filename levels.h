#ifndef _LEVELS_H_
#define _LEVELS_H_

#include "pieces.h"

class Levels {
    public:
    virtual Piece * create() = 0;
//    virtual string getFile() = 0;  // will need to add to 0, 3, 4
    virtual void setFile(string fn) = 0;  
};

#endif
