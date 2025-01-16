#include <utility>

class BasePiece{
    public:
        virtual ~BasePiece();
        virtual void move(int startX, int endX, int startY, int endY) = 0;

        void setPos(int x, int y);
        std::pair<int, int> getPos(void);
        
    private:
        int _posX;
        int _posY;
        char _color;
};