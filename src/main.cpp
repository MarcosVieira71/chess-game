#include <QApplication>
#include "view/chess_window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv); // Inicializa o QApplication

    ChessWindow window;
    window.setWindowTitle("Jogo de Xadrez");
    window.show();

    return app.exec(); // Inicia o loop de eventos
}