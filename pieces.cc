#include "info.h"
#include "state.h"
#include "pieces.h"
#include <vector>
using namespace std;

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
    info.base_col = whoFrom.getState().base_col;
    info.base_row = whoFrom.getState().base_row;
    info.offset = whoFrom.getState().offset;
    info.offset_height = whoFrom.getState().offset_height;
    info.offset_width = whoFrom.getState().offset_height;
}

Info getInfo() const{
    Info info = {base_row, base_col, offset, offset_height, offset_width, piece_type};
    return info;
}