#include <XCurses/System/Core.h>

#include <chrono>
#include <algorithm>
#include <stdexcept>

#include <PDCurses/curses.h>

#include <XCurses/System/Input.h>
#include <XCurses/System/Context.h>

namespace xcur {

Object::Ptr<Core> Core::create()
{
    // If curses doesn't init
    if (!Curses::isInit()) {
        throw std::runtime_error("Curses didn't initialized");
    }

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
    if (Curses::isInit()) {
        Curses::stop();
    }
}

Object::Ptr<ContextSystem> Core::getContextSystem() const
{
    return m_contextSystem;
}

Object::Ptr<ColorSystem> Core::getColorSystem() const
{
    return m_colorSystem;
}

void Core::run(Object::Ptr<Context> context)
{
    m_contextSystem->push(context);

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
