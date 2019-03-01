#pragma once

#include <XCurses/Window.h>

namespace xcur {
class Char;

class Input
{
public:
    /**
     * \brief Update m_pressedChar
     */
    static void handleEvents();

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