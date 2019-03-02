#include <XCurses/System/Core.h>

#include <algorithm>

#include <PDCurses/curses.h>

#include <XCurses/System/Input.h>

namespace xcur {
Core::Core()
{
    initscr();
}

Core::~Core()
{
    endwin();
}

void Core::init(const CoreConfig& config)
{
    this->setCBrakeMode(config.enableCBreakMode);
    this->setEchoMode(config.enableEchoMode);
    this->setRawMode(config.enableRawMode);
    this->setNewLineMode(config.enableNewLineMode);
    this->setTerminalSize(config.terminalWidth, config.terminalHeight);

}

Status Core::setCBrakeMode(bool v)
{
    m_config.enableCBreakMode = v;
    if (v) {
        return cbreak();
    }
    else {
        return nocbreak();
    }
}

Status Core::setEchoMode(bool v)
{
    m_config.enableEchoMode = v;
    if (v) {
        return echo();
    }
    else {
        return noecho();
    }
}

Status Core::setRawMode(bool v)
{
    m_config.enableRawMode = v;
    if (v) {
        return raw();
    }
    else {
        return noraw();
    }
}

Status Core::setNewLineMode(bool v)
{
    m_config.enableNewLineMode = v;
    if (v) {
        return nl();
    }
    else {
        return nonl();
    }
}

Status Core::setTerminalSize(unsigned int width, unsigned int height)
{
    m_config.terminalWidth = getmaxx(stdscr);
    m_config.terminalHeight = getmaxy(stdscr);
    return resize_term(height, width);
}

Status Core::blinkColors() const
{
    return flash();
}

Status Core::playBeepSound() const
{
    return beep();
}

void Core::handleEvents()
{
    // TODO: call current context handleEvents() func
}

void Core::update(const float dt)
{
    // TODO: call current context update() func
}

void Core::draw()
{
    /*
        // Clear virtual screen
        clear();
        wnoutrefresh(stdscr);
        // Draw all windows
        for (auto& window : m_windows) {
            window->draw();
        }
        // Draw all windows
        doupdate();
    */
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ all work code, copy to context
    // TODO: call current context draw() func
}
}
