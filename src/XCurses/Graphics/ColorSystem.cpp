#include <XCurses/Graphics/ColorSystem.h>

#include <PDCurses/curses.h>

#include <algorithm>


namespace xcur {
ColorSystem::ColorSystem() :
    m_curColorPalette(nullptr),
    m_palettes(0)
{
    const ColorPalette defaultPalette({
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

    m_palettes[lowerName] = std::make_unique<ColorPalette>(palette);

    return Status::Ok;
}

Status ColorSystem::useColorPalette(const std::string& paletteName)
{
    std::string lowerName = paletteName;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
    
    const auto paletteIt = m_palettes.find(lowerName);
    // If the palette not found
    if (paletteIt == m_palettes.end()) {
        return Status::Err;
    }

    m_curColorPalette = paletteIt->second.get();
    return applyCurrentColorPalette();
}

Status ColorSystem::applyCurrentColorPalette() const
{
    // If current palette is nonexistent
    if (m_curColorPalette == nullptr) {
        return Status::Err;
    }

    for (auto colorIt = m_curColorPalette->colorBegin(); colorIt != m_curColorPalette->colorEnd(); ++colorIt) {
        init_color(colorIt->second, colorIt->first.r, colorIt->first.g, colorIt->first.b);
    }

    for (auto pairIt = m_curColorPalette->colorPairBegin(); pairIt != m_curColorPalette->colorPairEnd(); ++pairIt) {
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

    return colorPaletteIt->second->getColorPairId(foreground, background);
}

ColorSystem::ColorPaletteIterator ColorSystem::findColorPalette(const std::string& paletteName)
{
    std::string lowerName = paletteName;
    std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

    return m_palettes.find(lowerName);
}

ColorSystem::ColorPaletteIterator ColorSystem::colorPaletteBegin()
{
    return m_palettes.begin();
}

ColorSystem::ColorPaletteIterator ColorSystem::colorPaletteEnd()
{
    return m_palettes.end();
}

ColorPalette* ColorSystem::getCurrentPalette() const
{
    return m_curColorPalette;
}
}
