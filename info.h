#ifndef __INFO_H__
#define __INFO_H__
#include <cstddef>

enum class PieceType { IBlock, JBlock, LBlock, TBlock, ZBlock, SBlock, OBlock};

struct Info {
  size_t base_row, base_col;
  Vector<bool> offset;
  size_t offset_height;
  size_t offset_width;
  PieceType piecetype;
};

#endif

