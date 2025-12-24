#include "qt_flying_enemy.hpp"

using biv::QtFlyingEnemy;

QtFlyingEnemy::QtFlyingEnemy(const Coord& top_left, const int width, const int height)
    : FlyingEnemy(top_left, width, height),
      QtUIObjectRectAdapter(top_left, width, height, Qt::blue)
{
}
