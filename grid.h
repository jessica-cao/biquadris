#include "observer.h"
#include "subject.h"
#include "info.h"
#include "state.h"

class Grid: public Observer<InfoType, StateType>, Subject<InfoType, StateType> {
    std::vector<std::vector<char>> the_grid;
    // void rotate_cw();
    // void rotate_ccw();
    // void move_l();
    // void move_d();
    // void move_r();
    void addOffset(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t base_row, const size_t base_col);
    void deleteOffset(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t base_row, const size_t base_col);
    void notify(Subject<InfoType, StateType> &whoFrom) override;
};

