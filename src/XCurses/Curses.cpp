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
	this->setCBrake(config.enableCBreak);
	this->setEcho(config.enableEcho);
	this->setRaw(config.enableRaw);
	this->setNewLine(config.enableNewLine);
	this->setHalfDelay(config.halfDelay);
	this->setTerminalSize(config.terminalWidth, config.terminalHeight);
}

Curses::Status Curses::setCBrake(bool v)
{
	m_config.enableCBreak = v;
	if (v) {
		return cbreak();
	}
	else {
		return nocbreak();
	}
}

Curses::Status Curses::setEcho(bool v)
{
	m_config.enableEcho = v;
	if (v) {
		return echo();
	}
	else {
		return noecho();
	}
}

Curses::Status Curses::setRaw(bool v)
{
	m_config.enableRaw = v;
	if (v) {
		return raw();
	}
	else {
		return noraw();
	}
}

Curses::Status Curses::setNewLine(bool v)
{
	m_config.enableNewLine = v;
	if (v) {
		return nl();
	}
	else {
		return nonl();
	}
}

Curses::Status Curses::setHalfDelay(unsigned int delay)
{
	m_config.halfDelay = delay;
	return halfdelay(delay);
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