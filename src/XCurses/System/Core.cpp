#include <XCurses/System/Core.h>

#include <chrono>
#include <algorithm>
#include <stdexcept>

#include <PDCurses/curses.h>

#include <XCurses/System/Input.h>
#include <XCurses/Graphics/Context.h>

namespace xcur {
CoreConfig Core::m_config(
    Vector2u::Zero,
    0,
    false,
    false,
    false,
    false,
    false,
    false);

Object::Ptr<Core> Core::create()
{
    std::shared_ptr<Core> core(new Core());
    core->m_contextSystem->setCore(core);
    return core;
}

Core::Core() :
    m_isRunning(true),
    m_contextSystem(ContextSystem::create()),
    m_colorSystem(ColorSystem::create())
{
}

Core::~Core()
{
    if (isCursesModeEnable()) {
        endwin();
        m_config.isCursesModeEnable = false;
    }
}

void Core::init(const CoreConfig& config)
{
    initscr();

    setCBreak(config.isCBreakEnable);
    setEcho(config.isEchoEnable);
    setRaw(config.isRawEnable);
    setNewLine(config.isNewLineEnable);
    setTerminalSize(config.terminalSize);

    m_config.isInit = true;

    onCursesMode();
}

bool Core::isInit()
{
    return m_config.isInit;
}

void Core::onCursesMode()
{
    // If curses mode disable
    if (!isCursesModeEnable()) {
        throw std::runtime_error("Core didn't initialized");
    }

    doupdate();
    m_config.isCursesModeEnable = true;
}

void Core::offCursesMode()
{
    // If curses mode disable
    if (!isCursesModeEnable()) {
        throw std::runtime_error("Core didn't initialized");
    }

    endwin();
    m_config.isCursesModeEnable = false;
}

bool Core::isCursesModeEnable()
{
    return m_config.isCursesModeEnable;
}

Status Core::setCBreak(bool v)
{
    // If curses mode disable
    if (!isCursesModeEnable()) {
        throw std::runtime_error("Core didn't initialized");
    }

    m_config.isCBreakEnable = v;
    if (v) {
        return cbreak();
    }
    else {
        return nocbreak();
    }
}

bool Core::isCBreakEnable()
{
    return m_config.isCBreakEnable;
}

Status Core::setEcho(bool v)
{
    // If curses mode disable
    if (!isCursesModeEnable()) {
        throw std::runtime_error("Core didn't initialized");
    }

    m_config.isEchoEnable = v;
    if (v) {
        return echo();
    }
    else {
        return noecho();
    }
}

bool Core::isEchoEnable()
{
    return m_config.isEchoEnable;
}

Status Core::setRaw(bool v)
{
    // If curses mode disable
    if (!isCursesModeEnable()) {
        throw std::runtime_error("Core didn't initialized");
    }

    m_config.isRawEnable = v;
    if (v) {
        return raw();
    }
    else {
        return noraw();
    }
}

bool Core::isRawEnable()
{
    return m_config.isRawEnable;
}

Status Core::setNewLine(bool v)
{
    // If curses mode disable
    if (!isCursesModeEnable()) {
        throw std::runtime_error("Core didn't initialized");
    }

    m_config.isNewLineEnable = v;
    if (v) {
        return nl();
    }
    else {
        return nonl();
    }
}

bool Core::isNewLineEnable()
{
    return m_config.isNewLineEnable;
}

Status Core::setTerminalSize(const Vector2u& size)
{
    // If curses mode disable
    if (!isCursesModeEnable()) {
        throw std::runtime_error("Core didn't initialized");
    }

    Status result = resize_term(size.y, size.x);
    m_config.terminalSize = Vector2u(getmaxx(stdscr), getmaxy(stdscr));
    return result;
}

Vector2u Core::getTerminalSize()
{
    return m_config.terminalSize;
}

Status Core::blinkColors()
{
    // If curses mode disable
    if (!isCursesModeEnable()) {
        throw std::runtime_error("Core didn't initialized");
    }

    return flash();
}

Status Core::playBeepSound()
{
    // If curses mode disable
    if (!isCursesModeEnable()) {
        throw std::runtime_error("Core didn't initialized");
    }

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

void Core::run(const CoreConfig& config)
{
    Core::init(config);

    using SecondPartial = std::chrono::duration<float, std::ratio<1>>;

    auto currentTime = std::chrono::steady_clock::now();
    auto lastTime = currentTime;
    float dt;
    while (m_isRunning) {
        dt = std::chrono::duration_cast<SecondPartial>(currentTime - lastTime).count();
        currentTime = std::chrono::steady_clock::now();

        handleEvents();
        update(dt);
        draw();

        lastTime = currentTime;
    }
}

void Core::handleEvents()
{
    m_contextSystem->handleEvents();
}

void Core::update(float dt)
{
    m_contextSystem->update(dt);
}

void Core::draw() const
{
    m_contextSystem->draw();
}

bool Core::isRunning() const
{
    return m_isRunning;
}

void Core::exit()
{
    m_isRunning = true;
}
}
