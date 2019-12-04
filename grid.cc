#include "grid.h"
#include "info.h"
#include "state.h"
#include "subject.h"
#include "observer.h"
#include "player.h"
#include "exception.h"
#include <vector>
#include <iostream>
using namespace std;

void Grid::setPlayer(Player * player){
    this->player = player;
}

bool Grid::isDone(){
    for (int i = 0; i < width; ++i){
        if(the_grid.at(3).at(i) != ' '){
            return true;
        }
    }
    return false;
}

void Grid::insertStarBlock(){
    for (int i = height - 1; i >= 0; --i){
        if(the_grid.at(i).at(5) == ' '){
            the_grid.at(i).at(5) = '*';
            break;
        }
    }
}

vector<vector<char>>& Grid::getGrid(){
    return the_grid;
}

void Grid::init(){
    for(int i = 0; i < height; ++i){          
        vector<char> row(width, ' ');
        the_grid.emplace_back(row);
    }
}

void Grid::clear(){
    the_grid.clear();
    this->init();
}

bool Grid::noCollision(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t cols, const size_t base_row, const size_t base_col){
    for (int i = rows - 1; i >= 0; --i){
        for (int j = 0; j < cols; ++j){
            if (offset.at(i).at(j) && the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) != ' '){
                return false;
            }
        }
    }
    return true;
}

void Grid::addOffset(const PieceType piece_type){
    vector<vector<bool>> offset = this->getState().offset;
    size_t rows = this->getState().offset_height;
    size_t cols = this->getState().offset_width;
    size_t base_row = this->getState().base_row;
    size_t base_col = this->getState().base_col;
    for (int i = rows - 1; i >= 0; --i){
        for (int j = 0; j < cols; ++j){
            if (offset.at(i).at(j) && the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) == ' '){
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
            } else if (offset.at(i).at(j) && the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) != ' ') {
                // throw exception - dunno how to do it with strong guarantee
            }
        }
    }
}

void Grid::deleteOffset(const std::vector<std::vector<bool>> &offset, const size_t rows, const size_t cols, const size_t base_row, const size_t base_col){
    for (int i = rows - 1; i >= 0; --i){
        for (int j = 0; j < cols; ++j){
            if (offset.at(i).at(j) && the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) != ' '){
                the_grid.at(base_row - (rows - 1 - i)).at(base_col + j) = ' ';
            }
        }
    }
}

void Grid::deleteRows(){
    bool is_full = true;
    int num_rows_deleted = 0;
    for (int i = height - 1; i >= 0; --i){
        for (int j = 0; j < width; ++j){
            if (the_grid.at(i).at(j) == ' '){
                is_full = false;
            }
        }
        if (is_full){
            this->setState({this->getState().base_row, this->getState().base_col, this->getState().offset, this->getState().offset_height, this->getState().offset_width, FromType::Board, CommandType::DeleteRow, i});
            this->notifyObservers();
            vector<char> new_row(width, ' ');
            the_grid.emplace(the_grid.begin(), new_row);
            ++num_rows_deleted;
            ++i;
        }
        is_full = true;
    }

    int level = player->pLevel->getLevel();
    if (num_rows_deleted != 0){
        player->incrementScoreBy((level + num_rows_deleted) * (level + num_rows_deleted));
    }

    if (num_rows_deleted >= 2){
        player->setEffect(true);
    }
    
    this->setDeletedRows(num_rows_deleted);  // LEVELFOUR EDITING
}

// LEVELFOUR EDITING

int Grid::getDeletedRows() {
    return this->deletedRows;
}

//maybe check that greater than 0 or use size_t
void Grid::setDeletedRows(int num) {
    this->deletedRows = num;
}

// LEVELFOUR EDITING

