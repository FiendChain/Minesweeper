cmake_minimum_required(VERSION 3.0)

project("SFML App")

set(SFML_LIB sfml-graphics sfml-audio sfml-window sfml-system)
set(APP_DIR .)

set(APP_FILES
    ${APP_DIR}/App.cpp
    ${APP_DIR}/Camera/Camera.cpp
    ${APP_DIR}/Camera/ControllableCamera.cpp
    ${APP_DIR}/ResourceManager/ResourceManager.cpp
    ${APP_DIR}/Utility/FpsCounter/FpsCounter.cpp)

add_library(App ${APP_FILES})
target_compile_options(App PUBLIC -std=c++17 -O3 -pthread)
target_link_libraries(App ${SFML_LIB})
target_include_directories(App ${APP_DIR})