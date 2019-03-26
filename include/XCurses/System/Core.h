#pragma once

#include <XCurses/System/Status.h>
#include <XCurses/System/Curses.h>
#include <XCurses/System/Object.h>
#include <XCurses/System/Vector2.h>
#include <XCurses/System/CursesConfig.h>
#include <XCurses/System/ColorSystem.h>
#include <XCurses/System/ContextSystem.h>

namespace xcur {
/**
 * \brief Basis xcurses class. It handles the context system, the color system
 * and curses modes
 */
class Core : 
    public Object
{
public:
    /**
     * \brief Create Core and init Curses
     * \return Smart ptr to Core
     */
    static Object::Ptr<Core> create();

    /**
     * \brief Core destructor
     */
    ~Core();

    /**
     * \brief Get context system
     * \return Smart ptr to context system
     */
    Object::Ptr<ContextSystem> getContextSystem() const;

    /**
     * \brief Get color system
     * \return Smart ptr to color system
     */
    Object::Ptr<ColorSystem> getColorSystem() const;

    /**
     * \brief Start in auto mode main loop where will push the Context and call
     * Core::handleEvents(), Core::update() and Core::draw() functions. 
     * The cycle will continue until called Core::exit() function for close application.
     * \param context Context for handle application
     */
    void run(Object::Ptr<Context> context);

    /**
     * \brief Handle input
     */
    void handleEvents();

    /**
     * \brief Call update all windows
     * \param dt Delta time
     */
    void update(float dt);

    /**
     * \brief Draw all windows
     */
    void draw() const;

    /**
     * \brief Check if application is running
     * \return True if application didn't close, false otherwise
     */
    bool isRunning() const;

    /**
     * \brief Set isRunning is false
     */
    void exit();

private:
    /**
     * \brief Default Core constructor
     */
    Core();

    /**
     * \brief State of application. If true then app is running
     */
    bool m_isRunning;

    /**
     * \brief Smart ptr to context system
     */
    Object::Ptr<ContextSystem> m_contextSystem;

    /**
     * \brief Smart ptr to color system
     */
    Object::Ptr<ColorSystem> m_colorSystem;
};
}