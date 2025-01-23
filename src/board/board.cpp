#include "board.h"

//REI BRANCO NA CASA PRETA 
//REI PRETO NA CASA BRANCAAA
void Board::clearBoard(void) {
    for (int row = 0; row < 8; row++) { 
        for (int col = 0; col < 8; col++) {  
            matrix[row][col] = nullptr;  
        }
    }
}


void Board::setupBoard(){
    Colors colors[] = { Colors::White, Colors::Black };

    for(int row = 0; row < 2; row++ ){

        matrix[0 + row*7][0] = new Rook(colors[row]);
        matrix[0 + row*7][1] = new Knight(colors[row]);
        matrix[0 + row*7][2] = new Bishop(colors[row]);
        matrix[0 + row*7][3] = new King(colors[row]);
        matrix[0 + row*7][4] = new Queen(colors[row]);
        matrix[0 + row*7][5] = new Bishop(colors[row]);
        matrix[0 + row*7][6] = new Knight(colors[row]);
        matrix[0 + row*7][7] = new Rook(colors[row]);
        
        for(int col = 0; col < 8; col++){
            matrix[1 + 5*row][col] = new Pawn(colors[row]);
        }

    }
}

BasePiece* Board::getPieceAt(int row, int col){
    return matrix[row][col];
}


bool Board::movePiece(int startX, int startY, int endX, int endY){

}