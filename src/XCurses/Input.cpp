#include <XCurses/Input.h>

#include <XCurses/Char.h>

#include <PDCurses/curses.h>

namespace xcur {
Char Input::m_pressedChar(ERR);

void Input::handleEvents(const Window::Ptr<>& window)
{
	if (window == nullptr) {
		m_pressedChar = Char::Err;
		return;
	}

	m_pressedChar = static_cast<uint16_t>(wgetch(window->getCursesWin()));
}

Char Input::getPressedKey()
{
	return m_pressedChar;
}
}
