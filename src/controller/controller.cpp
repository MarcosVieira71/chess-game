#include "controller.h"
#include <stdio.h>

void Controller::initializeGame() {
    board->clearBoard();
    board->setupBoard();
    for(int row = 0; row < 8; row++){
        for(int col = 0; col < 8; col++){
            BasePiece* piece = board->getPieceAt(row, col);
            if(piece) view->updateSquares(row, col, piece);
        }
    }
}
