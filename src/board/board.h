#pragma once

#include <array>
#include <memory>
#include <tuple>
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
    std::tuple<bool,bool,BasePiece*> movePiece(int startX, int startY, int endX, int endY);


private:
    std::array<std::array<std::unique_ptr<BasePiece>, 8>, 8> matrix;
};


