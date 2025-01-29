#include "board.h"
#include "stdio.h"
#include <tuple>

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
        matrix[row * 7][0] = std::make_shared<Rook>(colors[row]);
        matrix[row * 7][1] = std::make_shared<Knight>(colors[row]);
        matrix[row * 7][2] = std::make_shared<Bishop>(colors[row]);
        matrix[row * 7][3] = std::make_shared<King>(colors[row]);
        matrix[row * 7][4] = std::make_shared<Queen>(colors[row]);
        matrix[row * 7][5] = std::make_shared<Bishop>(colors[row]);
        matrix[row * 7][6] = std::make_shared<Knight>(colors[row]);
        matrix[row * 7][7] = std::make_shared<Rook>(colors[row]);

        for (int col = 0; col < 8; col++) {
            matrix[1 + row * 5][col] = std::make_shared<Pawn>(colors[row]);
        }
    }
}


std::shared_ptr<BasePiece> Board::getPieceAt(int row, int col){
    return matrix[row][col];
}



// Retorna {movimento bem-sucedido, peça eliminada (ou nullptr)}
std::tuple<bool, bool, std::shared_ptr<BasePiece>> Board::movePiece(int startX, int startY, int endX, int endY) {
    if (endX == startX && endY == startY) {
        return {false, false, nullptr};
    }

    std::shared_ptr<BasePiece> selectedPiece = getPieceAt(startX, startY);
    if (!selectedPiece) {
        return {false, false, nullptr};
    }

    std::shared_ptr<BasePiece> eliminatedPiece;
    bool wasPieceEliminated = false;
    auto pos = matrix[endX][endY];
    if (pos && pos->getColor() != selectedPiece->getColor()){
        if (selectedPiece->canEliminate(startX, startY, endX, endY)) {
            eliminatedPiece = matrix[endX][endY];
            wasPieceEliminated = true;
            matrix[endX][endY] = std::move(matrix[startX][startY]);
            return {true, wasPieceEliminated, eliminatedPiece};
        }
        return {false, false, nullptr};
    }

    if (!selectedPiece->isValidMovement(startX, startY, endX, endY)) {
        return {false, false, nullptr};
    }

    matrix[endX][endY] = std::move(matrix[startX][startY]);
    return {true, wasPieceEliminated, nullptr};
}
