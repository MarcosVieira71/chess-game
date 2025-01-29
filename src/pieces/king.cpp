#include "king.h"
#include <stdio.h>

PieceType King::getType() const{
    return PieceType::King;
}

bool King::isValidMovement(int startX, int startY, int endX, int endY){
    int direction = (color == Colors::White) ? 1 : -1; 

    if(endY == startY){
        return startX + direction == endX || startX - direction == endX;
    }
    
    if(endX == startX){
        return startY + direction == endY || startY - direction == endY;
    }

    if(startY + direction == endY){
        return startX + direction == endX || startX - direction == endX;
    }

    if(startY - direction == endY){
        return startX + direction == endX || startX - direction == endX;
    }
    
    return false;
}

bool King::canEliminate(int startX, int startY, int endX, int endY, Colors targetColor){
    return isValidMovement(startX, startY, endX, endY) && targetColor != this->color;
}