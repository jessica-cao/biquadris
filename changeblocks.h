#ifndef CHANGEBLOCKS_H
#define CHANGEBLOCKS_H
#include "abscommands.h"

class changeBlocks : public AbsCommands {
    public:
    void ib(AbsPieces &abs);
    void jb(AbsPieces &abs);
    void lb(AbsPieces &abs);
    void tb(AbsPieces &abs);
    void zb(AbsPieces &abs);
    void sb(AbsPieces &abs);
    void ob(AbsPieces &abs);

};

#endif
