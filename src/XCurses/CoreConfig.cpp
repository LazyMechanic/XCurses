#include <XCurses/CoreConfig.h>

namespace xcur {
const CoreConfig CoreConfig::Default;

CoreConfig::CoreConfig() :
	terminalWidth(120),
	terminalHeight(50),
	inputDelay(0),
	enableCBreakMode(true),
	enableEchoMode(false),
	enableRawMode(true),
	enableNewLineMode(false),
	enableKeypadMode(false),
	enableInputDelay(false)
{
}

CoreConfig::CoreConfig(
	unsigned _terminalWidth,
    unsigned _terminalHeight,
    unsigned _inputDelay,
    bool _enableCBreakMode,
    bool _enableEchoMode,
    bool _enableRawMode,
    bool _enableNewLineMode,
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
	enableKeypadMode(_enableKeypadMode),
	enableInputDelay(_enableInputDelay)
{
}
}
