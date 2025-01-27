#include <QApplication>
#include "view/chess_window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ChessWindow window;
    window.setWindowTitle("Jogo de Xadrez");
    window.show();

    return app.exec(); 
}