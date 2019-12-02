#ifndef _GRID_H_
#define _GRID_H_
#include <cstddef>
#include "observer.h"
#include "subject.h"
#include "info.h"
#include "state.h"
#include "levelZero.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"
#include <vector>

class Player;

class Grid: public Observer<Info, State>, public Subject<Info, State> {
    size_t height = 15;
    size_t width = 11;
    Player * player;
    std::vector<std::vector<char>> the_grid;
    // void rotate_cw();
    // void rotate_ccw();
    // void move_l();
    // void move_d();
    // void move_r();
    bool noCollision(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t cols, const size_t base_row, const size_t base_col);
    void addOffset(const PieceType piece_type);
    void deleteOffset(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t cols, const size_t base_row, const size_t base_col);
    void deleteRows();
    int deletedRows = 0; // levelFour edit

    public:
    int getDeletedRows(); //levelFour edit
    void setDeletedRows(int num); //levelFour edit
    bool isDone();
    void insertStarBlock();
    void setPlayer(Player * player);
    Info getInfo() const override;
    void init();
    void clear();
    std::vector<std::vector<char>>& getGrid();
    void notify(Subject<Info, State> &whoFrom) override;
};

#endif
