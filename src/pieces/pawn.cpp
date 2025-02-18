#include "pawn.h"

PieceType Pawn::getType() const{
    return PieceType::Pawn;
};
        
bool Pawn::isValidMovement(int startX, int startY, int endX, int endY) {
    if (endY == startY && endX == startX + direction) {
        return true;
    }
    
    if (endY == startY && endX == startX + direction * 2 && isFirstMove){
        return true;
    }
    
    return false;
}

void Pawn::updateFirstMove(void){
    isFirstMove = false;
}


bool Pawn::canEliminate(int startX, int startY, int endX, int endY, Colors targetColor){
    if (abs(endY - startY) == 1 && endX == startX + direction && targetColor != color) {
        return true;
    }
    return false;
}

void Pawn::onMove(){
    if(isFirstMove){
        this->updateFirstMove();
    }
}

bool Pawn::needsPromotion(int endX){
    return (color == Colors::White && endX == 7) || 
    (color == Colors::Black && endX == 0);
}
