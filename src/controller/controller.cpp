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
    auto piece = board->getPieceAt(row, col);

    if (isSelectingPiece) {
        auto [moveSucceeded, pieceEliminated, eliminatedPiece] = board->movePiece(selectedSquare.first, selectedSquare.second, row, col);
        
        if (moveSucceeded) {
            if (pieceEliminated) view->removePiece(eliminatedPiece);
            view->updateSquares(row, col, board->getPieceAt(row, col));
            currentPlayer = (currentPlayer == Colors::White) ? Colors::Black : Colors::White;
        }

        isSelectingPiece = false;
        return;
    }

    if (piece && piece->getColor() == currentPlayer) {
        isSelectingPiece = true;
        selectedSquare = {row, col};
        view->highlightSquare(row, col, QColor(0, 0, 255, 128));
        for (const auto& move : board->getValidMoves(row, col)) {
            auto target = board->getPieceAt(move.first, move.second);
            QColor highlightColor = (!target) ? QColor(0, 255, 0, 128) : QColor(255, 0, 0, 128);
            view->highlightSquare(move.first, move.second, highlightColor); 
        }
        return;
    } 
    view->highlightSquare(row, col, QColor(255, 0, 0, 128));
}