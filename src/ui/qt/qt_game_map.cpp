#include "qt_game_map.hpp"

using biv::QtGameMap;

QtGameMap::QtGameMap(const int height, const int width) : GameMap(height, width) {
    if (!QApplication::instance()) {
        static int argc = 1;
        static char arg0[] = "super_mario_qt";
        static char* argv[] = { arg0, nullptr };
        app = new QApplication(argc, argv);
    } else {
        app = qobject_cast<QApplication*>(QApplication::instance());
    }

    scene = new QGraphicsScene(0, 0, width, height);
    scene->setBackgroundBrush(Qt::black); 

    view = new QGraphicsView(scene);
    view->scale(20, 20); 
    view->setWindowTitle("Super Mario Qt");
    view->resize(1200, 600); 
    view->show();
}

QtGameMap::~QtGameMap() {
    delete view;
    delete scene;
}

void QtGameMap::add_obj(QtUIObject* obj) {
    objs.push_back(obj);
    scene->addItem(obj->get_graphics_item());
}

void QtGameMap::remove_obj(QtUIObject* obj) {
    for (auto it = objs.begin(); it != objs.end(); ++it) {
        if (*it == obj) {
            objs.erase(it);
            break;
        }
    }
    scene->removeItem(obj->get_graphics_item());
}

void QtGameMap::clear() noexcept {
}

void QtGameMap::refresh() noexcept {
    for (auto obj : objs) {
        obj->update_graphics();
    }
    QApplication::processEvents();
}

void QtGameMap::remove_objs() {
    for (auto obj : objs) {
        scene->removeItem(obj->get_graphics_item());
    }
    objs.clear();
}

void QtGameMap::show() const noexcept {
    QApplication::processEvents();
}
