#include "BasePiece.h"

class Queen : public BasePiece{
    
    void move(int startX, int endX, int startY, int endY) override;
};