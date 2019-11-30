#include "grid.h"
#include "info.h"
#include "state.h"
#include "subject.h"
#include "observer.h"
using namespace std;

bool noCollision(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t cols, const size_t base_row, const size_t base_col){
    for (int i = rows - 1; i >= 0; --i){
        for (int j = 0; j < cols; ++j){
            if (offset.at(j) && the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) != ' '){
                return false;
            }
        }
    }
    return true;
}

void Grid::addOffset(const PieceType piece_type){
    vector<vector<bool>> offset = state.offset;
    size_t rows = state.offset_height;
    size_t cols = state.offset_width;
    size_t base_row = state.base_row;
    size_t base_col = state.base_col;
    for (int i = rows - 1; i >= 0; --i){
        for (int j = 0; j < cols; ++j){
            if (offset.at(j) && the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) == ' '){
                if (piece_type == PieceType::IBlock){
                    the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) = 'I';
                } else if (piece_type == PieceType::JBlock){
                    the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) = 'J';
                } else if (piece_type == PieceType::LBlock){
                    the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) = 'L';
                } else if (piece_type == PieceType::OBlock){
                    the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) = 'O';
                } else if (piece_type == PieceType::SBlock){
                    the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) = 'S';
                } else if (piece_type == PieceType::TBlock){
                    the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) = 'T';
                } else if (piece_type == PieceType::ZBlock){
                    the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) = 'Z';
                }
            } else if (offset.at(j) && the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) != ' ') {
                // throw exception - dunno how to do it with strong guarantee
            }
        }
    }
}
void Grid::deleteOffset(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t cols, const size_t base_row, const size_t base_col){
    for (int i = rows - 1; i >= 0; --i){
        for (int j = 0; j < cols; ++j){
            if (offset.at(j) && the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) != ' '){
                the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) = ' ';
            }
        }
    }
}
void Grid::notify(Subject<InfoType, StateType> &whoFrom) override{
    if (whoFrom.getState().from_type == FromType::Board){
        return;
    }
    vector<vector<bool>> state_offset = whoFrom.getState().offset;
    size_t state_offset_height = whoFrom.getState().offset_height;
    size_t state_offset_width = whoFrom.getState().offset_width;
    size_t state_base_row = whoFrom.getState().base_row;
    size_t state_base_col = whoFrom.getState().base_col;
    CommandType state_command_type =  whoFrom.getState().command_type;
    if (state_command_type == CommandType::RotateCW || state_command_type == CommandType::RotateCCW){
        // Check if it's a valid move
        if ((state_offset_width + state_base_col >= width) || (state_offset_height + state_base_row >= width) || (state_base_row < 0) || (state_base_col < 0)){
            // This is an invalid move - throw exception
        }

        // Note that getInfo still has the old offset and old height and old base_row and stuff
        // Delete the old stuff from the grid
        this->deleteOffset(whoFrom.getInfo().offset, whoFrom.getInfo().offset_height, whoFrom.getInfo().offset_width, whoFrom.getInfo().base_row, whoFrom.getInfo().base_col);
        // Check if the new stuff has a collision
        bool no_collision = this->noCollision(state_offset, state_offset_height, state_offset_width, state_base_row, state_base_col);
        if (no_collision){
            // If no collision, change the grid's state to the new state and add the new offset
            this->setState({state_base_row, state_base_col, state_offset, state_offset_height, state_offset_width, FromType::Board, state_command_type});
            this->addOffset(whoFrom.getInfo().piece_type)
        } else {
            // If has a collsion, change the grid's state to the old state and add the old offset
            this->setState({whoFrom.getInfo().base_row, whoFrom.getInfo().base_col, whoFrom.getInfo().offset, whoFrom.getInfo().offset_height, whoFrom.getInfo().offset_width, FromType::Board, state_command_type});
            this->addOffset(whoFrom.getInfo().piece_type)
        }
    } else if (state_command_type == CommandType::MoveL){
        
    }
}

