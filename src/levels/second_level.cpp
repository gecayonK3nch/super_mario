#include "second_level.hpp"

#include "third_level.hpp"

using biv::SecondLevel;

SecondLevel::SecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool SecondLevel::is_final() const noexcept {
	return false;
}

biv::GameLevel* SecondLevel::get_next() {
	if (!next) {
		clear_data();
		next = new biv::ThirdLevel(ui_factory);
	}
	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void SecondLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
	
	ui_factory->create_ship({20, 25}, 40, 2);
	ui_factory->create_ship({60, 20}, 10, 7);
	ui_factory->create_ship({80, 25}, 20, 2);
	ui_factory->create_ship({120, 20}, 10, 7);
	ui_factory->create_ship({150, 25}, 40, 2);

	// Boxes and obstacles
	ui_factory->create_box({30, 15}, 5, 3);
	ui_factory->create_full_box({40, 15}, 5, 3);
	ui_factory->create_box({50, 15}, 5, 3);

	ui_factory->create_full_box({85, 15}, 5, 3);
	ui_factory->create_box({90, 15}, 5, 3);

	ui_factory->create_box({160, 15}, 5, 3);
	ui_factory->create_full_box({170, 15}, 5, 3);
	ui_factory->create_box({180, 15}, 5, 3);

	// Final ship (Exit)
	ui_factory->create_ship({210, 20}, 10, 7);

	// Enemies
	ui_factory->create_enemy({30, 23}, 3, 2);
	ui_factory->create_enemy({160, 23}, 3, 2);

	// New enemies
	ui_factory->create_flying_enemy({70, 10}, 3, 2);
	ui_factory->create_flying_enemy({130, 10}, 3, 2);
	
	ui_factory->create_jumping_enemy({90, 23}, 3, 2);
	ui_factory->create_jumping_enemy({170, 23}, 3, 2);

	// Money
	ui_factory->create_money({30, 10}, 2, 2);
	ui_factory->create_money({50, 10}, 2, 2);
	ui_factory->create_money({90, 10}, 2, 2);
	ui_factory->create_money({170, 10}, 2, 2);
}
