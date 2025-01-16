#include "BasePiece.h"

class Knight : public BasePiece{
    public:
    
    void move(int startX, int endX, int startY, int endY) override;
    
};

