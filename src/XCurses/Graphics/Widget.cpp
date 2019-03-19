#include <XCurses/Graphics/Widget.h>

#include <XCurses/Graphics/Context.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
Widget::Widget() :
    m_position(Vector2u::Zero),
    m_size(Vector2u::Zero)
{
}

Widget::Widget(const Vector2u& position, const Vector2u& size) :
    m_position(position),
    m_size(size)
{
}

Widget::Widget(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent) :
    m_position(position),
    m_size(size),
    m_parent(parent)
{
}

Widget::Widget(const Vector2u& position, const Vector2u& size, Object::Ptr<Context> context) :
    m_position(position),
    m_size(size),
    m_context(context)
{
}

Widget::Widget(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent, Object::Ptr<Context> context) :
    m_position(position),
    m_size(size),
    m_parent(parent),
    m_context(context)
{
}

Widget::~Widget()
{
    // If widget has context ptr
    if (getContext() != nullptr) {
        getContext()->remove(shared_from_this());
    }
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

uint32_t Widget::getWidth() const
{
    return m_size.x;
}

uint32_t Widget::getHeight() const
{
    return m_size.y;
}

Vector2u Widget::getSize() const
{
    return m_size;
}

void Widget::setParent(Object::Ptr<Container> parent)
{
    m_parent = parent;
}

Object::Ptr<Container> Widget::getParent() const
{
    return m_parent.lock();
}

void Widget::setContext(Object::Ptr<Context> context)
{
    m_context = context;
}

Object::Ptr<Context> Widget::getContext() const
{
    return m_context.lock();
}
}
