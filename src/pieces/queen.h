#pragma once

#include "base_piece.h"

class Queen : public BasePiece {
public:
    explicit Queen(Colors pieceColor) : BasePiece(pieceColor) {}

    PieceType getType() const override;
    bool isValidMovement(int startX, int endX, int startY, int endY) override;
};