#pragma once

#include <list>
#include <functional>

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
	 */
    void addWindow(const Window::Ptr<>& window);

    /**
	 * \brief Remove the window
	 * \param window Window
	 */
	void removeWindow(const Window::Ptr<>& window);

    /**
	 * \brief Get number of windows
	 * \return Number of windows
	 */
	size_t numberOfWindows() const;

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
	 * \brief Find the window in m_windows
	 * \param window Window
	 * \return Iterator to window
	 */
	std::list<Window::Ptr<>>::iterator findWindow(const Window::Ptr<>& window);

	/**
	 * \brief Try add and remove windows
	 */
	void updateWindows();

    /**
	 * \brief Try add windows
	 */
	void tryAddWindows();

    /**
	 * \brief Try remove windows
	 */
	void tryRemoveWindows();

	/**
	 * \brief Get hash from window id
	 * \param id Window id
	 * \return Hash
	 */
	size_t windowHash(const uint32_t& id) const;

	/**
	 * \brief Current PDCurses config
	 */
	CoreConfig m_config;

    /**
	 * \brief Container for windows
	 */
	std::list<Window::Ptr<>> m_windows;

    /**
	 * \brief Windows which need add
	 */
	std::list<Window::Ptr<>> m_addWindows;

	/**
	 * \brief Windows which need remove
	 */
	std::list<Window::Ptr<>> m_removeWindows;
};
}