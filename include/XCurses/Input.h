#pragma once

#include <XCurses/Window.h>

namespace xcur {
class Char;

class Input
{
public:
	static void handleEvents(const Window::Ptr<>& window);

	static Char getPressedKey();

private:
	static Char m_pressedChar;
};
}