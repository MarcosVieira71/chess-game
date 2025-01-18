#pragma once

#include <QMainWindow>
#include "controller/controller.h"
#include "board_widget.h"

class ChessWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ChessWindow(QWidget* parent = nullptr);
    virtual ~ChessWindow(); 

private:
    Controller* controller;
    BoardWidget* chessBoard;
};

