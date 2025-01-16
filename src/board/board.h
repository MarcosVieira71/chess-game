#include <array>
#include "pieces/base_piece.h"
class Board
{
private:
    std::array<std::array<BasePiece*, 8>, 8> matrix;
};


