#include <XCurses/ColorSystem.h>

#include <PDCurses/curses.h>
#include <algorithm>

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

	addColorPalette("default", defaultPalette);
	useColorPalette("default");
}

Status ColorSystem::addColorPalette(const std::string& name, const ColorPalette& palette)
{
	std::string lowerName = name;
	std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

	auto it = m_palettes.find(lowerName);
	// If the palette already exists
	if (it != m_palettes.end()) {
		return Status::Err;
	}

	m_palettes[lowerName] = palette;

	return Status::Ok;
}

Status ColorSystem::useColorPalette(const std::string& name)
{
	std::string lowerName = name;
	std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

	auto it = m_palettes.find(lowerName);
	// If the palette not found
	if (it == m_palettes.end()) {
		return Status::Err;
	}

	m_curPalette = &m_palettes[lowerName];

    for (auto colorIt = m_curPalette->colorBegin(); colorIt != m_curPalette->colorEnd(); ++colorIt) {
		init_color(colorIt->second, colorIt->first.r, colorIt->first.g, colorIt->first.b);
    }

    for (auto pairIt = m_curPalette->colorPairBegin(); pairIt != m_curPalette->colorPairEnd(); ++pairIt) {
		init_pair(
			pairIt->second, 
			pairIt->first.first, 
			pairIt->first.second);
    }

	return Status::Ok;
}

Char ColorSystem::setCharColors(const Char& ch, const Color& foreground, const Color& background) const
{
	auto colorPairIt = m_curPalette->findColorPair(foreground, background);
    // If colors is wrong
    if (colorPairIt == m_curPalette->colorPairEnd()) {
		return ch;
    }

	Char changedChar = ch;
	changedChar.colorPairId = colorPairIt->second;

	return changedChar;
}
}
