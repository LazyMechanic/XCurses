#include <XCurses/Graphics/Widget.h>

#include <XCurses/Graphics/Window.h>
#include <XCurses/Graphics/Container.h>

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

void Widget::setPosition(const Vector2u& newPos)
{
	m_position = newPos;
}

void Widget::move(const Vector2u& deltaPos)
{
	setPosition(getPosition() + deltaPos);
}

uint32_t Widget::getPositionX() const
{
	return m_position.x;
}

uint32_t Widget::getPositionY() const
{
	return m_position.y;
}

Vector2u Widget::getPosition() const
{
	return m_position;
}

void Widget::toFront()
{
    if (getParent() != nullptr) {
        getParent()->widgetToFront(shared_from_this());
    }
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
