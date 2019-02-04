#include <XCurses/ColorSystem.h>

#include <PDCurses/curses.h>

namespace xcur {
ColorSystem::ColorSystem()
{
    // Init standard colors

	init_color(COLOR_BLACK, Color::Black.cursesRed(), Color::Black.cursesGreen(), Color::Black.cursesBlue());
	init_color(COLOR_RED, Color::Red.cursesRed(), Color::Red.cursesGreen(), Color::Red.cursesBlue());
	init_color(COLOR_GREEN, Color::Green.cursesRed(), Color::Green.cursesGreen(), Color::Green.cursesBlue());
	init_color(COLOR_BLUE, Color::Blue.cursesRed(), Color::Blue.cursesGreen(), Color::Blue.cursesBlue());
	init_color(COLOR_CYAN, Color::Cyan.cursesRed(), Color::Cyan.cursesGreen(), Color::Cyan.cursesBlue());
	init_color(COLOR_MAGENTA, Color::Magenta.cursesRed(), Color::Magenta.cursesGreen(), Color::Magenta.cursesBlue());
	init_color(COLOR_YELLOW, Color::Yellow.cursesRed(), Color::Yellow.cursesGreen(), Color::Yellow.cursesBlue());
	init_color(COLOR_WHITE, Color::White.cursesRed(), Color::White.cursesGreen(), Color::White.cursesBlue());

	init_color(COLOR_BLACK + 8, Color::DarkGray.cursesRed(), Color::DarkGray.cursesGreen(), Color::DarkGray.cursesBlue());
	init_color(COLOR_RED + 8, Color::DarkRed.cursesRed(), Color::DarkRed.cursesGreen(), Color::DarkRed.cursesBlue());
	init_color(COLOR_GREEN + 8, Color::DarkGreen.cursesRed(), Color::DarkGreen.cursesGreen(), Color::DarkGreen.cursesBlue());
	init_color(COLOR_BLUE + 8, Color::DarkBlue.cursesRed(), Color::DarkBlue.cursesGreen(), Color::DarkBlue.cursesBlue());
	init_color(COLOR_CYAN + 8, Color::DarkCyan.cursesRed(), Color::DarkCyan.cursesGreen(), Color::DarkCyan.cursesBlue());
	init_color(COLOR_MAGENTA + 8, Color::DarkMagenta.cursesRed(), Color::DarkMagenta.cursesGreen(), Color::DarkMagenta.cursesBlue());
	init_color(COLOR_YELLOW + 8, Color::DarkYellow.cursesRed(), Color::DarkYellow.cursesGreen(), Color::DarkYellow.cursesBlue());
	init_color(COLOR_WHITE + 8, Color::Gray.cursesRed(), Color::Gray.cursesGreen(), Color::Gray.cursesBlue());

    // Add colors to container
	m_colors[Color::Black] = COLOR_BLACK;
	m_colors[Color::Red] = COLOR_RED;
	m_colors[Color::Green] = COLOR_GREEN;
	m_colors[Color::Blue] = COLOR_BLUE;
	m_colors[Color::Cyan] = COLOR_CYAN;
	m_colors[Color::Magenta] = COLOR_MAGENTA;
	m_colors[Color::Yellow] = COLOR_YELLOW;
	m_colors[Color::White] = COLOR_WHITE;

	m_colors[Color::DarkGray] = COLOR_BLACK + 8;
	m_colors[Color::DarkRed] = COLOR_RED + 8;
	m_colors[Color::DarkGreen] = COLOR_GREEN + 8;
	m_colors[Color::DarkBlue] = COLOR_BLUE + 8;
	m_colors[Color::DarkCyan] = COLOR_CYAN + 8;
	m_colors[Color::DarkMagenta] = COLOR_MAGENTA + 8;
	m_colors[Color::DarkYellow] = COLOR_YELLOW + 8;
	m_colors[Color::Gray] = COLOR_WHITE + 8;
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
}
