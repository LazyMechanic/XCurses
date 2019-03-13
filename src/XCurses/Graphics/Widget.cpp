#include <XCurses/Graphics/Widget.h>

#include <XCurses/Graphics/Window.h>
#include <XCurses/Graphics/Context.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
Object::Ptr<Widget> Widget::create()
{
    return std::shared_ptr<Widget>(new Widget());
}

Widget::Widget() :
    m_position(0, 0),
    m_size(0, 0)
{
}

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

void Widget::setSize(const Vector2u& newSize)
{
    m_size = newSize;
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

void Widget::setContext(Object::Ptr<Context> context)
{
    m_context = context;
}

Object::Ptr<Context> Widget::getContext() const
{
    return m_context.lock();
}
}
