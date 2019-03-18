#include <XCurses/System/CursesConfig.h>

namespace xcur {
const CursesConfig CursesConfig::Default;

CursesConfig::CursesConfig() :
    terminalSize(120, 50),
    inputDelay(0),
    isCBreakEnable(true),
    isEchoEnable(false),
    isRawEnable(true),
    isNewLineEnable(false),
    isKeypadEnable(false),
    isInputDelayEnable(false),
    isInit(false),
    isStop(true)
{
}

CursesConfig::CursesConfig(
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
    isCBreakEnable(enableCBreakMode),
    isEchoEnable(enableEchoMode),
    isRawEnable(enableRawMode),
    isNewLineEnable(enableNewLineMode),
    isKeypadEnable(enableKeypadMode),
    isInputDelayEnable(enableInputDelay),
    isInit(false),
    isStop(true)
{
}
}
