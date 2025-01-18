#pragma once

#include <utility>

enum class PieceType{
    Pawn,
    Rook, 
    Knight,
    Bishop,
    Queen, 
    King
};

enum class Colors{
    White,
    Black
};

class BasePiece{
    public:
        explicit BasePiece(Colors pieceColor) : color(pieceColor) {}
        virtual ~BasePiece() {};
        virtual PieceType getType() const = 0;
        virtual bool isValidMovement(int startX, int endX, int startY, int endY) = 0;

    protected:
        Colors color;
};