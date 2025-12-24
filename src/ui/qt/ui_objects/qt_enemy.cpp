#include "qt_enemy.hpp"

using biv::QtEnemy;

QtEnemy::QtEnemy(const Coord& top_left, const int width, const int height)
    : Enemy(top_left, width, height),
      QtUIObjectRectAdapter(top_left, width, height, Qt::green)
{
}
