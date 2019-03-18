#pragma once

#include <XCurses/System/Vector2.h>

#include <XCurses/System/Status.h>
#include <XCurses/System/CursesConfig.h>

namespace xcur {
class Curses
{
public:

    /**
     * \brief Initialize curses with params. Need to run first, only once
     * \param config Configuration object
     */
    static void init(const CursesConfig& config = CursesConfig::Default);

    /**
     * \brief Check if curses is init
     * \return True if curses is init, false otherwise
     */
    static bool isInit();

    /**
     * \brief Equal doupdate() from curses for return curses mode.
     * Use only after call Curses::init().
     * Called automatically when Core will init
     */
    static void resume();

    /**
     * \brief Equal endwin() from curses.
     * Called automatically when Core will destroy
     */
    static void stop();

    /**
     * \brief Check if curses mode stop
     * \return True if curses mode stop, false otherwise
     */
    static bool isStop();

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

private:
    /**
     * \brief Current curses config
     */
    static CursesConfig m_config;
};
}