#ifndef _PIECES_H_
#define _PIECES_H_
#include <cstddef>
#include "info.h"
#include "state.h"
#include "observer.h"
#include "subject.h"
#include <vector>

class Player;

class Piece: public Observer<Info, State>, Subject<Info, State> {
    Player * player;
    int level;
    size_t base_row, base_col;
    std::vector<std::vector<bool>> offset;
    size_t offset_height;
    size_t offset_width;
    PieceType piece_type;
    public:
    Piece();
    void setPiece(PieceType piece_type);
    void setLevel(int level);
    void setPlayer(Player * player);
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