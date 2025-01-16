#include "BasePiece.h"

class Rook : public BasePiece{
    
     void move(int startX, int endX, int startY, int endY) override;
};