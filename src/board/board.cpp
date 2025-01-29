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



// Retorna {movimento se foi bem-sucedido, se peça foi eliminada e a peça eliminada (ou nullptr)}
std::tuple<bool, bool, std::shared_ptr<BasePiece>> Board::movePiece(int startX, int startY, int endX, int endY) {
    std::shared_ptr<BasePiece> selectedPiece = getPieceAt(startX, startY);
    if ((endX == startX && endY == startY) || !selectedPiece->isValidMovement(startX, startY, endX, endY)){
        return {false, false, nullptr};
    }

    auto target = matrix[endX][endY];
    std::shared_ptr<BasePiece> eliminatedPiece = nullptr;
    bool wasPieceEliminated = false;

    if (target && selectedPiece->canEliminate(startX, startY, endX, endY, target->getColor())) {
        eliminatedPiece = std::move(target);
        wasPieceEliminated = true;
    } else if (target) {
        return {false, false, nullptr};
    }

    if (auto pawnPiece = std::dynamic_pointer_cast<Pawn>(selectedPiece)) {
        pawnPiece->updateFirstMove();
    }

    matrix[endX][endY] = std::move(matrix[startX][startY]);
    return {true, wasPieceEliminated, eliminatedPiece};
}

std::vector<std::pair<int, int>> Board::getValidMoves(int startX, int startY){
    std::vector<std::pair<int, int>> validMoves;
    std::shared_ptr<BasePiece> piece = getPieceAt(startX, startY);

    if (!piece) return validMoves;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (piece->isValidMovement(startX, startY, row, col)){
                auto target = matrix[row][col];
                if(!target){
                    validMoves.emplace_back(row, col);
                }
                else if(target->getColor() != piece->getColor()){
                    validMoves.emplace_back(row, col);
                }
            }
        }
    }

    return validMoves;
}