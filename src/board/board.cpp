#include <tuple>

#include "board.h"

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

void Board::replacePiece(int row, int col, std::shared_ptr<BasePiece> newPiece) {
    matrix[row][col] = newPiece;
}

std::shared_ptr<BasePiece> Board::getPieceAt(int row, int col){
    return matrix[row][col];
}


// Retorna {movimento se foi bem-sucedido, se peça foi eliminada e a peça eliminada (ou nullptr)}
std::tuple<bool, bool, std::shared_ptr<BasePiece>> Board::movePiece(int startX, int startY, int endX, int endY) {
    
    //Caso 1: Posicao inicial e final ser igual:
    if (endX == startX && endY == startY) return {false, false, nullptr};
    
    //Caso 2: movimento vai causar um cheque para a cor da peça movida
    if(willMoveCauseACheck(startX, startY, endX, endY)) return {false, false, nullptr};
    
    //Caso 3: O caminho não está livre para o movimento
    if (!isPathClear(startX, startY, endX, endY)) return {false, false, nullptr};
    

    std::shared_ptr<BasePiece> selectedPiece = getPieceAt(startX, startY);

    auto target = matrix[endX][endY];
    std::shared_ptr<BasePiece> eliminatedPiece = nullptr;
    bool wasPieceEliminated = false;
    bool wasMoved = false; 

    if (target && selectedPiece->canEliminate(startX, startY, endX, endY, target->getColor())) {
        eliminatedPiece = std::move(target);
        wasPieceEliminated = true;
    } else if (target) { //Caso da peça target ser da mesma cor da peça selecionada
        return {false, false, nullptr};
    }
    if((selectedPiece->isValidMovement(startX, startY, endX, endY) || wasPieceEliminated)){
        matrix[endX][endY] = std::move(matrix[startX][startY]);
        wasMoved = true;
        selectedPiece->onMove();
        if(selectedPiece->needsPromotion(endX))
            emit promotionRequired(endX, endY, selectedPiece->getColor()); 
        
    }
    return {wasMoved, wasPieceEliminated, eliminatedPiece};
}

std::vector<std::pair<int, int>> Board::getValidMoves(int startX, int startY){
    std::shared_ptr<BasePiece> piece = getPieceAt(startX, startY);
    std::vector<std::pair<int, int>> validMoves;

    if (!piece) return validMoves;

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if(isPathClear(startX, startY, row, col)){
                auto target = matrix[row][col];
                if(target && piece->canEliminate(startX, startY, row, col, target->getColor())){
                    validMoves.emplace_back(row,col);
                }
                else if(!target && piece->isValidMovement(startX, startY, row, col)){
                    validMoves.emplace_back(row, col);
                }
            }
        }
    }
    return validMoves;
}

bool Board::isPathClear(int startX, int startY, int endX, int endY){
    if(getPieceAt(startX, startY)->canJump()) return true;
    int deltaX = endX - startX;
    int deltaY = endY - startY;

    int stepX = (deltaX == 0) ? 0 : (deltaX > 0 ? 1 : -1);
    int stepY = (deltaY == 0) ? 0 : (deltaY > 0 ? 1 : -1);

    int x = startX + stepX;
    int y = startY + stepY;

    while (x != endX || y != endY) {
        if (matrix[x][y] != nullptr) { 
            return false;     
        }
        x += stepX;
        y += stepY;
    }

    return true; 
}

bool Board::isInCheck(Colors kingColor) {
    std::pair<int, int> kingPos = findKingPos(kingColor);
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            auto target = matrix[row][col];
            if (target && target->getColor() != kingColor && target->canEliminate(row, col, kingPos.first, kingPos.second, kingColor)) {
                if (isPathClear(row, col, kingPos.first, kingPos.second)) {
                    return true; 
                }
            }
        }
    }
    return false; 
}

bool Board::willMoveCauseACheck(int startX, int startY, int endX, int endY) {
    auto selectedPiece = matrix[startX][startY];
    auto target = matrix[endX][endY];
    
    matrix[endX][endY] = selectedPiece;
    matrix[startX][startY] = nullptr;
    
    bool check = isInCheck(selectedPiece->getColor());

    matrix[startX][startY] = selectedPiece;
    matrix[endX][endY] = target;

    return check;
}

std::pair<int, int>Board::findKingPos(Colors kingColor){
    std::pair<int, int> kingPos;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            auto piece = matrix[row][col];
            if (piece && piece->getColor() == kingColor && std::dynamic_pointer_cast<King>(piece)) {
                kingPos = std::make_pair(row, col);
                return kingPos;
            }
        }
    }
    return std::make_pair(-1, -1);
}

bool Board::isCheckMate(Colors kingColor){
    if(!isInCheck(kingColor)){
        return false;
    }

    return !doesKingHaveMoves(kingColor) && !hasAValidMove(kingColor);;
}

bool Board::doesKingHaveMoves(Colors kingColor){
    auto kingPos = findKingPos(kingColor);
    auto validMoves = getValidMoves(kingPos.first, kingPos.second);
    for (const auto& move : validMoves) {
        if (!willMoveCauseACheck(kingPos.first, kingPos.second, move.first, move.second)) {
            return true; 
        }
    }
    return false;
}

bool Board::hasAValidMove(Colors kingColor){
    for(int row = 0; row < 8; row++){
        for(int col = 0; col < 8; col++){
            auto piece = matrix[row][col];
            if(piece && piece->getColor() == kingColor){
                auto validMoves = getValidMoves(row, col);
                for (const auto& move : validMoves) {
                    if (!willMoveCauseACheck(row, col, move.first, move.second)) {
                        return true; 
                    }
                }
            }
        }
    }
    return false;
}

bool Board::isStalemate(Colors kingColor){
    return !isInCheck(kingColor) && !hasAValidMove(kingColor);

}