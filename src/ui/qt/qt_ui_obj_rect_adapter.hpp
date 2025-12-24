#pragma once

#include "qt_ui_obj.hpp"
#include "rect.hpp"
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>

namespace biv {
	class QtUIObjectRectAdapter : virtual public Rect, public QtUIObject {
		protected:
			QGraphicsRectItem* item = nullptr;
            QBrush brush;
            QPen pen;

		public:
			QtUIObjectRectAdapter(
				const Coord& top_left, const int width, const int height, QColor color
			);
            virtual ~QtUIObjectRectAdapter();
		
			QGraphicsItem* get_graphics_item() override;
			void update_graphics() override;
	};
}
