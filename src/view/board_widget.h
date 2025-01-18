#pragma once

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "pieces/base_piece.h"

class BoardWidget : public QWidget {
    Q_OBJECT

public:
    virtual ~BoardWidget(); 
    explicit BoardWidget(QWidget* parent = nullptr);
    QSize sizeHint() const override; 
    void updateSquare(int row, int col, BasePiece* piece);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override; 

private:
    void drawBoard(QPainter& painter);
    void drawPieces(QPainter& painter);

    static constexpr int boardSize = 8; 
    int squareSize; 


};

