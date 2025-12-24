#include "qt_ui_factory.hpp"

using biv::QtUIFactory;

QtUIFactory::QtUIFactory(Game* game) : UIFactory(game) {
    create_game_map();
}

void QtUIFactory::clear_data() {
    game->remove_objs();
    game_map->remove_objs();
    
    delete mario;
    mario = nullptr;
    
    for(auto p : boxes) delete p; boxes.clear();
    for(auto p : full_boxes) delete p; full_boxes.clear();
    for(auto p : ships) delete p; ships.clear();
    for(auto p : enemies) delete p; enemies.clear();
    for(auto p : flying_enemies) delete p; flying_enemies.clear();
    for(auto p : jumping_enemies) delete p; jumping_enemies.clear();
    for(auto p : moneys) delete p; moneys.clear();
}

void QtUIFactory::create_box(const Coord& top_left, const int width, const int height) {
    QtBox* box = new QtBox(top_left, width, height);
    boxes.push_back(box);
    game->add_map_movable(box);
    game->add_static_obj(box);
    game_map->add_obj(box);
}

void QtUIFactory::create_enemy(const Coord& top_left, const int width, const int height) {
    QtEnemy* enemy = new QtEnemy(top_left, width, height);
    enemies.push_back(enemy);
    game->add_map_movable(enemy);
    game->add_movable(enemy);
    game->add_collisionable(enemy);
    game_map->add_obj(enemy);
}

void QtUIFactory::create_flying_enemy(const Coord& top_left, const int width, const int height) {
    QtFlyingEnemy* enemy = new QtFlyingEnemy(top_left, width, height);
    flying_enemies.push_back(enemy);
    game->add_map_movable(enemy);
    game->add_movable(enemy);
    game->add_collisionable(enemy);
    game_map->add_obj(enemy);
}

void QtUIFactory::create_jumping_enemy(const Coord& top_left, const int width, const int height) {
    QtJumpingEnemy* enemy = new QtJumpingEnemy(top_left, width, height);
    jumping_enemies.push_back(enemy);
    game->add_map_movable(enemy);
    game->add_movable(enemy);
    game->add_collisionable(enemy);
    game_map->add_obj(enemy);
}

void QtUIFactory::create_full_box(const Coord& top_left, const int width, const int height) {
    QtFullBox* box = new QtFullBox(top_left, width, height, this);
    full_boxes.push_back(box);
    game->add_map_movable(box);
    game->add_collisionable(box);
    game->add_static_obj(box);
    game_map->add_obj(box);
}

void QtUIFactory::create_mario(const Coord& top_left, const int width, const int height) {
    mario = new QtMario(top_left, width, height);
    game->add_mario(mario);
    game->add_movable(mario);
    game->add_collisionable(mario);
    game_map->add_obj(mario);
}

void QtUIFactory::create_money(const Coord& top_left, const int width, const int height) {
    QtMoney* money = new QtMoney(top_left, width, height);
    moneys.push_back(money);
    game->add_map_movable(money);
    game->add_movable(money);
    game->add_collisionable(money);
    game_map->add_obj(money);
}

void QtUIFactory::create_ship(const Coord& top_left, const int width, const int height) {
    QtShip* ship = new QtShip(top_left, width, height);
    ships.push_back(ship);
    game->add_map_movable(ship);
    game->add_static_obj(ship);
    game_map->add_obj(ship);
}

biv::GameMap* QtUIFactory::get_game_map() {
    return game_map;
}

biv::Mario* QtUIFactory::get_mario() {
    return mario;
}

void QtUIFactory::create_game_map() {
    game_map = new QtGameMap(30, 120);
}
