#include <XCurses/System/Input.h>

#include <XCurses/Text/Char.h>

#include <PDCurses/curses.h>

namespace xcur {
Char Input::m_pressedChar(ERR);

void Input::handleEvents(Object::Ptr<VirtualScreen> screen)
{
    if (screen != nullptr) {
        m_pressedChar = wgetch(stdscr);
    }
    else {
        m_pressedChar = Char::Err;
    }
}

Char Input::getPressedKey()
{
    return m_pressedChar;
}
}
