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

    void initializeGame();
    void handleMouseClick(int x, int y);
    void nextTurn();

private:
    Board* board;           
    BoardWidget* view;      
    Colors currentPlayer;   
    int selectedX, selectedY; 
    bool isSelectingPiece;  
};