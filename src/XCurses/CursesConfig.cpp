#include <XCurses/CursesConfig.h>

namespace xcur {
const CursesConfig CursesConfig::Default;

CursesConfig::CursesConfig() :
	terminalWidth(120),
	terminalHeight(50),
	inputDelay(0),
	enableCBreakMode(true),
	enableEchoMode(false),
	enableRawMode(true),
	enableNewLineMode(false),
	enableColorMode(true),
	enableKeypadMode(false),
	enableInputDelay(false)
{
}

CursesConfig::CursesConfig(
	unsigned _terminalWidth,
    unsigned _terminalHeight,
    unsigned _inputDelay,
    bool _enableCBreakMode,
    bool _enableEchoMode,
    bool _enableRawMode,
    bool _enableNewLineMode,
    bool _enableColorMode,
    bool _enableKeypadMode,
    bool _enableInputDelay
) :
	terminalWidth(_terminalWidth),
	terminalHeight(_terminalHeight),
	inputDelay(_inputDelay),
	enableCBreakMode(_enableCBreakMode),
	enableEchoMode(_enableEchoMode),
	enableRawMode(_enableRawMode),
	enableNewLineMode(_enableNewLineMode),
	enableColorMode(_enableColorMode),
	enableKeypadMode(_enableKeypadMode),
	enableInputDelay(_enableInputDelay)
{
}
}
