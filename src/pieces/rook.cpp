#include "rook.h"
#include <iostream>
PieceType Rook::getType() const{
    return PieceType::Rook;
}

bool Rook::isValidMovement(int startX, int startY, int endX, int endY){
    return startX == endX || startY == endY;

}

bool Rook::canEliminate(int startX, int startY, int endX, int endY, Colors targetColor){
    return isValidMovement(startX, startY, endX, endY) && targetColor != this->color;
}