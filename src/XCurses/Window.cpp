#include <PDCurses/curses.h>

#include <XCurses/Window.h>

namespace xcur {
Window::Window()
{
}

Window::Window(const Window&)
{
}

Window::Window(Window&&)
{
}

Window::~Window()
{
	delwin(m_win);
}

void Window::draw()
{
	wnoutrefresh(m_win);
}
}