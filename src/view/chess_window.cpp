#include <QMessageBox>
#include <QVBoxLayout>
#include <QWidget>
#include "chess_window.h"

ChessWindow::ChessWindow(QWidget* parent)
    : QMainWindow(parent), chessBoard(new BoardWidget(this)),
    controller(std::make_unique<Controller>(std::make_unique<Board>(), chessBoard)){
    setWindowTitle("Chess Game");

    QWidget* borderWidget = new QWidget(this);
    borderWidget->setStyleSheet("background-color: black;");
    QVBoxLayout* borderLayout = new QVBoxLayout(borderWidget);
    borderLayout->setContentsMargins(5, 5, 5, 5);
    borderLayout->addWidget(chessBoard); 
    borderLayout->setSpacing(0); 

    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    layout->addWidget(borderWidget, 0, Qt::AlignCenter);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    connect(controller.get(), &Controller::gameOver, this, &ChessWindow::displayGameOverMessage);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    resize(800, 800);
}


void ChessWindow::displayGameOverMessage(QString message) {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Game Over");
    msgBox.setText(message);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, "New Game");
    msgBox.setButtonText(QMessageBox::No, "Exit");

    int response = msgBox.exec();
    if (response == QMessageBox::Yes) {
        resetGame();
    } else {
        close(); 
    }
}

void ChessWindow::resetGame() {
    chessBoard->clearBoard();
    disconnect(controller.get(), &Controller::gameOver, this, &ChessWindow::displayGameOverMessage);

    controller = std::make_unique<Controller>(std::make_unique<Board>(), chessBoard);
    
    connect(controller.get(), &Controller::gameOver, this, &ChessWindow::displayGameOverMessage);
    
    controller->initializeGame();
}

ChessWindow::~ChessWindow(){}
