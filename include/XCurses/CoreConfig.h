#pragma once

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
         * \param _terminalWidth Terminal width
         * \param _terminalHeight Terminal height
         * \param _inputDelay Delay value for input
         * \param _enableCBreakMode CBreak mode state
         * \param _enableEchoMode Echo mode state
         * \param _enableRawMode Raw mode state
         * \param _enableNewLineMode NewLine mode state
         * \param _enableKeypadMode Keypad mode state
         * \param _enableInputDelay Delay mode state
         */
        CoreConfig(
            unsigned int _terminalWidth,
            unsigned int _terminalHeight,
            unsigned int _inputDelay,
            bool _enableCBreakMode,
            bool _enableEchoMode,
            bool _enableRawMode,
            bool _enableNewLineMode,
            bool _enableKeypadMode,
            bool _enableInputDelay
        );

        static const CoreConfig Default;   //< Default predefined config

        /**
         * \brief Terminal width
         */
        unsigned int terminalWidth;

        /**
         * \brief Terminal height
         */
        unsigned int terminalHeight;

        /**
         * \brief Delay value for input
         */
        unsigned int inputDelay;

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