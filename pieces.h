#include "info.h"

class AbsPieces {
    Info data;
    virtual void rotate_cw() = 0;
    virtual void rotate_ccw() = 0;
    virtual void move_l() = 0;
    virtual void move_d() = 0;
    virtual void move_r() = 0;
};
