#include <XCurses/ColorSystem.h>

#include <PDCurses/curses.h>

namespace xcur {
ColorSystem::ColorSystem()
{
    // Init standard colors
	this->addColor(Color::Black, COLOR_BLACK);
	this->addColor(Color::Red, COLOR_RED);
	this->addColor(Color::Green, COLOR_GREEN);
	this->addColor(Color::Blue, COLOR_BLUE);
	this->addColor(Color::Cyan, COLOR_CYAN);
	this->addColor(Color::Magenta, COLOR_MAGENTA);
	this->addColor(Color::Yellow, COLOR_YELLOW);
	this->addColor(Color::White, COLOR_WHITE);

	this->addColor(Color::DarkGray, COLOR_BLACK + 8);
	this->addColor(Color::DarkRed, COLOR_RED + 8);
	this->addColor(Color::DarkGreen, COLOR_GREEN + 8);
	this->addColor(Color::DarkBlue, COLOR_BLUE + 8);
	this->addColor(Color::DarkCyan, COLOR_CYAN + 8);
	this->addColor(Color::DarkMagenta, COLOR_MAGENTA + 8);
	this->addColor(Color::DarkYellow, COLOR_YELLOW + 8);
	this->addColor(Color::Gray, COLOR_WHITE + 8);
}

Status ColorSystem::changeColor(const Color& from, const Color& to)
{
	auto itFrom = m_colors.find(from);
	auto itTo = m_colors.find(to);

    if (itFrom == m_colors.end() ||
		itTo == m_colors.end()) 
	{
		return Status::Code::Err;
    }

	m_colors[to] = itFrom->second;
	m_colors.erase(itFrom);

	return Status::Code::Ok;
}

inline void ColorSystem::addColor(const Color& color, uint16_t num)
{
	init_color(num, color.cursesRed(), color.cursesGreen(), color.cursesBlue());
	m_colors[color] = num;
}
}
