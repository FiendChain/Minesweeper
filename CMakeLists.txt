cmake_minimum_required(VERSION 3.0)

project("Minesweeper Game")

set(SRC_DIR ${CMAKE_SOURCE_DIR}/source)
set(APP_DIR ${SRC_DIR}/App)
set(MINESWEEPER_DIR ${SRC_DIR}/Minesweeper)

set(SFML_LIB sfml-graphics sfml-audio sfml-window sfml-system)

include_directories(${SRC_DIR} ${APP_DIR} ${MINESWEEPER_DIR})

add_subdirectory(${APP_DIR})
add_subdirectory(${MINESWEEPER_DIR})

add_executable(main ${SRC_DIR}/main.cpp)
target_link_libraries(main App minesweeper ${SFML_LIB})