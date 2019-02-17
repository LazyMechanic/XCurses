#include <PDCurses/curses.h>

#include <XCurses/Window.h>
#include <XCurses/Container.h>

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
