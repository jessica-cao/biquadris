#include "info.h"
#include "pieces.h"
#include <vector>
using namespace std;

void Piece::rotate_cw(){
    vector<vector<bool>> offset = info.offset;
    size_t rows = info.offset_height;
    size_t cols = info.offset_width;
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
    info.offset = final_offset;
    info.offset_height = cols;
    info.offset_width = rows;
    this->setState({info.base_row, info.base_col, info.offset, info.offset_height, info.offset_width, info.piece_type, FromType::Piece, CommandType::RotateCW});
    // notify the grid
    this->notifyObservers();
}
void Piece::rotate_ccw(){
    
}
void Piece::move_l(){

}
void Piece::move_d(){

}
void Piece::move_r(){

}

void Piece::notify(Subject<InfoType, StateType> &whoFrom){
    if (whoFrom.getState().from_type == Piece){
        return;
    }
    info.base_col = whoFrom.getState().base_col;
    info.base_row = whoFrom.getState().base_row;
    info.offset = whoFrom.getState().offset;
}