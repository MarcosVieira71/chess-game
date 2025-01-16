#include <QApplication>

int main(void) {
    QApplication app(argc, argv);

    // Modelo (tabuleiro de xadrez).
    Board board;
    board.initialize();

    // Janela principal (visualização).
    ChessWindow window(board);
    window.setWindowTitle("Jogo de Xadrez");
    window.show();

    return app.exec();
}