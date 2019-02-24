#include <XCurses/Widget.h>

#include <XCurses/Window.h>
#include <XCurses/Container.h>

namespace xcur {
Widget::~Widget()
{
	// If widget has context ptr
	if (getContext() != nullptr) {
		getContext()->remove(shared_from_this());
	}
}

void Widget::update(float dt)
{
	/* full virtual func */
}

void Widget::draw()
{
	/* full virtual func */
}

void Widget::setParent(Object::Ptr<Container> parent)
{
	m_parent = parent;
}

Object::Ptr<Container> Widget::getParent() const
{
	return m_parent.lock();
}
}
