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

Status Window::addChar(uint32_t ch, int x, int y)
{
	return mvaddch(y, x, ch);
}

Status Window::setBorder(const Border& border)
{
	m_border = border;
	return wborder(
		m_win,
		border.leftSide,
		border.rightSide,
		border.topSide,
		border.bottomSide,
		border.topLeftCorner,
		border.topRightCorner,
		border.bottomLeftCorner,
		border.bottomRightCorner
	);
}

Status Window::setBorder(
	uint32_t leftSide,
	uint32_t rightSide,
	uint32_t topSide,
	uint32_t bottomSide,
	uint32_t topLeftCorner,
	uint32_t topRightCorner,
	uint32_t bottomLeftCorner,
	uint32_t bottomRightCorner
)
{
	return this->setBorder(Border(
		leftSide,
		rightSide,
		topSide,
		bottomSide,
		topLeftCorner,
		topRightCorner,
		bottomLeftCorner,
		bottomRightCorner
	));
}

Status Window::refresh() const
{
	return wrefresh(m_win);
}
}