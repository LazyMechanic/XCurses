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
	this->setCBrakeMode(config.enableCBreakMode);
	this->setEchoMode(config.enableEchoMode);
	this->setRawMode(config.enableRawMode);
	this->setNewLineMode(config.enableNewLineMode);
	this->setTerminalSize(config.terminalWidth, config.terminalHeight);

}

Status Curses::setCBrakeMode(bool v)
{
	m_config.enableCBreakMode = v;
	if (v) {
		return cbreak();
	}
	else {
		return nocbreak();
	}
}

Status Curses::setEchoMode(bool v)
{
	m_config.enableEchoMode = v;
	if (v) {
		return echo();
	}
	else {
		return noecho();
	}
}

Status Curses::setRawMode(bool v)
{
	m_config.enableRawMode = v;
	if (v) {
		return raw();
	}
	else {
		return noraw();
	}
}

Status Curses::setNewLineMode(bool v)
{
	m_config.enableNewLineMode = v;
	if (v) {
		return nl();
	}
	else {
		return nonl();
	}
}

Status Curses::setTerminalSize(unsigned int width, unsigned int height)
{
	m_config.terminalWidth = width;
	m_config.terminalHeight = height;
	return resize_term(height, width);
}

Status Curses::blinkColors()
{
	return flash();
}

Status Curses::playBeepSound()
{
	return beep();
}
}