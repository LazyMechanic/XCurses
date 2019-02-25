#include <PDCurses/curses.h>

#include <XCurses/Window.h>
#include <XCurses/Container.h>
#include <XCurses/HasWindow.h>

namespace xcur {
Window::Window()
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
    // Draw widgets
	m_rootWindowContainer->draw();
}

void Window::updateCursesBorder() const
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
