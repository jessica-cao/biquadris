#ifndef _GRID_H_
#define _GRID_H_
#include <cstddef>
#include "observer.h"
#include "subject.h"
#include "info.h"
#include "state.h"
#include "levels.h"
#include "levelZero.h"
#include <vector>

class Grid: public Observer<Info, State>, Subject<Info, State> {
    size_t height = 15;
    size_t width = 11;
    std::vector<std::vector<char>> the_grid;
    // void rotate_cw();
    // void rotate_ccw();
    // void move_l();
    // void move_d();
    // void move_r();
    void init();
    bool noCollision(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t cols, const size_t base_row, const size_t base_col);
    void addOffset(const PieceType piece_type);
    void deleteOffset(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t cols, const size_t base_row, const size_t base_col);
    void deleteRow();
    Info getInfo() const override;

    public:
    std::vector<std::vector<char>>& getGrid();
    void notify(Subject<Info, State> &whoFrom) override;
    Levels * pLevel = new LevelZero();  // probably not good design for these to be public
    string nLevel = "0";
};

#endif

