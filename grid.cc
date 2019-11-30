#include "grid.h"
#include "info.h"
#include "state.h"
#include "subject.h"
#include "observer.h"

bool noCollision(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t base_row, const size_t base_col){
    for (int i = cols - 1; i >= 0; --i){
        for (auto &col: offset){
            
        }
    }
}

void Grid::addOffset(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t base_row, const size_t base_col){
    
}
void Grid::deleteOffset(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t base_row, const size_t base_col){

}
void Grid::notify(Subject<InfoType, StateType> &whoFrom) override{
    if (whoFrom.getState().from_type == FromType::Board){
        return;
    }
    if (whoFrom.getState().command_type == CommandType::RotateCW){
        // Check if it's a valid move
        if ()
    }
}

