cmake_minimum_required(VERSION 3.25)
project(cells_live)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML
        COMPONENTS
        system window graphics network audio
        REQUIRED
        )

if (NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif ()

add_executable(
        cells_live
        main.cpp
        interface/components/button/Button.cpp
        game/Game.cpp
        interface/menus/main/MainMenu.cpp
        interface/screen/Screen.cpp
        interface/menus/Menu.cpp
        interface/components/button/template/ButtonTemplate.cpp
        interface/menus/game/GameMenu.cpp
        game/config/GameConfig.cpp game/field/GameField.cpp
        game/cell/Cell.cpp internal/renderable/Renderable.cpp
        game/config/cell/CellConfig.cpp
        game/cell/color_scheme/ColorScheme.cpp
        game/cell/color_scheme/energy/EnergyColorScheme.cpp
        game/config/field/FieldConfig.cpp
        game/cell/alive/AliveCell.cpp
        game/field/neighbors/NeighborsField.cpp
)

target_link_libraries(cells_live sfml-graphics sfml-audio spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)