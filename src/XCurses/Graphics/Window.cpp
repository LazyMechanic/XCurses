#include <XCurses/Graphics/Window.h>

#include <algorithm>

#include <XCurses/System/Context.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
Object::Ptr<Window> Window::create()
{
    return Window::create(Area(Vector2i::Zero, Vector2i::Zero), nullptr, nullptr);
}

Object::Ptr<Window> Window::create(const Area& area)
{
    return Window::create(area, nullptr, nullptr);
}

Object::Ptr<Window> Window::create(const Area& area, Object::Ptr<Container> parent)
{
    return Window::create(area, parent, nullptr);
}

Object::Ptr<Window> Window::create(const Area& area, Object::Ptr<Context> context)
{
    return Window::create(area, nullptr, context);
}

Object::Ptr<Window> Window::create(const Area& area,
    Object::Ptr<Container> parent,
    Object::Ptr<Context> context)
{
    std::shared_ptr<Window> result(new Window(area, parent, context));
    result->add(result->m_title);
    result->add(result->m_border);
    return result;
}

Window::Window() :
    Window(Area(Vector2i::Zero, Vector2i::Zero), nullptr, nullptr)
{
}

Window::Window(const Area& area) :
    Window(area, nullptr, nullptr)
{
}

Window::Window(const Area& area, Object::Ptr<Container> parent) :
    Window(area, parent, nullptr)
{
}

Window::Window(const Area& area, Object::Ptr<Context> context) :
    Window(area, nullptr, context)
{
}

Window::Window(const Area& area, Object::Ptr<Container> parent, Object::Ptr<Context> context) :
    Container(area, parent, context),
    m_backgroundChar(' '),
    m_border(Border::create()),
    m_title(Title::create(Vector2i(2, 0)))
{
}

void Window::addChar(const Char& ch, const Vector2i& position) const
{
    auto context = getContext();
    // If context exists
    if (context != nullptr) {
        if (m_area.contain(position))
        {
            context->addToVirtualScreen(shared_from_this(), ch, position);
        }
    }
}

void Window::addString(const String& str, const Vector2i& position) const
{
    auto context = getContext();
    // If context exists
    if (context != nullptr) {
        Vector2i nextPosition = position;
        // Pass through string and add all character if position is correct
        for (auto& ch : str) {
            if (m_area.contain(nextPosition))
            {
                context->addToVirtualScreen(shared_from_this(), ch, nextPosition);
                nextPosition += Vector2i(1, 0);
            }
            else {
                break;
            }
        }
    }
}

void Window::setBackground(const Char& ch)
{
    m_backgroundChar = ch;
}

Char Window::getBackground() const
{
    return m_backgroundChar;
}

void Window::setBorder(Object::Ptr<Border> border)
{
    remove(m_border);
    add(border);
    m_border = border;
}

Object::Ptr<Border> Window::getBorder() const
{
    return m_border;
}

void Window::setTitle(Object::Ptr<Title> title)
{
    remove(m_title);
    add(title);
    m_title = title;
}

Object::Ptr<Title> Window::getTitle() const
{
    return m_title;
}
}
