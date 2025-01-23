#pragma once

#include <array>
#include "pieces/base_piece.h"
#include "pieces/pawn.h"
#include "pieces/king.h"
#include "pieces/queen.h"
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/rook.h"

class Board
{
public:
    BasePiece* getPieceAt(int row, int col);
    void clearBoard();
    void setupBoard();
    bool movePiece(int startX, int startY, int endX, int endY);


private:
    std::array<std::array<BasePiece*, 8>, 8> matrix;
};


