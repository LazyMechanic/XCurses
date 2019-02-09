#include <XCurses/ColorSystem.h>

#include <algorithm>

#include <PDCurses/curses.h>
#include <iostream>

namespace xcur {
ColorSystem::ColorSystem() :
    m_curPalette(nullptr),
    m_palettes(0)
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

Status ColorSystem::addColorPalette(const std::string& paletteName, const ColorPalette& palette)
{
	std::string lowerName = paletteName;
	std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

	auto it = m_palettes.find(lowerName);
	// If the palette already exists
	if (it != m_palettes.end()) {
		return Status::Err;
	}

	m_palettes[lowerName] = palette;

	return Status::Ok;
}

Status ColorSystem::useColorPalette(const std::string& paletteName)
{
	std::string lowerName = paletteName;
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

uint8_t ColorSystem::getColorPairId(const std::string& paletteName, const Color& foreground, const Color& background)
{
	auto colorPaletteIt = m_palettes.find(paletteName);
    // If palette not found
    if (colorPaletteIt == m_palettes.end()) {
        // 0 pair init by default by curses
		return 0;
    }

	return colorPaletteIt->second.getColorPairId(foreground, background);
}

ColorPalette* ColorSystem::getColorPalette(const std::string& paletteName)
{
	std::string lowerName = paletteName;
	std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

	auto colorPaletteIt = m_palettes.find(lowerName);
    // If the color palette not found
    if (colorPaletteIt == m_palettes.end()) {
		return nullptr;
    }

	return &(colorPaletteIt->second);
}
}
