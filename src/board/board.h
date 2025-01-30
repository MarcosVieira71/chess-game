#pragma once

#include <array>
#include <memory>
#include <tuple>
#include <vector>

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
    std::shared_ptr<BasePiece> getPieceAt(int row, int col);
    void clearBoard();
    void setupBoard();
    std::vector<std::pair<int, int>> getValidMoves(int startX, int startY);
    std::tuple<bool,bool,std::shared_ptr<BasePiece>> movePiece(int startX, int startY, int endX, int endY);

private:
    std::tuple<bool, bool, std::shared_ptr<BasePiece>> movePawn(int startX, int startY, int endX, int endY);
    std::vector<std::pair<int, int>> getValidMovesForPawn(std::shared_ptr<Pawn> piece, int startX, int startY);
    bool isPathClear(int startX, int startY, int endX, int endY);
    
    std::array<std::array<std::shared_ptr<BasePiece>, 8>, 8> matrix;
};


