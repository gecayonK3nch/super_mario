#include "qt_full_box.hpp"

using biv::QtFullBox;

QtFullBox::QtFullBox(const Coord& top_left, const int width, const int height, UIFactory* ui_factory)
    : FullBox(top_left, width, height, ui_factory),
      QtUIObjectRectAdapter(top_left, width, height, QColor(255, 215, 0)) // Gold
{
}

void QtFullBox::update_graphics() {
    if (is_active_) {
        item->setBrush(QColor(255, 215, 0)); // Gold
    } else {
        item->setBrush(QColor(139, 69, 19)); // SaddleBrown
    }
    QtUIObjectRectAdapter::update_graphics();
}

