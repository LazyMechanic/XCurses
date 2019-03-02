#include <XCurses/System/Input.h>

#include <XCurses/Text/Char.h>

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
