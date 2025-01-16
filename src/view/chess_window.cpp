#include <QVBoxLayout>
#include <QWidget>
#include "chess_window.h"

ChessWindow::ChessWindow(QWidget* parent)
    : QMainWindow(parent), chessBoard(new BoardWidget(this)) 
{
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

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    resize(800, 800);
}

ChessWindow::~ChessWindow() {}
