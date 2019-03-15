#pragma once

#include <XCurses/System/Status.h>
#include <XCurses/System/Object.h>
#include <XCurses/System/Vector2.h>
#include <XCurses/System/CoreConfig.h>
#include <XCurses/Graphics/ColorSystem.h>
#include <XCurses/Graphics/ContextSystem.h>

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
     * \brief Create Core
     * \return Smart ptr to Core
     */
    static Object::Ptr<Core> create();

    /**
     * \brief Core destructor
     */
    ~Core();

    /**
     * \brief Initialize Core with params
     * \param config Configuration object
     */
    static void init(const CoreConfig& config = CoreConfig::Default);

    /**
     * \brief Check if Core is init
     * \return True if Core is init, false otherwise
     */
    static bool isInit();

    /**
     * \brief Equal doupdate() from curses for return curses mode.
     * Use only after call Core::init().
     * Called automatically when Core will init
     */
    static void onCursesMode();

    /**
     * \brief Equal endwin() from curses.
     * Called automatically when Core will destroy
     */
    static void offCursesMode();

    /**
     * \brief Check if curses mode enable
     * \return True if curses mode enable, false otherwise
     */
    static bool isCursesModeEnable();

    /**
     * \brief Toggle cbreak mode.
     * In cbreak mode (\a true), characters typed by the user are made available immediately,
     * and erase/kill character processing is not performed.
     * In nocbreak mode (\a false), typed characters are buffered until a newline or carriage return.
     * Interrupt and flow control characters are unaffected by this mode.
     * \param v Value
     * \return Status
     */
    static Status setCBreak(bool v);

    /**
     * \brief Get cbreak mode state
     * \return True if cbreak mode enable, false otherwise
     */
    static bool isCBreakEnable();

    /**
     * \brief Toggle echo mode.
     * The mode controls whether typed characters are echoed by the input routine.
     * \param v Value
     * \return Status
     */
    static Status setEcho(bool v);

    /**
     * \brief Get echo mode state
     * \return True if echo mode enable, false otherwise
     */
    static bool isEchoEnable();

    /**
     * \brief Toggle raw mode.
     * Raw mode is similar to cbreak mode, in that characters typed
     * are immediately passed through to the user program.
     * The difference is that in raw mode,
     * the \a INTR, \a QUIT, \a SUSP, and \a STOP characters are passed through
     * without being interpreted, and without generating a signal.
     * \param v Value
     * \return Status
     */
    static Status setRaw(bool v);

    /**
     * \brief Get raw mode state
     * \return True if raw mode enable, false otherwise
     */
    static bool isRawEnable();

    /**
     * \brief Toggle newline mode.
     * The mode enables or disables the translation
     * of a carriage return into a newline on input.
     * \param v Value
     * \return Status
     */
    static Status setNewLine(bool v);

    /**
     * \brief Get new line mode state
     * \return True if new line mode enable, false otherwise
     */
    static bool isNewLineEnable();

    /**
     * \brief Set terminal size.
     * size.x is width, size.y is height
     * \param size New terminal size
     * \return Status
     */
    static Status setTerminalSize(const Vector2u& size);

    /**
     * \brief Get terminal size.
     * size.x is width, size.y is height
     * \return Terminal size
     */
    static Vector2u getTerminalSize();

    /**
     * \brief Inverse all colors in terminal for a moment
     * \return Status
     */
    static Status blinkColors();

    /**
     * \brief Beep sound
     * \return Status
     */
    static Status playBeepSound();

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
     * \brief Start in auto mode main loop where will called Core::init(), 
     * Core::handleEvents(), Core::update() and Core::draw() functions. 
     * The cycle will continue until called Core::exit() function for close application.
     * \param config Core config for init
     */
    void run(const CoreConfig& config = CoreConfig::Default);

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
     * \brief Current curses config
     */
    static CoreConfig m_config;

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