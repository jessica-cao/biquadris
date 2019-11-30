#include "info.h"
#include "state.h"
#include "pieces.h"
#include <vector>
using namespace std;

Piece::Piece(){
    base_row = 3;
    base_col = 0;
    setPiece(PieceType PieceType::IBlock);
}

void Piece::setPeice(PieceType piece_type){
    this->piece_type = piece_type;
    if (piece_type == PieceType::IBlock){
        this->offset_height = 1;
        this->offset_width = 4;
        vector<bool> row(this->offset_width, true);
        this->offset.emplace_back(row);
    } else if (piece_type == PieceType::JBlock){
        this->offset_height = 2;
        this->offset_width = 3;
        for(int i = 0; i < this->offset_height; ++i){
            vector<bool> row;
            for(int j = 0; j < this->offset_width ; ++j){
                if((i == 0 && j == 0) || (i == 1 && j == 0) || (i == 1 && j == 1) || (i == 1 && j == 2)){
                    row.emplace_back(true);
                } else {
                    row.emplace_back(false);
                }
                offset.emplace_back(row);
            }
        }
    } else if (piece_type == PieceType::LBlock){
        this->offset_height = 2;
        this->offset_width = 3;
        for(int i = 0; i < this->offset_height; ++i){
            vector<bool> row;
            for(int j = 0; j < this->offset_width ; ++j){
                if((i == 0 && j == 2) || (i == 1 && j == 0) || (i == 1 && j == 1) || (i == 1 && j == 2)){
                    row.emplace_back(true);
                } else {
                    row.emplace_back(false);
                }
                offset.emplace_back(row);
            }
        }
    } else if (piece_type == PieceType::OBlock){
        this->offset_height = 2;
        this->offset_width = 2;
        for(int i = 0; i < this->offset_height; ++i){
            vector<bool> row;
            for(int j = 0; j < this->offset_width ; ++j){              
                vector<bool> row(this->offset_width, true);
                offset.emplace_back(row);
            }
        }
    } else if (piece_type == PieceType::SBlock){
        this->offset_height = 2;
        this->offset_width = 3;
        for(int i = 0; i < this->offset_height; ++i){
            vector<bool> row;
            for(int j = 0; j < this->offset_width ; ++j){
                if((i == 0 && j == 1) || (i == 0 && j == 2) || (i == 1 && j == 0) || (i == 1 && j == 1)){
                    row.emplace_back(true);
                } else {
                    row.emplace_back(false);
                }
                offset.emplace_back(row);
            }
        }
    } else if (piece_type == PieceType::ZBlock){
        this->offset_height = 2;
        this->offset_width = 3;
        for(int i = 0; i < this->offset_height; ++i){
            vector<bool> row;
            for(int j = 0; j < this->offset_width ; ++j){
                if((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 1) || (i == 1 && j == 2)){
                    row.emplace_back(true);
                } else {
                    row.emplace_back(false);
                }
                offset.emplace_back(row);
            }
        }
    } else if (piece_type == PieceType::TBlock){
        this->offset_height = 2;
        this->offset_width = 3;
        for(int i = 0; i < this->offset_height; ++i){
            vector<bool> row;
            for(int j = 0; j < this->offset_width ; ++j){
                if((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 0 && j == 2) || (i == 1 && j == 1)){
                    row.emplace_back(true);
                } else {
                    row.emplace_back(false);
                }
                offset.emplace_back(row);
            }
        }
    }
    this->setState({this->base_row, this->base_col, this->offset, this->offset_height, this->offset_width, FromType::Piece, CommandType::SetPiece});
    try {
        this->notifyObservers();
    } catch (...) {
        // throw another exception
    }
}

void Piece::rotate_cw(){
    size_t rows = offset_height;
    size_t cols = offset_width;
    vector<vector<bool>> final_offset(cols, vector<bool> (rows));
    for(int j=0; j < rows; ++j)
    {
        int dx = (rows - 1) - j;
        for(int i = 0; i < cols; ++i)
        {
            int dy = i;
            final_offset[dy * rows + dx] = offset[j * cols + i];
            // for a 2d Array, you'd just
            // dest[dy][dx] = src[j][i];
        }
    }
    // Note that the offset_height and offset_width switch because the offset was rotated
    size_t final_offset_height = cols;
    size_t final_offset_width = rows;
    this->setState({base_row, base_col, final_offset, final_offset_height, final_offset_width, FromType::Piece, CommandType::RotateCW});
    // Notify the grid
    this->notifyObservers();
}
void Piece::rotate_ccw(){
    
}
void Piece::move_l(){
    if (base_col == 0){
        // Throw exceptions
    }
    this->setState({base_row, base_col - 1, offset, offset_height, offset_width, FromType::Piece, CommandType::RotateCW})
}
void Piece::move_d(){
    if (base_row == 0){
        // Throw exceptions
    }
    this->setState({base_row - 1, base_col, offset, offset_height, offset_width, FromType::Piece, CommandType::RotateCW})
}

void Piece::move_r(){
    this->setState({base_row, base_col + 1, offset, offset_height, offset_width, FromType::Piece, CommandType::RotateCW})

}

void Piece::drop(){
    
}

void Piece::notify(Subject<InfoType, StateType> &whoFrom){
    if (whoFrom.getState().from_type == FromType::Piece){
        return;
    }
    // If it's a deleted row
    if (whoFrom.getState().command_type == CommandType::DeleteRow){
        
    }
    // Make sure that it's yours
    if (this->getState().command_type != CommandType::NoCommand){
        base_col = whoFrom.getState().base_col;
        base_row = whoFrom.getState().base_row;
        offset = whoFrom.getState().offset;
        offset_height = whoFrom.getState().offset_height;
        offset_width = whoFrom.getState().offset_height;
        this->setState(base_col, base_row, offset, offset_height, offset_width, FromType::Piece, CommandType::NoCommand);
    }
}

Info getInfo() const{
    Info info = {base_row, base_col, offset, offset_height, offset_width, piece_type};
    return info;
}