#ifndef CHANGELVL_H
#define CHANGELVL_H
#include "abscommands.h"

class changeLvl : public AbsCommands {
    public:
    void levelUp(AbsPieces &ab);
    void levelDown(AbsPieces &ab);
};

#endif
