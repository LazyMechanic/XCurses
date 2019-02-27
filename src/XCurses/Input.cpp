#include <XCurses/Input.h>

#include <XCurses/Char.h>

#include <PDCurses/curses.h>

namespace xcur {
Char Input::m_pressedChar(ERR);

void Input::handleEvents()
{

}

Char Input::getPressedKey()
{
    return m_pressedChar;
}
}
