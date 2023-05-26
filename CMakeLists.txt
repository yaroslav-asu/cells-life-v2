cmake_minimum_required(VERSION 3.25)
project(cells_live)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML
        COMPONENTS
        system window graphics network audio
        REQUIRED
        )

add_executable(
        cells_live
        main.cpp
        interface/components/button/button.cpp
        game/game.cpp
        interface/menus/main/main_menu.cpp
        interface/screen/screen.cpp
        interface/menus/menu.cpp
        interface/components/button/template/button_template.cpp
        interface/menus/game/game_menu.cpp
        game/config/game_config.cpp game/field/game_field.cpp
)

target_link_libraries(cells_live sfml-graphics sfml-audio)