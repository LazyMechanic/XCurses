#include <PDCurses/curses.h>

#include <XCurses/Window.h>
#include <XCurses/Container.h>

namespace xcur {
Window::Window() :
    m_backgroundChar(' '),
    m_border(Border::Default)
{
}

Window::~Window()
{
    delwin(m_win);
}


void Window::update(const float dt)
{
	/* full virtual func */
}

void Window::setBorder(const Border& border)
{
    m_border = border;
}

Border Window::getBorder() const
{
    return m_border;
}

_win* Window::getCursesWin() const
{
    return m_win;
}

Object::Ptr<Window> Window::getSharedFromThis()
{
    return std::enable_shared_from_this<Window>::shared_from_this();
}

void Window::draw()
{
    // Clear the window
    wclear(m_win);
    // Draw border
	drawCursesBorder();
}

void Window::addChar(const Char& ch) const
{
    waddch(m_win, ch.toCursesChar());
}

void Window::addChar(const Char& ch, const Vector2u& pos) const
{
    mvwaddch(m_win, pos.y, pos.x, ch.toCursesChar());
}

void Window::setCursorPosition(const Vector2u& newPos) const
{
    wmove(m_win, newPos.y, newPos.x);
}

uint32_t Window::getCursorPositionX() const
{
	return getcurx(m_win);
}

uint32_t Window::getCursorPositionY() const
{
	return getcury(m_win);
}

Vector2u Window::getCursorPosition() const
{
    return Vector2u(getCursorPositionX(), getCursorPositionY());
}

void Window::setPosition(const Vector2u& newPos)
{
	mvwin(m_win, newPos.y, newPos.x);
	m_position = Vector2u(getbegx(m_win), getbegy(m_win));
}

void Window::move(const Vector2u& deltaPos)
{
	setPosition(getPosition() + deltaPos);
}

Status Window::resize(const Vector2u& newSize) const
{
	return wresize(m_win, newSize.y, newSize.x);
}

uint32_t Window::getWidth() const
{
	return getmaxx(m_win);
}

uint32_t Window::getHeight() const
{
	return getmaxy(m_win);
}

Vector2u Window::getSize() const
{
	return Vector2u(getWidth(), getHeight());
}

void Window::drawCursesBorder() const
{
    wborder(m_win,
        m_border.leftSide,
        m_border.rightSide,
        m_border.topSide,
        m_border.bottomSide,
        m_border.topLeftCorner,
        m_border.topRightCorner,
        m_border.bottomLeftCorner,
        m_border.bottomRightCorner);
}
}
