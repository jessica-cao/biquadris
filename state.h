#include <vector> // added as a syntax fix
#include <cstddef>

enum class PieceType { IBlock, JBlock, LBlock, TBlock, ZBlock, SBlock, OBlock};
enum class FromType { Board, Piece };
enum class CommandType { RotateCW, RotateCCW, MoveL, MoveD, MoveR };

struct State {
  size_t base_row, base_col;
  std::vector<std::vector<bool>> offset;
  size_t offset_height;
  size_t offset_width;
  FromType from_type;
  CommandType command_type;
};