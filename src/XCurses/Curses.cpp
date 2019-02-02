#include <XCurses/Curses.h>

#include <PDCurses/curses.h>

namespace xcur {
Curses::Curses()
{
	initscr();
}

Curses::~Curses()
{
	endwin();
}

void Curses::init(const CursesConfig& config)
{
	this->setCBrake(config.enableCBreakMode);
	this->setEcho(config.enableEchoMode);
	this->setRaw(config.enableRawMode);
	this->setNewLine(config.enableNewLineMode);
	this->setTerminalSize(config.terminalWidth, config.terminalHeight);
}

Curses::Status Curses::setCBrake(bool v)
{
	m_config.enableCBreakMode = v;
	if (v) {
		return cbreak();
	}
	else {
		return nocbreak();
	}
}

Curses::Status Curses::setEcho(bool v)
{
	m_config.enableEchoMode = v;
	if (v) {
		return echo();
	}
	else {
		return noecho();
	}
}

Curses::Status Curses::setRaw(bool v)
{
	m_config.enableRawMode = v;
	if (v) {
		return raw();
	}
	else {
		return noraw();
	}
}

Curses::Status Curses::setNewLine(bool v)
{
	m_config.enableNewLineMode = v;
	if (v) {
		return nl();
	}
	else {
		return nonl();
	}
}

Curses::Status Curses::setTerminalSize(unsigned int width, unsigned int height)
{
	m_config.terminalWidth = width;
	m_config.terminalHeight = height;
	return resize_term(height, width);
}

Curses::Status Curses::inverseColors()
{
	return flash();
}

Curses::Status Curses::playBeepSound()
{
	return beep();
}
}