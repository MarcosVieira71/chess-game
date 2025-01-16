cmake_minimum_required(VERSION 3.10)

project(vieiraChess)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5 REQUIRED COMPONENTS Core Gui)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(SOURCES
    src/main.cpp
    src/pieces/BasePiece.cpp
    src/pieces/Bishop.cpp
    src/pieces/King.cpp
    src/pieces/Knight.cpp
    src/pieces/Pawn.cpp
    src/pieces/Queen.cpp
    src/pieces/Rook.cpp
)

set(HEADERS
    src/pieces/BasePiece.h
    src/pieces/Bishop.h
    src/pieces/King.h
    src/pieces/Knight.h
    src/pieces/Pawn.h
    src/pieces/Queen.h
    src/pieces/Rook.h
)

add_executable(vieiraChess ${SOURCES} ${HEADERS})

target_link_libraries(vieiraChess Qt5::Core Qt5::Gui)