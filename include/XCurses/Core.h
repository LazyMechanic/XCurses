#pragma once

#include <functional>
#include <unordered_map>

#include <XCurses/Status.h>
#include <XCurses/Window.h>
#include <XCurses/CoreConfig.h>

namespace xcur {
class Core
{
public:
    /**
	 * \brief Default Core constructor
	 */
	Core();

    /**
	 * \brief Core destructor
	 */
	~Core();

	/**
	 * \brief Initialize Core with params
	 * \param config Configuration object
	 */
	void init(const CoreConfig& config = CoreConfig::Default);

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
	Status blinkColors() const;

	/**
	 * \brief Beep sound
	 * \return Status
	 */
	Status playBeepSound() const;

    /**
	 * \brief Add window to core
	 * \param window Window smart ptr
	 * \return Ok if window added successfully, Err if the window already exists
	 */
	Status addWindow(const Window::Ptr<>& window);

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
	void draw();

private:
	/**
	 * \brief Get hash from window id
	 * \param id Window id
	 * \return Hash
	 */
	size_t windowHash(const uint32_t& id);

	/**
	 * \brief Current PDCurses config
	 */
	CoreConfig m_config;

    /**
	 * \brief Container for windows
	 */
	std::unordered_map<const uint32_t, Window::Ptr<>, std::function<size_t(const uint32_t&)>> m_windows;
};
}