void Grid::notify(Subject<Info, State> &whoFrom) {
    if (whoFrom.getState().from_type == FromType::Board){
        return;
    }
    vector<vector<bool>> state_offset = whoFrom.getState().offset;
    size_t state_offset_height = whoFrom.getState().offset_height;
    size_t state_offset_width = whoFrom.getState().offset_width;
    size_t state_base_row = whoFrom.getState().base_row;
    size_t state_base_col = whoFrom.getState().base_col;
    CommandType state_command_type =  whoFrom.getState().command_type;
    if (state_command_type == CommandType::SetPiece){
        bool no_collision = this->noCollision(state_offset, state_offset_height, state_offset_width, state_base_row, state_base_col);
        if (no_collision){
            this->setState({state_base_row, state_base_col, state_offset, state_offset_height, state_offset_width, FromType::Board, state_command_type});
            this->addOffset(whoFrom.getInfo().piece_type);
        } else {
            // throw exception AAAAAAAAAAAAAAAAAAAAAAA
            throw DoneException {"Done game."};
        }
    }
    if (state_command_type == CommandType::RotateCW || state_command_type == CommandType::RotateCCW || state_command_type == CommandType::MoveL || state_command_type == CommandType::MoveR || state_command_type == CommandType::MoveD){
        // Check if it's a valid move
        if (((state_offset_width + whoFrom.getInfo().base_col >= width) || (state_offset_height - whoFrom.getInfo().base_row < 0)) && (state_command_type == CommandType::RotateCW || state_command_type == CommandType::RotateCCW)){
            return;
        } else if ((state_offset_width + state_base_col > width) && (state_command_type == CommandType::MoveR)) { // editing >= before
            return;
        } else if ((whoFrom.getInfo().base_col == 0) && (state_command_type == CommandType::MoveL)){
            return;
        } else if ((whoFrom.getInfo().base_row == height - 1) && (state_command_type == CommandType::MoveD)){
            return;
        }
        // Note that getInfo still has the old offset and old height and old base_row and stuff
        // Delete the old stuff from the grid
        this->deleteOffset(whoFrom.getInfo().offset, whoFrom.getInfo().offset_height, whoFrom.getInfo().offset_width, whoFrom.getInfo().base_row, whoFrom.getInfo().base_col);
        // Check if the new stuff has a collision


        bool no_collision = this->noCollision(state_offset, state_offset_height, state_offset_width, state_base_row, state_base_col);
        
        if (no_collision){
            // If no collision, change the grid's state to the new state and add the new offset
            this->setState({state_base_row, state_base_col, state_offset, state_offset_height, state_offset_width, FromType::Board, state_command_type});
            this->addOffset(whoFrom.getInfo().piece_type);

            
            
            this->notifyObservers();

            // Check if the entire row is full and delete the row
            this->deleteRows();
        } else {
            // If has a collsion, change the grid's state to the old state and add the old offset
            this->setState({whoFrom.getInfo().base_row, whoFrom.getInfo().base_col, whoFrom.getInfo().offset, whoFrom.getInfo().offset_height, whoFrom.getInfo().offset_width, FromType::Board, state_command_type});
            this->addOffset(whoFrom.getInfo().piece_type);
            this->notifyObservers();
        }

    } else if (state_command_type == CommandType::Drop) {
        if (state_base_row != height - 1){
            this->deleteOffset(whoFrom.getInfo().offset, whoFrom.getInfo().offset_height, whoFrom.getInfo().offset_width, whoFrom.getInfo().base_row, whoFrom.getInfo().base_col);
            size_t new_base_row = whoFrom.getInfo().base_row; // original code: state_t, changed to size_t - Jessica
            while (new_base_row != height - 1){
                bool no_collision = this->noCollision(state_offset, state_offset_height, state_offset_width, new_base_row + 1, state_base_col);
                if (no_collision == true){
                    ++new_base_row;
                } else {
                    break;
                }
            }
            this->setState({new_base_row, state_base_col, state_offset, state_offset_height, state_offset_width});
            this->addOffset(whoFrom.getInfo().piece_type);
            this->deleteRows();
        }
    }
}

Info Grid::getInfo() const {
    Info info = {0, 0, vector<vector<bool>> {}, 0, 0, PieceType::IBlock}; // what is the original offset?
    return info;
}
