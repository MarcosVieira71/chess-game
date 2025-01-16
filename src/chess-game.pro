
TEMPLATE = app
TARGET = ChessGame

QT += core gui

INCLUDEPATH += $$PWD/src

SOURCES +=  $$PWD/src/main.cpp \
            $$PWD/src/pieces/BasePiece.cpp \
            $$PWD/src/pieces/Bishop.cpp \
            $$PWD/src/pieces/King.cpp \
            $$PWD/src/pieces/Knight.cpp \
            $$PWD/src/pieces/Pawn.cpp \
            $$PWD/src/pieces/Queen.cpp \
            $$PWD/src/pieces/Rook.cpp

HEADER +=   $$PWD/src/pieces/BasePiece.h \
            $$PWD/src/pieces/Bishop.h \
            $$PWD/src/pieces/King.h \
            $$PWD/src/pieces/Knight.h \
            $$PWD/src/pieces/Pawn.h \
            $$PWD/src/pieces/Queen.h \
            $$PWD/src/pieces/Rook.h


LIBS += -lQt5Core -lQt5Gui
