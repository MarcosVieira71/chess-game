#include <QDebug>
#include "board_widget.h"

BoardWidget::BoardWidget(QWidget* parent)
    : QWidget(parent), squareSize(75) 
{
    setMinimumSize(boardSize * squareSize, boardSize * squareSize); 
}

QSize BoardWidget::sizeHint() const {
    return QSize(boardSize * squareSize, boardSize * squareSize);
}

void BoardWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    drawBoard(painter);
}

void BoardWidget::drawBoard(QPainter& painter) {
    
    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            QRect square(col * squareSize, row * squareSize, squareSize, squareSize);
            if ((row + col) % 2 == 0) {
                painter.setBrush(Qt::white);
            } else {
                painter.setBrush(Qt::black);
            }
            painter.drawRect(square);
        }
    }
}

void BoardWidget::mousePressEvent(QMouseEvent* event) {
    int row = event->y() / squareSize;
    int col = event->x() / squareSize;
    qDebug() << "Square clicked:" << row << col;
}

BoardWidget::~BoardWidget() {}

