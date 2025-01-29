#include "pawn.h"
#include <stdio.h>

PieceType Pawn::getType() const{
    return PieceType::Pawn;
};
        
bool Pawn::isValidMovement(int startX, int startY, int endX, int endY) {
    int direction = (color == Colors::White) ? 1 : -1; 
    if (endY == startY && endX == startX + direction) {
        return true;
    }
    
    if (endY == startY && endX == startX + direction * 2 && isFirstMove){
        isFirstMove = false;
        return true;
    }
    
    return false;
}

bool Pawn::canEliminate(int startX, int startY, int endX, int endY, Colors targetColor){
    return true;
}