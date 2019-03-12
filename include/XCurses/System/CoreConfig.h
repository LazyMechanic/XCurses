#pragma once

#include <cstdint>

#include <XCurses/System/Vector2.h>

namespace xcur {
/**
 * \brief Config of core
 */
class CoreConfig
{
public:
    /**
     * \brief Default config constructor
     */
    CoreConfig();

    /**
     * \brief Construct config with specific params
     * \param terminalSize Terminal size
     * \param inputDelay Delay value for input
     * \param enableCBreakMode CBreak mode state
     * \param enableEchoMode Echo mode state
     * \param enableRawMode Raw mode state
     * \param enableNewLineMode NewLine mode state
     * \param enableKeypadMode Keypad mode state
     * \param enableInputDelay Delay mode state
     */
    CoreConfig(
        const Vector2u& terminalSize,
        uint32_t inputDelay,
        bool enableCBreakMode,
        bool enableEchoMode,
        bool enableRawMode,
        bool enableNewLineMode,
        bool enableKeypadMode,
        bool enableInputDelay
    );

    /**
     * \brief Default predefined config
     */
    static const CoreConfig Default;

    /**
     * \brief Terminal size.
     * size.x is width, size.y = height
     */
    Vector2u terminalSize;

    /**
     * \brief Delay value for input
     */
    uint32_t inputDelay;

    /**
     * \brief CBreak mode state
     */
    bool enableCBreakMode;

    /**
     * \brief Echo mode state
     */
    bool enableEchoMode;

    /**
     * \brief Raw mode state
     */
    bool enableRawMode;

    /**
     * \brief NewLine mode state
     */
    bool enableNewLineMode;

    /**
     * \brief Keypad mode state
     */
    bool enableKeypadMode;

    /**
     * \brief Input delay mode state
     */
    bool enableInputDelay;

};
}