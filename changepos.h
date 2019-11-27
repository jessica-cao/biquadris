#ifndef CHANGEPOS_H
#define CHANGEPOS_H
#include "abscommands.h"

class changePos : public AbsCommands {
    public:
    void left(AbsPieces &ab);
    void right(AbsPieces &ab);
    void down(AbsPieces &ab);
    void cw(AbsPieces &ab);
    void ccw(AbsPieces &ab);
};

#endif
