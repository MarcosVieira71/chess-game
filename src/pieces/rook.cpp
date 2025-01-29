#include "rook.h"
#include <iostream>
PieceType Rook::getType() const{
    return PieceType::Rook;
}

bool Rook::isValidMovement(int startX, int startY, int endX, int endY){
    if (endY == startY){
        return startX + direction * 7 <= endX || startX - direction * 7 <= endX;
    }
    if (endX == startX){
        return startY + direction * 7 <= endY || startY - direction * 7 <= endY;
    }
}

bool Rook::canEliminate(int startX, int startY, int endX, int endY, Colors targetColor){
    return isValidMovement(startX, startY, endX, endY) && targetColor != this->color;
}