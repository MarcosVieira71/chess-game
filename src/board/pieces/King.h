#include "BasePiece.h"

class King : public BasePiece{
    public:
    
    void move(int startX, int endX, int startY, int endY) override;
    
};

