#include "info.h"
#include "state.h"
#include "observer.h"
#include "subject.h"

class Piece: public Observer<InfoType, StateType>, Subject<InfoType, StateType> {
    size_t base_row, base_col;
    std::vector<std::vector<bool>> offset;
    size_t offset_height;
    size_t offset_width;
    PieceType piece_type;
    void rotate_cw();
    void rotate_ccw();
    void move_l();
    void move_d();
    void move_r();
    void notify(Subject<InfoType, StateType> &whoFrom);
    Info getInfo() const override;
};
