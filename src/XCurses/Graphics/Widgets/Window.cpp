#include <XCurses/Graphics/Widgets/Window.h>

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
    drawBorders();
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

void Window::drawBorders() const
{
    auto context = getContext();
    if (context != nullptr) {
        // Draw verticals
        Vector2u topSidePosition = Vector2u::Zero;
        Vector2u bottomSidePosition = Vector2u(0, std::max<uint32_t>(static_cast<int32_t>(m_size.y) - 1, 0));

        for (uint32_t i = 1; i <= m_size.x; ++i) {
            topSidePosition.x = i;
            bottomSidePosition.x = i;
            context->addToVirtualScreen(shared_from_this(), m_border.topSide, topSidePosition);
            context->addToVirtualScreen(shared_from_this(), m_border.bottomSide, bottomSidePosition);
        }

        // Draw horizontals
        Vector2u leftSidePosition = Vector2u::Zero;
        Vector2u rightSidePosition = Vector2u(std::max<uint32_t>(static_cast<int32_t>(m_size.x) - 1, 0), 0);

        for (uint32_t i = 1; i <= m_size.y; ++i) {
            leftSidePosition.y = i;
            rightSidePosition.y = i;
            context->addToVirtualScreen(shared_from_this(), m_border.leftSide, leftSidePosition);
            context->addToVirtualScreen(shared_from_this(), m_border.rightSide, rightSidePosition);
        }

        // Draw corners
        Vector2u topLeftCornerPosition = Vector2u::Zero;
        Vector2u topRightCornerPosition = Vector2u(std::max<uint32_t>(static_cast<int32_t>(m_size.x) - 1, 0), 0);
        Vector2u bottomLeftCornerPosition = Vector2u(0, std::max<uint32_t>(static_cast<int32_t>(m_size.y) - 1, 0));
        Vector2u bottomRightCornerPosition = Vector2u(std::max<uint32_t>(static_cast<int32_t>(m_size.x) - 1, 0), std::max<uint32_t>(m_size.y - 1, 0));

        context->addToVirtualScreen(shared_from_this(), m_border.topLeftCorner, topLeftCornerPosition);
        context->addToVirtualScreen(shared_from_this(), m_border.topRightCorner, topRightCornerPosition);
        context->addToVirtualScreen(shared_from_this(), m_border.bottomLeftCorner, bottomLeftCornerPosition);
        context->addToVirtualScreen(shared_from_this(), m_border.bottomRightCorner, bottomRightCornerPosition);
    }
}
}
