#include <QDebug>
#include <iostream> 

#include "board_widget.h"


BoardWidget::BoardWidget(QWidget* parent)
    : QWidget(parent), squareSize(75){
    setMinimumSize(boardSize * squareSize, boardSize * squareSize); 
    initImgMap();
    
}

void BoardWidget::initImgMap() {
    std::array<PieceType, 6> piecesTypes = {
        PieceType::King,  PieceType::Knight,
        PieceType::Queen, PieceType::Bishop,
        PieceType::Pawn,  PieceType::Rook
    };

    std::array<Colors, 2> colors = {Colors::White, Colors::Black};
    std::array<std::string, 6> pieceNames = {"king", "knight", "queen", "bishop", "pawn", "rook"};

    std::string basePath = "src/pieces/assets/";

    for (int i = 0; i < 2; i++) {
        std::string colorPath = (i == 0) ? "white/white-" : "black/black-";
        std::map<PieceType, QPixmap> coloredPiecesImgMap;

        for (int j = 0; j < 6; j++) {
            std::string imgPath = basePath + colorPath + pieceNames[j] + ".png";

            QPixmap imgPng(QString::fromStdString(imgPath));

            QPixmap scaledImg = imgPng.scaled(squareSize, squareSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            coloredPiecesImgMap[piecesTypes[j]] = scaledImg;
        }

        piecesImages[colors[i]] = coloredPiecesImgMap;
    }
}


void BoardWidget::paintEvent(QPaintEvent* event){
    QPainter painter(this);

    drawBoard(painter);
    drawPieces(painter);
    drawHighlightedSquares(painter);
    highlightedSquares.clear(); 
}

void BoardWidget::drawHighlightedSquares(QPainter& painter){
    for (const auto& square : highlightedSquares){
        int row = square.first.first;
        int col = square.first.second;
        QRect squareRect(col * squareSize, row * squareSize, squareSize, squareSize);

        painter.setBrush(square.second); 
        painter.setPen(Qt::NoPen);             
        painter.drawRect(squareRect); 
    }
}


void BoardWidget::drawBoard(QPainter& painter){
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {
            QRect square(col * squareSize, row * squareSize, squareSize, squareSize);
            painter.setBrush((row + col) % 2 == 0 ? Qt::white : Qt::gray);
            painter.drawRect(square);
        }
    }
}

void BoardWidget::updateSquares(int row, int col, std::shared_ptr<BasePiece> piece){
    auto pos = std::make_pair(row, col);

    std::weak_ptr<BasePiece> weakPiece = piece; 
    squaresUpdate[weakPiece] = pos;
    update();
}


void BoardWidget::drawPieces(QPainter& painter){
    for(auto squares: squaresUpdate){
        auto piece = squares.first.lock();
        
        if (!piece) continue;
        
        auto position = squares.second;
        auto row = position.first;
        auto col = position.second;
        QRect square(col * squareSize, row * squareSize, squareSize, squareSize);
        
        auto color = piece->getColor();
        auto type = piece->getType();
        auto imgMap = piecesImages[color];
        auto scaledImg = imgMap[type];

        painter.drawPixmap(square.topLeft(), scaledImg);
    }
}

void BoardWidget::removePiece(std::shared_ptr<BasePiece> piece) {
    auto it = squaresUpdate.find(piece);
    if (it != squaresUpdate.end()) {
        squaresUpdate.erase(it); 
    }
}


void BoardWidget::highlightSquare(int row, int col, const QColor& color){
    highlightedSquares[std::make_pair(row, col)] = color; 
    update();
}

void BoardWidget::mousePressEvent(QMouseEvent* event){
    int row = event->y() / squareSize;
    int col = event->x() / squareSize;
    emit squareClicked(row, col);

}
void BoardWidget::clearBoard() {
    squaresUpdate.clear();
    update(); 
}


BoardWidget::~BoardWidget() {}
