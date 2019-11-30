#include "observer.h"
#include "subject.h"
#include "info.h"
#include "state.h"
#include "levels.h"
#include "levelZero.h"

class Grid: public Observer<InfoType, StateType>, Subject<InfoType, StateType> {
    size_t height = 15;
    size_t width = 11;
    std::vector<std::vector<char>> the_grid;
    // void rotate_cw();
    // void rotate_ccw();
    // void move_l();
    // void move_d();
    // void move_r();
    void addOffset(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t base_row, const size_t base_col);
    void deleteOffset(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t base_row, const size_t base_col);
    void notify(Subject<InfoType, StateType> &whoFrom) override;

    public:
    Levels * pLevel = new LevelZero();  // probably not good design for these to be public
    string nLevel = "0";
};

