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
    isInputDelayEnable(false),
    isKeypadEnable(true),
    isInit(false),
    isStop(true)
{
}

CursesConfig::CursesConfig(
    const Vector2i& terminalSize,
    uint32_t inputDelay,
    bool isCBreakEnable,
    bool isEchoEnable,
    bool isRawEnable,
    bool isNewLineEnable,
    bool isInputDelayEnable,
    bool isKeypadEnable
) :
    terminalSize(terminalSize),
    inputDelay(inputDelay),
    isCBreakEnable(isCBreakEnable),
    isEchoEnable(isEchoEnable),
    isRawEnable(isRawEnable),
    isNewLineEnable(isNewLineEnable),
    isInputDelayEnable(isInputDelayEnable),
    isKeypadEnable(isKeypadEnable),
    isInit(false),
    isStop(true)
{
}
}
