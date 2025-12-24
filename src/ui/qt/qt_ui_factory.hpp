#pragma once

#include "ui_factory.hpp"
#include "qt_game_map.hpp"
#include "ui_objects/qt_box.hpp"
#include "ui_objects/qt_enemy.hpp"
#include "ui_objects/qt_flying_enemy.hpp"
#include "ui_objects/qt_jumping_enemy.hpp"
#include "ui_objects/qt_full_box.hpp"
#include "ui_objects/qt_mario.hpp"
#include "ui_objects/qt_money.hpp"
#include "ui_objects/qt_ship.hpp"

namespace biv {
    class QtUIFactory : public UIFactory {
    private:
        QtGameMap* game_map = nullptr;
        QtMario* mario = nullptr;
        
        std::vector<QtBox*> boxes;
        std::vector<QtFullBox*> full_boxes;
        std::vector<QtShip*> ships;
        std::vector<QtEnemy*> enemies;
        std::vector<QtFlyingEnemy*> flying_enemies;
        std::vector<QtJumpingEnemy*> jumping_enemies;
        std::vector<QtMoney*> moneys;

    public:
        QtUIFactory(Game* game);
        
        void clear_data() override;
        void create_box(const Coord& top_left, const int width, const int height) override;
        void create_enemy(const Coord& top_left, const int width, const int height) override;
        void create_flying_enemy(const Coord& top_left, const int width, const int height) override;
        void create_jumping_enemy(const Coord& top_left, const int width, const int height) override;
        void create_full_box(const Coord& top_left, const int width, const int height) override;
        void create_mario(const Coord& top_left, const int width, const int height) override;
        void create_money(const Coord& top_left, const int width, const int height) override;
        void create_ship(const Coord& top_left, const int width, const int height) override;
        
        GameMap* get_game_map() override;
        Mario* get_mario() override;
        
    protected:
        void create_game_map() override;
    };
}
