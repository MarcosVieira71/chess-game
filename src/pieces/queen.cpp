#include "queen.h"

PieceType Queen::getType() const{
    return PieceType::Queen;
}

bool Queen::isValidMovement(int startX, int startY, int endX, int endY){    
    int deltaX = endX - startX;
    int deltaY = endY - startY;
    return (startX == endX || startY == endY) || abs(deltaX) == abs(deltaY);
}

bool Queen::canEliminate(int startX, int startY, int endX, int endY, Colors targetColor){
    return isValidMovement(startX, startY, endX, endY) && targetColor != this->color;
}