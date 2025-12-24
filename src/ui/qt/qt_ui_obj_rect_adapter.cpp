#include "qt_ui_obj_rect_adapter.hpp"

using biv::QtUIObjectRectAdapter;

QtUIObjectRectAdapter::QtUIObjectRectAdapter(
	const Coord& top_left, const int width, const int height, QColor color
) : brush(color), pen(Qt::NoPen) {
	this->top_left = top_left;
	this->width = width;
	this->height = height;
    
    item = new QGraphicsRectItem(0, 0, width, height);
    item->setBrush(brush);
    item->setPen(pen);
    update_graphics();
}

QtUIObjectRectAdapter::~QtUIObjectRectAdapter() {
}

QGraphicsItem* QtUIObjectRectAdapter::get_graphics_item() {
    return item;
}

void QtUIObjectRectAdapter::update_graphics() {
    if (item) {
        item->setPos(get_x(), get_y());
    }
}
