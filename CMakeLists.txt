cmake_minimum_required(VERSION 3.10)

project(vieiraChess)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

include_directories(${CMAKE_SOURCE_DIR}/src)

set(SOURCES
    src/main.cpp
    src/pieces/bishop.cpp
    src/pieces/king.cpp
    src/pieces/knight.cpp
    src/pieces/pawn.cpp
    src/pieces/queen.cpp
    src/pieces/rook.cpp
    src/view/chess_window.cpp
    src/view/board_widget.cpp
)

set(HEADERS
    src/pieces/base_piece.h
    src/pieces/bishop.h
    src/pieces/king.h
    src/pieces/knight.h
    src/pieces/pawn.h
    src/pieces/queen.h
    src/pieces/rook.h
    src/view/chess_window.h
    src/view/board_widget.h
)

add_executable(vieiraChess ${SOURCES} ${HEADERS})

target_link_libraries(vieiraChess Qt5::Core Qt5::Gui Qt5::Widgets)