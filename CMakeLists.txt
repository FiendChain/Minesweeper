cmake_minimum_required(VERSION 3.0)

project("Minesweeper")

set(SRC_DIR ${CMAKE_SOURCE_DIR}/source)
set(APP_DIR ${SRC_DIR}/App)

include_directories(${SRC_DIR} ${APP_DIR})

set(APP_FILES
    ${APP_DIR}/App.cpp
    ${APP_DIR}/Camera/Camera.cpp
    ${APP_DIR}/Camera/ControllableCamera.cpp
    ${APP_DIR}/ResourceManager/ResourceManager.cpp
    ${APP_DIR}/Utility/FpsCounter/FpsCounter.cpp)

add_library(App ${APP_FILES})
target_compile_options(App PUBLIC -std=c++17 -O3 -pthread)
target_link_libraries(App sfml-graphics sfml-audio sfml-window sfml-system)

add_executable(main ${SRC_DIR}/main.cpp)
target_link_libraries(main App)