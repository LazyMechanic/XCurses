#include <XCurses/ColorSystem.h>

#include <PDCurses/curses.h>

namespace xcur {
ColorSystem::ColorSystem() :
    m_curPalette(nullptr)
{
	ColorPalette defaultPalette({
	    Color::Black,
	    Color::Blue,
	    Color::Green,
	    Color::Cyan,
	    Color::Red,
	    Color::Magenta,
	    Color::Yellow,
	    Color::White,
	    Color::DarkGray,
	    Color::DarkBlue,
	    Color::DarkGreen,
	    Color::DarkCyan,
	    Color::DarkRed,
	    Color::DarkMagenta,
	    Color::DarkYellow,
	    Color::Gray});

	m_palettes["default"] = defaultPalette;
	useColorPalette("default");
}

Status ColorSystem::addColorPalette(const std::string& name, const ColorPalette& palette)
{
	auto it = m_palettes.find(name);
	// If the palette already exists
	if (it != m_palettes.end()) {
		return Status::Err;
	}

	m_palettes[name] = palette;

	return Status::Ok;
}

Status ColorSystem::useColorPalette(const std::string& name)
{
	auto it = m_palettes.find(name);
	// If the palette not found
	if (it == m_palettes.end()) {
		return Status::Err;
	}

	m_curPalette = &m_palettes[name];

    for (auto colorIt = m_curPalette->m_colors.begin(); colorIt != m_curPalette->m_colors.end(); ++colorIt) {
		init_color(colorIt->second, colorIt->first.r, colorIt->first.g, colorIt->first.b);
    }

    for (auto pairIt = m_curPalette->m_colorPairs.begin(); pairIt != m_curPalette->m_colorPairs.end(); ++pairIt) {
		init_pair(
			pairIt->second, 
			pairIt->first.first, 
			pairIt->first.second);
    }
}

Status ColorSystem::setCharColors(const Color& background, const Color& foreground)
{
}
}
