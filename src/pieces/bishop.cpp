#include "bishop.h"

PieceType Bishop::getType() const{
    return PieceType::Bishop;
};
        
bool Bishop::isValidMovement(int startX, int startY, int endX, int endY) {
    int deltaX = endX - startX;
    int deltaY = endY - startY;
    return abs(deltaX) == abs(deltaY);
}

bool Bishop::canEliminate(int startX, int startY, int endX, int endY, Colors targetColor){
    return isValidMovement(startX, startY, endX, endY) && targetColor != this->color;
}