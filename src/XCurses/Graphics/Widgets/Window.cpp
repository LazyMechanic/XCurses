#include <XCurses/Graphics/Widgets/Window.h>

#include <algorithm>

#include <XCurses/Graphics/Context.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
Object::Ptr<Window> Window::create()
{
    return Window::create(Vector2u::Zero, Vector2u::Zero, nullptr, nullptr);
}

Object::Ptr<Window> Window::create(const Vector2u& position, const Vector2u& size)
{
    return Window::create(position, size, nullptr, nullptr);
}

Object::Ptr<Window> Window::create(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent)
{
    return Window::create(position, size, parent, nullptr);
}

Object::Ptr<Window> Window::create(const Vector2u& position, const Vector2u& size, Object::Ptr<Context> context)
{
    return Window::create(position, size, nullptr, context);
}

Object::Ptr<Window> Window::create(
    const Vector2u& position,
    const Vector2u& size,
    Object::Ptr<Container> parent,
    Object::Ptr<Context> context)
{
    std::shared_ptr<Window> result(new Window(position, size, parent, context));
    result->add(result->m_title);
    result->add(result->m_border);
    return result;
}

Window::Window() :
    Window(Vector2u::Zero, Vector2u::Zero, nullptr, nullptr)
{
}

Window::Window(const Vector2u& position, const Vector2u& size) :
    Window(position, size, nullptr, nullptr)
{
}

Window::Window(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent) :
    Window(position, size, parent, nullptr)
{
}

Window::Window(const Vector2u& position, const Vector2u& size, Object::Ptr<Context> context) :
    Window(position, size, nullptr, context)
{
}

Window::Window(
    const Vector2u& position,
    const Vector2u& size,
    Object::Ptr<Container> parent,
    Object::Ptr<Context> context) :
    Container(position, size, parent, context),
    m_backgroundChar(' '),
    m_border(Border::create()),
    m_title(Title::create(Vector2u(2, 0)))
{
}

void Window::resize(const Vector2u& newSize)
{
    m_size = newSize;
}

void Window::addChar(const Char& ch, const Vector2u& position) const
{
    auto context = getContext();
    // If context exists
    if (context != nullptr) {
        Vector2u availableArea = getAvailableArea();
        if (position.x < availableArea.x && 
            position.y < availableArea.y)
        {
            context->addToVirtualScreen(shared_from_this(), ch, position);
        }
    }
}

void Window::addString(const String& str, const Vector2u& position) const
{
    auto context = getContext();
    // If context exists
    if (context != nullptr) {
        Vector2u availableArea = getAvailableArea();
        Vector2u nextPosition = position;
        // Pass through string and add all character if position is correct
        for (auto& ch : str) {
            if (nextPosition.x < availableArea.x &&
                nextPosition.y < availableArea.y)
            {
                context->addToVirtualScreen(shared_from_this(), ch, nextPosition);
                nextPosition += Vector2u(1, 0);
            }
            else {
                break;
            }
        }
    }
}

Vector2u Window::getAvailableArea() const
{
    Vector2u result = Vector2u::Zero;
    if (m_size.x > 2) {
        result.x = m_size.x - 2;
    }
    if (m_size.y > 2) {
        result.y = m_size.y - 2;
    }

    return result;
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
