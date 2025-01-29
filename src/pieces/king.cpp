#include "king.h"
#include <stdio.h>

PieceType King::getType() const{
    return PieceType::King;
}

bool King::isValidMovement(int startX, int startY, int endX, int endY){
    return abs(endX - startX) <= 1 && abs(endY - startY) <= 1;
}

bool King::canEliminate(int startX, int startY, int endX, int endY, Colors targetColor){
    return isValidMovement(startX, startY, endX, endY) && targetColor != this->color;
}