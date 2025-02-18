#pragma once

#include "base_piece.h"

class Pawn : public BasePiece {
public:
    explicit Pawn(Colors pieceColor) : BasePiece(pieceColor) {}

    PieceType getType() const override;
    bool isValidMovement(int startX, int startY, int endX, int endY) override;
    bool canEliminate(int startX, int startY, int endX, int endY,  Colors targetColor) override;
    void onMove() override;
    bool needsPromotion(int endX) override;
    void updateFirstMove(void);

private:
    bool isFirstMove = true;
};
