#include <XCurses/Core.h>

#include <PDCurses/curses.h>

namespace xcur {
Core::Core() :
    m_windows(0, std::bind(&Core::windowHash, this, std::placeholders::_1))
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

Status Core::addWindow(const Window::Ptr<>& window)
{
    const auto windowIt = m_windows.find(window->getId());
    // If the window already exists
    if (windowIt != m_windows.end()) {
		return Status::Err;
    }

	m_windows[window->getId()] = window;
	m_windows[window->getId()]->m_core = this;
	return Status::Ok;
}

Status Core::removeWindow(const Window::Ptr<>& window)
{
    const auto windowIt = m_windows.find(window->getId());
    // If window not found
    if (windowIt == m_windows.end()) {
		return Status::Err;
    }

	m_windows.erase(window->getId());
	return Status::Err;
}

size_t Core::numberOfWindows() const
{
    return m_windows.size();
}

void Core::handleEvents()
{
}

void Core::update(const float dt)
{
    for (auto& window : m_windows) {
		window.second->update(dt);
    }
}

void Core::draw()
{
    // Clear virtual screen
	clear();
	wnoutrefresh(stdscr);
    // Draw all windows
	for (auto& window : m_windows) {
		window.second->draw();
	}
}

size_t Core::windowHash(const uint32_t& id) const
{
	return std::hash<uint32_t>()(id);
}
}
