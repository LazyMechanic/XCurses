#pragma once

#include <XCurses/System/Object.h>

namespace xcur {
class Char;
class Window;

class Input
{
public:
    /**
     * \brief Update m_pressedChar
     */
    static void handleEvents(Object::Ptr<Window> window);

    /**
     * \brief Get pressed key
     * \return Character (key value) if key pressed, Err if doesn't
     */
    static Char getPressedKey();

private:
    /**
     * \brief Stored pressed char
     */
    static Char m_pressedChar;
};
}