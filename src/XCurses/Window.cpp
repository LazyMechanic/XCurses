#include <PDCurses/curses.h>

#include <XCurses/Window.h>
#include <XCurses/Container.h>

namespace xcur {
Window::Window() :
	m_cursorPosition(0, 0)
{
}

Window::~Window()
{
	delwin(m_win);
}


void Window::update(const float dt)
{
}

void Window::setBorder(const Border& border)
{
	m_border = border;
	updateCursesBorder();
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
	updateCursesBorder();
}

void Window::addChar(const Char& ch)
{
}

void Window::addChar(const Char& ch, const Position& pos)
{
}

Position Window::getCursorPosition() const
{
	return m_cursorPosition;
}

void Window::updateCursesBorder()
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
