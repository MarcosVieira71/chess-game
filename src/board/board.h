#pragma once

#include <array>
#include <memory>
#include <tuple>
#include <vector>
#include <QObject>

#include "pieces/base_piece.h"
#include "pieces/pawn.h"
#include "pieces/king.h"
#include "pieces/queen.h"
#include "pieces/bishop.h"
#include "pieces/knight.h"
#include "pieces/rook.h"

class Board: public QObject{
    Q_OBJECT
public:
    void clearBoard();
    void setupBoard();
    void replacePiece(int row, int col, std::shared_ptr<BasePiece> newPiece);
    bool willMoveCauseACheck(int startX, int startY, int endX, int endY);
    bool isStalemate(Colors kingColor);
    bool isCheckMate(Colors kingColor);
    std::pair<int, int> findKingPos(Colors kingColor);
    std::shared_ptr<BasePiece> getPieceAt(int row, int col);
    std::vector<std::pair<int, int>> getValidMoves(int startX, int startY);
    std::tuple<bool,bool,std::shared_ptr<BasePiece>> movePiece(int startX, int startY, int endX, int endY);

private:
    bool isPathClear(int startX, int startY, int endX, int endY);
    bool doesKingHaveMoves(Colors kingColor);
    bool hasAValidMove (Colors kingColor);
    bool isInCheck(Colors kingColor);

    std::array<std::array<std::shared_ptr<BasePiece>, 8>, 8> matrix;

signals:
    void promotionRequired(int row, int col, Colors color);

};


