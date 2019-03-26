#pragma once

#include <cstdint>

#include <XCurses/System/Vector2.h>

namespace xcur {
/**
 * \brief Config of curses
 */
class CursesConfig
{
public:
    /**
     * \brief Default config constructor
     */
    CursesConfig();

    /**
     * \brief Construct config with specific params
     * \param terminalSize Terminal size
     * \param inputDelay Delay value for input
     * \param isCBreakEnable CBreak mode state
     * \param isEchoEnable Echo mode state
     * \param isRawEnable Raw mode state
     * \param isNewLineEnable NewLine mode state
     * \param isInputDelayEnable Delay mode state
     * \param isKeypadEnable Keypad mode state
     */
    CursesConfig(
        const Vector2i& terminalSize,
        uint32_t inputDelay,
        bool isCBreakEnable,
        bool isEchoEnable,
        bool isRawEnable,
        bool isNewLineEnable,
        bool isInputDelayEnable,
        bool isKeypadEnable
    );

    /**
     * \brief Default predefined config
     */
    static const CursesConfig Default;

    /**
     * \brief Terminal size.
     * size.x is width, size.y = height
     */
    Vector2i terminalSize;

    /**
     * \brief Delay value for input
     */
    uint32_t inputDelay;

    /**
     * \brief CBreak mode state
     */
    bool isCBreakEnable;

    /**
     * \brief Echo mode state
     */
    bool isEchoEnable;

    /**
     * \brief Raw mode state
     */
    bool isRawEnable;

    /**
     * \brief NewLine mode state
     */
    bool isNewLineEnable;

    /**
     * \brief Input delay mode state
     */
    bool isInputDelayEnable;

    /**
     * \brief Keypad mode state
     */
    bool isKeypadEnable;

    /**
     * \brief Curses state. True if Curses::init() was called (equal initscr() in curses)
     */
    bool isInit;

    /**
     * \brief Curses mode state
     */
    bool isStop;
};
}