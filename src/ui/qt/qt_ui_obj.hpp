#pragma once

#include <QGraphicsItem>

namespace biv {
	class QtUIObject {
		public:
			virtual QGraphicsItem* get_graphics_item() = 0;
			virtual void update_graphics() = 0;
	};
}
