#ifndef _PIECES_H_
#define _PIECES_H_
#include "player.h"
#include <cstddef>
#include "info.h"
#include "state.h"
#include "observer.h"
#include "subject.h"
#include "level.h"
#include <vector>

class Piece: public Observer<Info, State>, Subject<Info, State> {
    Player * player;
    Level * level;
    size_t base_row, base_col;
    std::vector<std::vector<bool>> offset;
    size_t offset_height;
    size_t offset_width;
    PieceType piece_type;
    Piece();
    public:
    void setPiece(PieceType piece_type);
    void rotate_cw();
    void rotate_ccw();
    void move_l();
    void move_d();
    void move_r();
    void drop();
    void notify(Subject<Info, State> &whoFrom) override;
    Info getInfo() const override;
};

#endif