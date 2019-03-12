#include <XCurses/System/Core.h>

#include <algorithm>

#include <PDCurses/curses.h>

#include <XCurses/System/Input.h>
#include <XCurses/Graphics/Context.h>

namespace xcur {
Object::Ptr<Core> Core::create()
{
    std::shared_ptr<Core> core(new Core());
    core->m_contextSystem->setCore(core);
    return core;
}

Core::Core() :
    m_contextSystem(ContextSystem::create()),
    m_colorSystem(ColorSystem::create())
{
    initscr();
}

Core::~Core()
{
    endwin();
}

void Core::init(const CoreConfig& config)
{
    this->setCBreakMode(config.enableCBreakMode);
    this->setEchoMode(config.enableEchoMode);
    this->setRawMode(config.enableRawMode);
    this->setNewLineMode(config.enableNewLineMode);
    this->setTerminalSize(config.terminalSize);
}

Status Core::setCBreakMode(bool v)
{
    m_config.enableCBreakMode = v;
    if (v) {
        return cbreak();
    }
    else {
        return nocbreak();
    }
}

bool Core::isCBreakMode() const
{
    return m_config.enableCBreakMode;
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

bool Core::isEchoMode() const
{
    return m_config.enableEchoMode;
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

bool Core::isRawMode() const
{
    return m_config.enableRawMode;
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

bool Core::isNewLineMode() const
{
    return m_config.enableNewLineMode;
}

Status Core::setTerminalSize(const Vector2u& size)
{
    Status result = resize_term(size.y, size.x);
    m_config.terminalSize = Vector2u(getmaxx(stdscr), getmaxy(stdscr));
    return result;
}

Vector2u Core::getTerminalSize() const
{
    return m_config.terminalSize;
}

Status Core::blinkColors() const
{
    return flash();
}

Status Core::playBeepSound() const
{
    return beep();
}

Object::Ptr<ContextSystem> Core::getContextSystem() const
{
    return m_contextSystem;
}

Object::Ptr<ColorSystem> Core::getColorSystem() const
{
    return m_colorSystem;
}

void Core::handleEvents()
{
    m_contextSystem->handleEvents();
}

void Core::update(float dt)
{
    m_contextSystem->update(dt);
}

void Core::draw()
{
    m_contextSystem->draw();
}
}
