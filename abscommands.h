#ifndef ABSCOMMANDS_H
#define ABSCOMMNANDS_H
#include "changepos.h"
#include "changelvl.h"
#include "changeblocks.h"
#include <iostream>
#include <vector>
#include <cstddef>

class AbsCommands {
    public:
    virtual void useOn(changePos &cp, std::string str) = 0;
    virtual void useOn(changeLvl &cl, std::string str) = 0;
    virtual void useOn(changeBlocks &cb, std::string str) = 0;
    };


#endif
