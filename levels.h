#ifndef _LEVELS_H_
#define _LEVELS_H_

#include "pieces.h"
#include <string>

class Levels {
    public:
    virtual std::unique_ptr<Piece> create() = 0;
//    virtual string getFile() = 0;  // will need to add to 0, 3, 4
    virtual void setFile(std::string fn) = 0;  
};

#endif
