#pragma once

#include <QMainWindow>
#include "board_widget.h"

class ChessWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ChessWindow(QWidget* parent = nullptr);
    virtual ~ChessWindow(); 

private:
    BoardWidget* chessBoard;
};

