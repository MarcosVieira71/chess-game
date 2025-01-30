#pragma once

#include "base_piece.h"

class Knight : public BasePiece {
public:
    explicit Knight(Colors pieceColor) : BasePiece(pieceColor) {}

    PieceType getType() const override;
    bool isValidMovement(int startX, int endX, int startY, int endY) override;
    bool canEliminate(int startX, int startY, int endX, int endY, Colors targetColor) override;
    bool canJump() override;
};
