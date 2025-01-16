#include "BasePiece.h"

BasePiece::~BasePiece(){};

void BasePiece::setPos(int x, int y){
    _posX = x;
    _posY = y;
}

std::pair<int, int> BasePiece::getPos(void){
    return {_posX, _posY};
}