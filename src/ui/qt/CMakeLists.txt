find_package(Qt6 REQUIRED COMPONENTS Widgets)

target_sources(${PROJECT_NAME} PRIVATE
    qt_game_map.cpp
    qt_ui_factory.cpp
    qt_ui_obj_rect_adapter.cpp
    ui_objects/qt_box.cpp
    ui_objects/qt_enemy.cpp
    ui_objects/qt_flying_enemy.cpp
    ui_objects/qt_full_box.cpp
    ui_objects/qt_jumping_enemy.cpp
    ui_objects/qt_mario.cpp
    ui_objects/qt_money.cpp
    ui_objects/qt_ship.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
