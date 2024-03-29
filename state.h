#ifndef _STATE_H_
#define _STATE_H_
#include <vector> // added as a syntax fix
#include <cstddef>

enum class PieceType { IBlock, JBlock, LBlock, TBlock, ZBlock, SBlock, OBlock};
enum class FromType { Board, Piece };
enum class CommandType { RotateCW, RotateCCW, MoveL, MoveD, MoveR, Drop, SetPiece, DeleteRow, NoCommand };

struct State {
  size_t base_row, base_col;
  std::vector<std::vector<bool>> offset;
  size_t offset_height;
  size_t offset_width;
  FromType from_type;
  CommandType command_type;
  int deleted_row = 0;
};

#endif
