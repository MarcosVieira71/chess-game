#pragma once

#include "pieces/base_piece.h"

#include <map>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPixmap>
#include <QString>
#include <string>
#include <utility>

class BoardWidget : public QWidget {
    Q_OBJECT

public:
    virtual ~BoardWidget(); 
    explicit BoardWidget(QWidget* parent = nullptr);
    void updateSquares(int row, int col, BasePiece* piece);
    void highlightSquare(int row, int col, const QColor& color);


protected:
    void initImgMap();
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override; 

private:
    void drawBoard(QPainter& painter);
    void drawPieces(QPainter& painter);
    void drawHighlightedSquares(QPainter& painter);


    std::map<BasePiece*, std::pair<int, int>> squaresUpdate;
    std::map<Colors, std::map<PieceType, std::string>> piecesImages; 
    std::map<std::pair<int, int>, QColor> highlightedSquares;
    static constexpr int boardSize = 8; 
    int squareSize; 

signals:
    void squareClicked(int row, int col);
};

