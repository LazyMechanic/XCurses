#pragma once

#include <cstdint>

namespace xcur {
class CoreConfig
{
public:
    /**
     * \brief Default config constructor
     */
    CoreConfig();

    /**
     * \brief Construct config with specific params
     * \param terminalWidth Terminal width
     * \param terminalHeight Terminal height
     * \param inputDelay Delay value for input
     * \param enableCBreakMode CBreak mode state
     * \param enableEchoMode Echo mode state
     * \param enableRawMode Raw mode state
     * \param enableNewLineMode NewLine mode state
     * \param enableKeypadMode Keypad mode state
     * \param enableInputDelay Delay mode state
     */
    CoreConfig(
        uint32_t terminalWidth,
		uint32_t terminalHeight,
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
     * \brief Terminal width
     */
    uint32_t terminalWidth;

    /**
     * \brief Terminal height
     */
    uint32_t terminalHeight;

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