#include <XCurses/Graphics/Window.h>

#include <algorithm>

#include <XCurses/Graphics/Context.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
Object::Ptr<Window> Window::create()
{
    return std::shared_ptr<Window>(new Window());
}

Object::Ptr<Window> Window::create(const Vector2u& position, const Vector2u& size)
{
    return std::shared_ptr<Window>(new Window(position, size));
}

Object::Ptr<Window> Window::create(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent)
{
    return std::shared_ptr<Window>(new Window(position, size, parent));
}

Object::Ptr<Window> Window::create(const Vector2u& position, const Vector2u& size, Object::Ptr<Context> context)
{
    return std::shared_ptr<Window>(new Window(position, size, context));
}

Object::Ptr<Window> Window::create(
    const Vector2u& position,
    const Vector2u& size,
    Object::Ptr<Container> parent,
    Object::Ptr<Context> context)
{
    return std::shared_ptr<Window>(new Window(position, size, parent, context));
}

Window::Window() :
    m_size(Vector2u::Zero),
    m_backgroundChar(' '),
    m_border(Border::Default)
{
}

Window::Window(const Vector2u& position, const Vector2u& size) :
    Container(position),
    m_size(size),
    m_backgroundChar(' '),
    m_border(Border::Default)
{
}

Window::Window(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent) :
    Container(position, parent),
    m_size(size),
    m_backgroundChar(' '),
    m_border(Border::Default)
{
}

Window::Window(const Vector2u& position, const Vector2u& size, Object::Ptr<Context> context) :
    Container(position, context),
    m_size(size),
    m_backgroundChar(' '),
    m_border(Border::Default)
{
}

Window::Window(
    const Vector2u& position,
    const Vector2u& size,
    Object::Ptr<Container> parent,
    Object::Ptr<Context> context) :
    Container(position, parent, context),
    m_size(size),
    m_backgroundChar(' '),
    m_border(Border::Default)
{
}

void Window::setBorder(const Border& border)
{
    m_border = border;
}

Border Window::getBorder() const
{
    return m_border;
}

void Window::draw() const
{
    // TODO: Window::draw()
    drawBorders();
}

void Window::resize(const Vector2u& newSize)
{
    m_size = newSize;
}

uint32_t Window::getWidth() const
{
    return m_size.x;
}

uint32_t Window::getHeight() const
{
    return m_size.y;
}

Vector2u Window::getSize() const
{
    return m_size;
}

void Window::setBackground(const Char& ch)
{
    m_backgroundChar = ch;
}

Char Window::getBackground() const
{
    return m_backgroundChar;
}

void Window::drawBorders() const
{

}
}
