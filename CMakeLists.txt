cmake_minimum_required(VERSION 3.25)
project(cells_live)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML
        COMPONENTS
        system window graphics network audio
        REQUIRED
        )

add_executable(cells_live main.cpp)

target_link_libraries(cells_live sfml-graphics sfml-audio)