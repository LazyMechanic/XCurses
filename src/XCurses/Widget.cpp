#include <XCurses/Widget.h>

#include <XCurses/Window.h>
#include <XCurses/Container.h>

namespace xcur {
Widget::~Widget()
{
    if (getParentWidget() != nullptr) {
		getParentWidget()->remove(shared_from_this());
    }
}

Object::Ptr<Container> Widget::getParentWidget() const
{
	return m_parentWidget.lock();
}

Object::Ptr<Window> Widget::getParentWindow() const
{
	return m_parentWindow.lock();
}
}
