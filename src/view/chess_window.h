#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QWidget>

#include "controller/controller.h"
#include "board_widget.h"

class ChessWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ChessWindow(QWidget* parent = nullptr);
    virtual ~ChessWindow(); 
    void resetGame();

private:
    void displayGameOverMessage(QString message);
    BoardWidget* chessBoard;
    std::unique_ptr<Controller> controller;
};

