#pragma once

#include "board/board.h"
#include "view/board_widget.h"

class Controller: public QObject{
    Q_OBJECT

public:
    Controller(Board* board, BoardWidget* view)
    : board(board), view(view), currentPlayer(Colors::White), 
      selectedX(-1), selectedY(-1), isSelectingPiece(false) {
        initializeGame();
    };
private:

    void initializeGame();
    void showPieces();
    void handleMouseClick(int x, int y);
    void attemptMovement(int row, int col);
    void highlightValidMoves(int row, int col);
    void selectBoardSquare(int row, int col);
    void nextTurn();
    void gameOver();

private:
    Board* board;           
    const QColor blueColor = QColor(0, 0, 255, 128);
    const QColor redColor = QColor(255, 0, 0, 128);
    BoardWidget* view;      
    Colors currentPlayer;   
    int selectedX, selectedY; 
    bool isSelectingPiece;
    std::pair<int, int> selectedSquare;
};