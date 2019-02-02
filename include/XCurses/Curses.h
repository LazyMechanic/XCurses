#pragma once

#include <XCurses/CursesConfig.h>

namespace xcur {
class Curses
{
public:
	using Status = int;

	Curses();
	~Curses();

	/**
	 * \brief Initialize Curses with params
	 * \param config Config container
	 */
	void init(const CursesConfig& config = CursesConfig());

	/**
	 * \brief Toggle cbreak mode.
	 * In cbreak mode (true), characters typed by the user are made available immediately,
	 * and erase/kill character processing is not performed.
	 * In nocbreak mode (false), typed characters are buffered until a newline or carriage return.
	 * Interrupt and flow control characters are unaffected by this mode.
	 * \param v Value
	 * \return Status code
	 */
	Curses::Status setCBrake(bool v);

	/**
	 * \brief Toggle echo mode.
	 * The mode controls whether typed characters are echoed by the input routine.
	 * \param v Value
	 * \return Status code
	 */
	Curses::Status setEcho(bool v);

	/**
	 * \brief Toggle raw mode.
	 * Raw mode is similar to cbreak mode, in that characters typed
	 * are immediately passed through to the user program.
	 * The difference is that in raw mode,
	 * the INTR, QUIT, SUSP, and STOP characters are passed through
	 * without being interpreted, and without generating a signal.
	 * \param v Value
	 * \return Status code
	 */
	Curses::Status setRaw(bool v);

	/**
	 * \brief Toggle newline mode.
	 * The mode enables or disables the translation
	 * of a carriage return into a newline on input.
	 * \param v Value
	 * \return Status code
	 */
	Curses::Status setNewLine(bool v);

	/**
	 * \brief Set delay for input.
	 * It is similar to cbreak mode,
	 * but allows for a time limit to be specified,
	 * in tenths of a second. This causes getch()
	 * to block for that period before returning ERR if no key has been received.
	 * Value must be between 1 and 255.
	 * \param delay Delay value
	 * \return Status code
	 */
	Curses::Status setHalfDelay(unsigned int delay);

	/**
	 * \brief Set terminal size.
	 * \param width Width value
	 * \param height Height value
	 * \return Status code
	 */
	Curses::Status setTerminalSize(unsigned int width, unsigned int height);

	/**
	 * \brief Inverse all colors in terminal
	 * \return Status code
	 */
	Curses::Status inverseColors();

	/**
	 * \brief Beep sound
	 * \return Status code
	 */
	Curses::Status playBeepSound();

private:
	/**
	 * \brief Current PDCurses config
	 */
	CursesConfig m_config;
};
}