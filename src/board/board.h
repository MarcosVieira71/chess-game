#include <array>
#include "pieces/base_piece.h"
#include "pieces/pawn.h"

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


