#include <XCurses/System/Curses.h>

#include <stdexcept>

#include <PDCurses/curses.h>

namespace xcur {
CursesConfig Curses::m_config(
    Vector2i::Zero,
    0,
    false,
    false,
    false,
    false,
    false,
    false);

void Curses::init(const CursesConfig& config)
{
    initscr();

    m_config.isStop = false;
    m_config.isInit = true;

    setCBreak(config.isCBreakEnable);
    setEcho(config.isEchoEnable);
    setRaw(config.isRawEnable);
    setNewLine(config.isNewLineEnable);
    setTerminalSize(config.terminalSize);
    setKeypad(config.isKeypadEnable);
    nodelay(stdscr, true);
}

bool Curses::isInit()
{
    return m_config.isInit;
}

void Curses::resume()
{
    // If curses doesn't init
    if (!Curses::isInit()) {
        throw std::runtime_error("Curses didn't initialized");
    }

    doupdate();
    m_config.isStop = false;
}

void Curses::stop()
{
    // If curses doesn't init
    if (!Curses::isInit()) {
        throw std::runtime_error("Curses didn't initialized");
    }

    endwin();
    m_config.isStop = true;
}

bool Curses::isStop()
{
    return m_config.isStop;
}

Status Curses::setCBreak(bool v)
{
    // If curses mode stop
    if (!Curses::isInit()) {
        throw std::runtime_error("Curses didn't initialized");
    }

    m_config.isCBreakEnable = v;
    if (v) {
        return cbreak();
    }
    else {
        return nocbreak();
    }
}

bool Curses::isCBreakEnable()
{
    return m_config.isCBreakEnable;
}

Status Curses::setEcho(bool v)
{
    // If curses mode stop
    if (!Curses::isInit()) {
        throw std::runtime_error("Curses didn't initialized");
    }

    m_config.isEchoEnable = v;
    if (v) {
        return echo();
    }
    else {
        return noecho();
    }
}

bool Curses::isEchoEnable()
{
    return m_config.isEchoEnable;
}

Status Curses::setRaw(bool v)
{
    // If curses mode stop
    if (!Curses::isInit()) {
        throw std::runtime_error("Curses didn't initialized");
    }

    m_config.isRawEnable = v;
    if (v) {
        return raw();
    }
    else {
        return noraw();
    }
}

bool Curses::isRawEnable()
{
    return m_config.isRawEnable;
}

Status Curses::setNewLine(bool v)
{
    // If curses mode stop
    if (!Curses::isInit()) {
        throw std::runtime_error("Curses didn't initialized");
    }

    m_config.isNewLineEnable = v;
    if (v) {
        return nl();
    }
    else {
        return nonl();
    }
}

bool Curses::isNewLineEnable()
{
    return m_config.isNewLineEnable;
}

Status Curses::setKeypad(bool v)
{
    // If curses mode stop
    if (!Curses::isInit()) {
        throw std::runtime_error("Curses didn't initialized");
    }

    m_config.isKeypadEnable = v;
    return keypad(stdscr, v);
}

bool Curses::isKeypadEnable()
{
    return m_config.isKeypadEnable;
}

Status Curses::setTerminalSize(const Vector2i& size)
{
    // If curses mode stop
    if (!Curses::isInit()) {
        throw std::runtime_error("Curses didn't initialized");
    }

    Status result = resize_term(size.y, size.x);
    m_config.terminalSize = Vector2i(getmaxx(stdscr), getmaxy(stdscr));
    return result;
}

Vector2i Curses::getTerminalSize()
{
    return m_config.terminalSize;
}

Status Curses::blinkColors()
{
    // If curses mode stop
    if (!Curses::isInit()) {
        throw std::runtime_error("Curses didn't initialized");
    }

    return flash();
}

Status Curses::playBeepSound()
{
    // If curses mode stop
    if (!Curses::isInit()) {
        throw std::runtime_error("Curses didn't initialized");
    }

    return beep();
}
}
