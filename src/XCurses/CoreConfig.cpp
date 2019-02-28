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
    unsigned terminalWidth,
    unsigned terminalHeight,
    unsigned inputDelay,
    bool enableCBreakMode,
    bool enableEchoMode,
    bool enableRawMode,
    bool enableNewLineMode,
    bool enableKeypadMode,
    bool enableInputDelay
) :
    terminalWidth(terminalWidth),
    terminalHeight(terminalHeight),
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
