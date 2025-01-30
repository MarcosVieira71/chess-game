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
        Colors getColor(){return color;}
        virtual ~BasePiece() {};
        virtual PieceType getType() const = 0;
        virtual bool canJump(){return false;}
        virtual bool isValidMovement(int startX, int endX, int startY, int endY) = 0;
        virtual bool canEliminate(int startX, int startY, int endX, int endY, Colors targetColor) = 0;

    protected:
        Colors color;
        int direction = (color == Colors::White) ? 1 : -1; 
};