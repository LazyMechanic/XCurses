#include <XCurses/System/Input.h>

#include <XCurses/Text/Char.h>

#include <PDCurses/curses.h>

namespace xcur {
Char Input::m_pressedChar(ERR);

void Input::handleEvents(Object::Ptr<Window> window)
{
    if (window == nullptr) {
        m_pressedChar = wgetch(stdscr);
    }
    else {
        
    }
}

Char Input::getPressedKey()
{
    return m_pressedChar;
}
}
