#include "controller.h"
#include <stdio.h>
#include <iostream>

void Controller::initializeGame() {
    board->clearBoard();
    board->setupBoard();
    for(int row = 0; row < 8; row++){
        for(int col = 0; col < 8; col++){
            std::shared_ptr<BasePiece> piece = board->getPieceAt(row, col);
            if(piece) view->updateSquares(row, col, piece);
        }
    }
    QObject::connect(view, &BoardWidget::squareClicked, this, &Controller::handleMouseClick);
}

void Controller::handleMouseClick(int row, int col) {
    if(isSelectingPiece){
        int startX = selectedSquare.first; 
        int startY = selectedSquare.second;
        
        auto [moveSucceeded, pieceEliminated, eliminatedPiece] = board->movePiece(startX, startY, row, col);
        if(moveSucceeded){
            std::shared_ptr<BasePiece> selectedPiece = board->getPieceAt(row, col);
            if(pieceEliminated){
                view->removePiece(eliminatedPiece);
            }
            view->updateSquares(row, col, selectedPiece);     

            currentPlayer = currentPlayer == Colors::White ? Colors::Black : Colors::White;
        }
        isSelectingPiece = false;
    }
    else{
        std::shared_ptr<BasePiece> piece = board->getPieceAt(row, col);
        QColor color;
        if (piece && piece->getColor() == currentPlayer) {
            isSelectingPiece = true;
            color = QColor(0, 0, 255, 128);
            selectedSquare = {row, col};
        } 
        else {
            isSelectingPiece = false;
            color = QColor(255, 0, 0, 128);
        }
        view->highlightSquare(row, col, color);
    }
}