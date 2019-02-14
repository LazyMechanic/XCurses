#include <XCurses/Core.h>

#include <algorithm>

#include <PDCurses/curses.h>

#include <XCurses/Input.h>

namespace xcur {
Core::Core()
{
	initscr();
}

Core::~Core()
{
	endwin();
}

void Core::init(const CoreConfig& config)
{
	this->setCBrakeMode(config.enableCBreakMode);
	this->setEchoMode(config.enableEchoMode);
	this->setRawMode(config.enableRawMode);
	this->setNewLineMode(config.enableNewLineMode);
	this->setTerminalSize(config.terminalWidth, config.terminalHeight);

}

Status Core::setCBrakeMode(bool v)
{
	m_config.enableCBreakMode = v;
	if (v) {
		return cbreak();
	}
	else {
		return nocbreak();
	}
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

Status Core::setTerminalSize(unsigned int width, unsigned int height)
{
	m_config.terminalWidth = getmaxx(stdscr);
	m_config.terminalHeight = getmaxy(stdscr);
	return resize_term(height, width);
}

Status Core::blinkColors() const
{
	return flash();
}

Status Core::playBeepSound() const
{
	return beep();
}

void Core::addWindow(const Window::Ptr<>& window)
{
	m_addWindows.push_back(window);
}

void Core::removeWindow(const Window::Ptr<>& window)
{
	m_removeWindows.push_back(window);
}

size_t Core::numberOfWindows() const
{
    return m_windows.size();
}

void Core::handleEvents()
{
	Input::handleEvents(m_windows.back());
}

void Core::update(const float dt)
{
    for (auto& window : m_windows) {
		window->update(dt);
		window->updateWidgets();
    }

	updateWindows();
}

void Core::draw()
{
    // Clear virtual screen
	clear();
	wnoutrefresh(stdscr);
    // Draw all windows
	for (auto& window : m_windows) {
		window->draw();
	}
    // Draw all windows
	doupdate();
}

std::list<Window::Ptr<>>::iterator Core::findWindow(const Window::Ptr<>& window)
{
	return std::find_if(m_windows.begin(), m_windows.end(), [&window](const Window::Ptr<>& findWindow) {
		return window->getId() == findWindow->getId();
	});
}

void Core::tryAddWindows()
{
    for (auto& window : m_addWindows) {
		auto windowIt = findWindow(window);
		// If the window not found 
		if (windowIt == m_windows.end()) {
			m_windows.push_back(window);
		}
    }
	// Clear window queue for add
	m_addWindows.clear();
}

void Core::tryRemoveWindows()
{
	for (auto& window : m_removeWindows) {
		auto windowIt = findWindow(window);
		// If the window exists 
		if (windowIt != m_windows.end()) {
			m_windows.erase(windowIt);
		}
	}
	// Clear window queue for remove
	m_removeWindows.clear();
}

void Core::updateWindows()
{
    // Add windows
	tryAddWindows();
    // Remove windows
	tryRemoveWindows();
}

size_t Core::windowHash(const uint32_t& id) const
{
	return std::hash<uint32_t>()(id);
}
}
