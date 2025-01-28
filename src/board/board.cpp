#include "board.h"
#include "stdio.h"
//REI BRANCO NA CASA PRETA 
//REI PRETO NA CASA BRANCAAA
void Board::clearBoard() {
    for (auto& row : matrix) {
        for (auto& cell : row) {
            cell.reset(); 
        }
    }
}


void Board::setupBoard() {
    Colors colors[] = { Colors::White, Colors::Black };

    for (int row = 0; row < 2; row++) {
        matrix[0 + row * 7][0] = std::make_unique<Rook>(colors[row]);
        matrix[0 + row * 7][1] = std::make_unique<Knight>(colors[row]);
        matrix[0 + row * 7][2] = std::make_unique<Bishop>(colors[row]);
        matrix[0 + row * 7][3] = std::make_unique<King>(colors[row]);
        matrix[0 + row * 7][4] = std::make_unique<Queen>(colors[row]);
        matrix[0 + row * 7][5] = std::make_unique<Bishop>(colors[row]);
        matrix[0 + row * 7][6] = std::make_unique<Knight>(colors[row]);
        matrix[0 + row * 7][7] = std::make_unique<Rook>(colors[row]);

        for (int col = 0; col < 8; col++) {
            matrix[1 + row * 5][col] = std::make_unique<Pawn>(colors[row]);
        }
    }
}


BasePiece* Board::getPieceAt(int row, int col){
    return matrix[row][col].get();
}


bool Board::movePiece(int startX, int startY, int endX, int endY) {
    if(matrix[endX][endY]) return false;

    BasePiece* selectedPiece = getPieceAt(startX, startY);
    
    if (!selectedPiece->isValidMovement(startX, startY, endX, endY)) {
        return false;
    }
    
    matrix[endX][endY] = std::move(matrix[startX][startY]);
    return true;
}
