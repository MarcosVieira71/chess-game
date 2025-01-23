#pragma once

#include "base_piece.h"

class King : public BasePiece {
public:
    explicit King(Colors pieceColor) : BasePiece(pieceColor) {}

    PieceType getType() const override;
    bool isValidMovement(int startX, int endX, int startY, int endY) override;
};
