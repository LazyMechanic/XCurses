#pragma once

#include <XCurses/Status.h>
#include <XCurses/CursesConfig.h>

namespace xcur {
class Curses
{
public:

	Curses();

	~Curses();

	/**
	 * \brief Initialize Curses with params
	 * \param config Configuration object
	 */
	void init(const CursesConfig& config = CursesConfig::Default);

	/**
	 * \brief Toggle cbreak mode.
	 * In cbreak mode (\a true), characters typed by the user are made available immediately,
	 * and erase/kill character processing is not performed.
	 * In nocbreak mode (\a false), typed characters are buffered until a newline or carriage return.
	 * Interrupt and flow control characters are unaffected by this mode.
	 * \param v Value
	 * \return Status
	 */
	Status setCBrakeMode(bool v);

	/**
	 * \brief Toggle echo mode.
	 * The mode controls whether typed characters are echoed by the input routine.
	 * \param v Value
	 * \return Status
	 */
    Status setEchoMode(bool v);

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
	Status setRawMode(bool v);

	/**
	 * \brief Toggle newline mode.
	 * The mode enables or disables the translation
	 * of a carriage return into a newline on input.
	 * \param v Value
	 * \return Status
	 */
	Status setNewLineMode(bool v);

	/**
	 * \brief Set terminal size.
	 * \param width Width value
	 * \param height Height value
	 * \return Status
	 */
	Status setTerminalSize(unsigned int width, unsigned int height);

	/**
	 * \brief Inverse all colors in terminal for a moment
	 * \return Status
	 */
	Status blinkColors();

	/**
	 * \brief Beep sound
	 * \return Status
	 */
	Status playBeepSound();

private:
	/**
	 * \brief Current PDCurses config
	 */
	CursesConfig m_config;
};
}