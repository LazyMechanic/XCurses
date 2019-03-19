#include <XCurses/Graphics/Container.h>

#include <algorithm>

#include <XCurses/System/Context.h>

namespace xcur {
Object::Ptr<Container> Container::create()
{
    return Container::create(Vector2u::Zero, Vector2u::Zero, nullptr, nullptr);
}

Object::Ptr<Container> Container::create(const Vector2u& position, const Vector2u& size)
{
    return Container::create(position, position, nullptr, nullptr);
}

Object::Ptr<Container> Container::create(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent)
{
    return Container::create(position, position, parent, nullptr);
}

Object::Ptr<Container> Container::create(const Vector2u& position, const Vector2u& size, Object::Ptr<Context> context)
{
    return Container::create(position, position, nullptr, context);
}

Object::Ptr<Container> Container::create(
    const Vector2u& position,
    const Vector2u& size,
    Object::Ptr<Container> parent,
    Object::Ptr<Context> context)
{
    return std::shared_ptr<Container>(new Container(position, size, parent, context));
}

Container::Container(const Vector2u& position, const Vector2u& size) :
    Widget(position, size)
{
}

Container::Container(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent) :
    Widget(position, size, parent)
{
}

Container::Container(const Vector2u& position, const Vector2u& size, Object::Ptr<Context> context) :
    Widget(position, size, context)
{
}

Container::Container(
    const Vector2u& position,
    const Vector2u& size,
    Object::Ptr<Container> parent,
    Object::Ptr<Context> context) :
    Widget(position, size, parent, context)
{
}

Status Container::add(Object::Ptr<Widget> widget)
{
    // If widget has parent already
    if (widget->getParent() != nullptr) {
        return Status::Err;
    }

    widget->setParent(std::dynamic_pointer_cast<Container>(shared_from_this()));
    m_childWidgets.push_back(widget);

    // If container was added in context and has ptr to it
    if (getContext() != nullptr) {
        getContext()->add(widget);
    }

    return Status::Ok;
}

Status Container::remove(Object::Ptr<Widget> widget)
{
    auto widgetIt = find(widget);
    // If widget not found
    if (widgetIt == m_childWidgets.end()) {
        return Status::Err;
    }

    m_childWidgets.erase(widgetIt);

    // If container was added in context and has ptr to it
    if (getContext() != nullptr) {
        getContext()->remove(widget);
    }

    return Status::Ok;
}

bool Container::has(Object::Ptr<Widget> widget)
{
    return find(widget) != m_childWidgets.end();
}

void Container::widgetToFront(Object::Ptr<Widget> widget)
{
    auto foundWidget = find(widget);
    // If widget found
    if (foundWidget != end()) {
        m_childWidgets.splice(m_childWidgets.end(), m_childWidgets, foundWidget);
        if (getContext() != nullptr) {
            getContext()->widgetToFront(widget);
        }
    }
}

std::list<Object::Ptr<Widget>>::const_iterator Container::begin() const
{
    return m_childWidgets.begin();
}

std::list<Object::Ptr<Widget>>::const_iterator Container::end() const
{
    return m_childWidgets.end();
}

std::list<Object::Ptr<Widget>>::const_reverse_iterator Container::rbegin() const
{
    return m_childWidgets.rbegin();
}

std::list<Object::Ptr<Widget>>::const_reverse_iterator Container::rend() const
{
    return m_childWidgets.rend();
}

std::list<Object::Ptr<Widget>>::const_iterator Container::find(Object::Ptr<Widget> widget) const
{
    return std::find_if(
        m_childWidgets.begin(),
        m_childWidgets.end(),
        [&widget](const Object::Ptr<Widget>& checkWidget) {
        return widget == checkWidget;
    });
}
}
