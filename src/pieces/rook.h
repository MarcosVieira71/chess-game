#pragma once

#include "base_piece.h"

class Rook : public BasePiece {
public:
    explicit Rook(Colors pieceColor) : BasePiece(pieceColor) {}

    PieceType getType() const override;
    bool isValidMovement(int startX, int endX, int startY, int endY) override;
    bool canEliminate(int startX, int startY, int endX, int endY, Colors targetColor) override;

};
