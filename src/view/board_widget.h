#pragma once

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class BoardWidget : public QWidget {
    Q_OBJECT

public:
    virtual ~BoardWidget(); 
    explicit BoardWidget(QWidget* parent = nullptr);
    QSize sizeHint() const override; 


protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override; 

private:
    static constexpr int boardSize = 8; 
    int squareSize; 
    void drawBoard(QPainter& painter);
};

