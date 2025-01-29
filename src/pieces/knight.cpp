#include "knight.h"
#include <cmath>

PieceType Knight::getType() const{
    return PieceType::Knight;
}

bool Knight::isValidMovement(int startX, int startY, int endX, int endY) {    
    int deltaX = abs(endX - startX);
    int deltaY = abs(endY - startY);
    
    return (deltaX == 2 && deltaY == 1) || (deltaX == 1 && deltaY == 2);
}

bool Knight::canEliminate(int startX, int startY, int endX, int endY, Colors targetColor) {
    return isValidMovement(startX, startY, endX, endY) && targetColor != this->color;
}