#ifndef _LEVELS_H_
#define _LEVELS_H_

class AbsPiece;

class Levels {
    public:
    virtual AbsPiece * create() = 0;
};

#endif
