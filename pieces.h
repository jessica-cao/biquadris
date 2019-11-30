#include "info.h"
#include "observer.h"
#include "subject.h"

class Piece: public Observer<Info>, public Subject<Info> {
    Observer * grid;
    Info info;
    void rotate_cw();
    void rotate_ccw();
    void move_l();
    void move_d();
    void move_r();

};
