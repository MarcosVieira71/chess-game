#include "controller.h"
#include <stdio.h>
#include <iostream>

void Controller::initializeGame() {
    board->clearBoard();
    board->setupBoard();
    showPieces();
    QObject::connect(view, &BoardWidget::squareClicked, this, &Controller::handleMouseClick);
}

void Controller::showPieces(){
    for(int row = 0; row < 8; row++){
        for(int col = 0; col < 8; col++){
            std::shared_ptr<BasePiece> piece = board->getPieceAt(row, col);
            if(piece) view->updateSquares(row, col, piece);
        }
    }
}

void Controller::handleMouseClick(int row, int col) {
    isSelectingPiece ? attemptMovement(row, col) : selectBoardSquare(row, col);
}

void Controller::selectBoardSquare(int row, int col){
    auto piece = board->getPieceAt(row, col);
    QColor redColor = QColor(255, 0, 0, 128);
    QColor blueColor = QColor(0, 0, 255, 128);

    if (piece && piece->getColor() == currentPlayer) {
        isSelectingPiece = true;
        selectedSquare = {row, col};
        view->highlightSquare(row, col, blueColor);
        highlightValidMoves(row, col);
        return;
    } 
    view->highlightSquare(row, col, redColor);
}

void Controller::attemptMovement(int row, int col){
    auto [moveSucceeded, pieceEliminated, eliminatedPiece] = board->movePiece(selectedSquare.first, selectedSquare.second, row, col);
    if (moveSucceeded) {
        if (pieceEliminated) view->removePiece(eliminatedPiece);
        view->updateSquares(row, col, board->getPieceAt(row, col));
        nextTurn(); 
        checkGameOver();
        
    }
    isSelectingPiece = false;
    return;
}

void Controller::nextTurn(){
    currentPlayer = (currentPlayer == Colors::White) ? Colors::Black : Colors::White;
}

void Controller::highlightValidMoves(int row, int col){
    for (const auto& move : board->getValidMoves(row, col)) {
        auto target = board->getPieceAt(move.first, move.second);
        QColor highlightColor = (!target) ? blueColor : redColor;
        if(board->willMoveCauseACheck(row, col, move.first, move.second)){
            highlightColor = redColor;
        }
        view->highlightSquare(move.first, move.second, highlightColor); 
    }
}

void Controller::checkGameOver(){
    QString state;
    if(board->isCheckMate(currentPlayer)){
        state = (currentPlayer == Colors::White) ? "Black wins!" : "White wins!";
        emit gameOver(state);
    }
    else if(board->isStalemate(currentPlayer)){
        state = "Draw!";
        emit gameOver(state);
    }
}
