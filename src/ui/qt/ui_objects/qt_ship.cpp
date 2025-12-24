#include "qt_ship.hpp"

using biv::QtShip;

QtShip::QtShip(const Coord& top_left, const int width, const int height)
    : Ship(top_left, width, height),
      QtUIObjectRectAdapter(top_left, width, height, Qt::gray)
{
}
