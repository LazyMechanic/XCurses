#include <XCurses/System/CoreConfig.h>

namespace xcur {
const CoreConfig CoreConfig::Default;

CoreConfig::CoreConfig() :
    terminalSize(120, 50),
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
	const Vector2u& terminalSize,
	uint32_t inputDelay,
    bool enableCBreakMode,
    bool enableEchoMode,
    bool enableRawMode,
    bool enableNewLineMode,
    bool enableKeypadMode,
    bool enableInputDelay
) :
    terminalSize(terminalSize),
    inputDelay(inputDelay),
    enableCBreakMode(enableCBreakMode),
    enableEchoMode(enableEchoMode),
    enableRawMode(enableRawMode),
    enableNewLineMode(enableNewLineMode),
    enableKeypadMode(enableKeypadMode),
    enableInputDelay(enableInputDelay)
{
}
}
