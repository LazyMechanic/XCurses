#include <XCurses/Graphics/Widget.h>

#include <XCurses/System/Context.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
Widget::Widget() :
    Widget(Area(Vector2i::Zero, Vector2i::Zero), nullptr, nullptr)
{
}

Widget::Widget(const Area& area) :
    Widget(area, nullptr, nullptr)
{
}

Widget::Widget(const Area& area, Object::Ptr<Container> parent) :
    Widget(area, parent, nullptr)
{
}

Widget::Widget(const Area& area, Object::Ptr<Context> context) :
    Widget(area, nullptr, context)
{
}

Widget::Widget(const Area& area, Object::Ptr<Container> parent, Object::Ptr<Context> context) :
    m_area(area),
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

void Widget::toFront()
{
    if (getParent() != nullptr) {
        getParent()->widgetToFront(shared_from_this());
    }
}

void Widget::setArea(const Area& area)
{
    setPosition(area.position);
    setSize(area.size);
}

Area Widget::getArea() const
{
    return m_area;
}

void Widget::setPosition(const Vector2i& position)
{
    m_area.position = position;
}

void Widget::move(const Vector2i& deltaPos)
{
    setPosition(getPosition() + deltaPos);
}

Vector2i Widget::getPosition() const
{
    return m_area.position;
}

void Widget::setSize(const Vector2i& size)
{
    m_area.size = size;
}

Vector2i Widget::getSize() const
{
    return m_area.size;
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

bool Widget::isIntoVisibleArea(const Vector2i& point) const
{
    auto parent = getParent();
    if (parent != nullptr) {
        return parent->isIntoVisibleArea(shared_from_this(), point);
    }
    else {
        return false;
    }
}
}
