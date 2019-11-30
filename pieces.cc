#include "info.h"
#include "pieces.h"
#include <vector>
using namespace std;


void Piece::rotate_cw(){
    vector<vector<bool>> offset = info.offset;
    size_t rows = info.offset_height;
    size_t cols = info.offset_height;
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
    info.offset_height = final_offset;
    // notify the grid
}
void Piece::rotate_ccw(){
    
}
void Piece::move_l(){

}
void Piece::move_d(){

}
void Piece::move_r(){

}