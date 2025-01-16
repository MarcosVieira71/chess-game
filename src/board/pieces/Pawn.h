#include "BasePiece.h"

class Pawn : public BasePiece{
    public:
    
    void move(int startX, int endX, int startY, int endY) override;
    
};

