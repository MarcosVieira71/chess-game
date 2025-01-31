#pragma once

#include <memory>
#include "board/board.h"
#include "view/board_widget.h"

class Controller: public QObject{
    Q_OBJECT

public:
    Controller(std::unique_ptr<Board> board, BoardWidget* view)
    : board(std::move(board)), view(view), currentPlayer(Colors::White), 
    isSelectingPiece(false) {
        initializeGame();
    };
    void initializeGame();
    
signals:
    void gameOver(QString message);
private:
    void showPieces();
    void handleMouseClick(int x, int y);
    void attemptMovement(int row, int col);
    void highlightValidMoves(int row, int col);
    void selectBoardSquare(int row, int col);
    void nextTurn();
    void checkGameOver();

    std::unique_ptr<Board> board;           
    const QColor blueColor = QColor(0, 0, 255, 128);
    const QColor redColor = QColor(255, 0, 0, 128);
    BoardWidget* view;      
    Colors currentPlayer;   
    bool isSelectingPiece;
    std::pair<int, int> selectedSquare;
};