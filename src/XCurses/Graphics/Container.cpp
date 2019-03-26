#include <XCurses/Graphics/Container.h>

#include <algorithm>
#include <stdexcept>

#include <XCurses/System/Context.h>

namespace xcur {
Object::Ptr<Container> Container::create()
{
    return Container::create(Area(Vector2i::Zero, Vector2i::Zero), nullptr, nullptr);
}

Object::Ptr<Container> Container::create(const Area& area)
{
    return Container::create(area, nullptr, nullptr);
}

Object::Ptr<Container> Container::create(const Area& area, Object::Ptr<Container> parent)
{
    return Container::create(area, parent, nullptr);
}

Object::Ptr<Container> Container::create(const Area& area, Object::Ptr<Context> context)
{
    return Container::create(area, nullptr, context);
}

Object::Ptr<Container> Container::create(const Area& area, Object::Ptr<Container> parent, Object::Ptr<Context> context)
{
    return std::shared_ptr<Container>(new Container(area, parent, context));
}

Container::Container(const Area& area) :
    Container(area, nullptr, nullptr)
{
}

Container::Container(const Area& area, Object::Ptr<Container> parent) :
    Container(area, parent, nullptr)
{
}

Container::Container(const Area& area, Object::Ptr<Context> context) :
    Container(area, nullptr, context)
{
}

Container::Container(const Area& area, Object::Ptr<Container> parent, Object::Ptr<Context> context) :
    Widget(area, parent, context)
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

bool Container::isIntoVisibleArea(Object::PtrConst<Widget> widget, const Vector2i& point) const
{
    if (widget == nullptr) {
        throw std::runtime_error("Widget pointer is nullptr");
    }

    Vector2i endPoint = point + widget->getPosition();
    auto parent = getParent();
    if (parent != nullptr) {
        return m_area.contain(endPoint) && parent->isIntoVisibleArea(shared_from_this(), endPoint);
    }
    else {
        return m_area.contain(endPoint);
    }
}
}
