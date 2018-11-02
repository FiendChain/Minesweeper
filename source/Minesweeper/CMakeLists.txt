project("Minesweeper")
cmake_minimum_required(VERSION 3.0)

set(SFML_LIB sfml-graphics sfml-audio sfml-window sfml-system)
set(SRC_DIR .)

add_subdirectory(${CMAKE_SOURCE_DIR}/App)

set(SRC_FILES
    ${SRC_DIR}/Mine.cpp
    ${SRC_DIR}/MineField.cpp
    ${SRC_DIR}/Minesweeper.cpp)

add_library(minesweeper ${SRC_FILES})
target_link_libraries(minesweeper App ${SFML_LIB})
target_compile_options(minesweeper PUBLIC -O3 -std=c++17)
target_include_directories(minesweeper PUBLIC ${SRC_DIR})