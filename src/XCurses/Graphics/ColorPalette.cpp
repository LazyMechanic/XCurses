#include <XCurses/Graphics/ColorPalette.h>

namespace xcur {
const uint16_t ColorPalette::maxNumberOfColors = 16;
const uint16_t ColorPalette::maxNumberOfColorPairs = 256;

ColorPalette::ColorPalette() :
    m_curColorId(0),
    m_curColorPairId(0),
    m_defaultColorPairId(0),
    m_colors(0, std::bind(&ColorPalette::colorHash, this, std::placeholders::_1)),
    m_colorPairs(0, std::bind(&ColorPalette::colorPairHash, this, std::placeholders::_1))
{
}

ColorPalette::ColorPalette(const std::list<Color>& colorList) :
    m_curColorId(0),
    m_curColorPairId(0),
    m_defaultColorPairId(0),
    m_colors(0, std::bind(&ColorPalette::colorHash, this, std::placeholders::_1)),
    m_colorPairs(0, std::bind(&ColorPalette::colorPairHash, this, std::placeholders::_1))
{
    for (auto it = colorList.begin(); it != colorList.end() && m_curColorId < maxNumberOfColors; ++it) {
        // If the color doesn't exist
        addColor(*it);
    }
}

Status ColorPalette::addColor(const Color& color)
{
    auto it = m_colors.find(color);
    // If the color already exists
    if (it != m_colors.end()) {
        return Status::Err;
    }

    // If number of colors is maximum
    if (m_curColorId >= maxNumberOfColors) {
        return Status::Err;
    }

    m_colors[color] = m_curColorId++;
    return Status::Ok;
}

Status ColorPalette::swapColor(const Color& from, const Color& to)
{
    auto fromIt = m_colors.find(from);
    // If the color in palette not found
    if (fromIt == m_colors.end()) {
        return Status::Err;
    }

    auto toIt = m_colors.find(to);
    // If new color already exists
    if (toIt != m_colors.end()) {
        return Status::Err;
    }

    // If all right then insert new color and erase previous
    m_colors[to] = fromIt->second;
    m_colors.erase(fromIt);

    return Status::Ok;
}

Status ColorPalette::setDefaultColorPair(const Color& foreground, const Color& background)
{
    auto foregroundIt = m_colors.find(foreground);
    auto backgroundIt = m_colors.find(background);
    // If colors not found
    if (foregroundIt == m_colors.end() ||
        backgroundIt == m_colors.end())
    {
        return Status::Err;
    }

    const std::pair<uint16_t, uint16_t> colorPair = std::make_pair(foregroundIt->second, backgroundIt->second);
    auto colorPairIt = m_colorPairs.find(colorPair);
    // If the color pair already exists
    if (colorPairIt != m_colorPairs.end()) {
        m_defaultColorPairId = m_colorPairs[colorPair];
    }
    // Else create new color pair
    else {
        m_defaultColorPairId = m_curColorPairId++;
        m_colorPairs[colorPair] = m_defaultColorPairId;
    }

    return Status::Ok;
}

Status ColorPalette::setDefaultColorPair(const std::pair<Color, Color>& colorPair)
{
    return setDefaultColorPair(colorPair.first, colorPair.second);
}

uint8_t ColorPalette::getDefaultColorPairId() const
{
    return m_defaultColorPairId;
}

Status ColorPalette::initColorPair(const Color& foreground, const Color& background)
{
    auto foregroundIt = m_colors.find(foreground);
    auto backgroundIt = m_colors.find(background);
    // If colors not found
    if (foregroundIt == m_colors.end() ||
        backgroundIt == m_colors.end())
    {
        return Status::Err;
    }

    const std::pair<uint16_t, uint16_t> colorPair = std::make_pair(foregroundIt->second, backgroundIt->second);
    auto colorPairIt = m_colorPairs.find(colorPair);
    // If the color pair already exists
    if (colorPairIt != m_colorPairs.end()) {
        return Status::Err;
    }
    // If palette stored maximum of color pairs
    if (m_curColorPairId >= maxNumberOfColorPairs) {
        return Status::Err;
    }

    m_colorPairs[colorPair] = m_curColorPairId++;
    return Status::Ok;
}

Status ColorPalette::initColorPair(const std::pair<Color, Color>& colorPair)
{
    return initColorPair(colorPair.first, colorPair.second);
}

uint8_t ColorPalette::getColorPairId(const Color& foreground, const Color& background)
{
    auto foregroundIt = m_colors.find(foreground);
    auto backgroundIt = m_colors.find(background);
    // If colors not found
    if (foregroundIt == m_colors.end() ||
        backgroundIt == m_colors.end())
    {
        return m_defaultColorPairId;
    }

    const std::pair<uint16_t, uint16_t> colorPair = std::make_pair(foregroundIt->second, backgroundIt->second);
    auto colorPairIt = m_colorPairs.find(colorPair);
    // If the color pair already exists
    if (colorPairIt == m_colorPairs.end()) {
        Status initStatus = initColorPair(foreground, background);
        // If init color pair is unsuccessfully
        if (initStatus == Status::Err) {
            return m_defaultColorPairId;
        }
    }

    return m_colorPairs[colorPair];
}

uint8_t ColorPalette::getColorPairId(const std::pair<Color, Color>& colorPair)
{
    return getColorPairId(colorPair.first, colorPair.second);
}

ColorPalette::ConstColorIterator ColorPalette::findColor(const Color& color) const
{
    return m_colors.find(color);
}

ColorPalette::ConstColorPairIterator ColorPalette::findColorPair(const Color& foreground, const Color& background) const
{
    auto foregroundIt = m_colors.find(foreground);
    auto backgroundIt = m_colors.find(background);

    if (foregroundIt == m_colors.end() ||
        backgroundIt == m_colors.end())
    {
        return m_colorPairs.end();
    }

    return m_colorPairs.find(std::make_pair(foregroundIt->second, backgroundIt->second));
}

ColorPalette::ConstColorPairIterator ColorPalette::findColorPair(const std::pair<Color, Color>& colorPair) const
{
    return findColorPair(colorPair.first, colorPair.second);
}

ColorPalette::ConstColorIterator ColorPalette::colorBegin() const
{
    return m_colors.begin();
}

ColorPalette::ConstColorPairIterator ColorPalette::colorPairBegin() const
{
    return m_colorPairs.begin();
}

ColorPalette::ConstColorIterator ColorPalette::colorEnd() const
{
    return m_colors.end();
}

ColorPalette::ConstColorPairIterator ColorPalette::colorPairEnd() const
{
    return m_colorPairs.end();
}

size_t ColorPalette::numberOfColors() const
{
    return m_colors.size();
}

size_t ColorPalette::numberOfColorPairs() const
{
    return m_colorPairs.size();
}

inline size_t ColorPalette::colorHash(const Color& color) const
{
    return std::hash<uint32_t>()(
        (color.r << 16) |
        (color.g << 8) |
        (color.b << 0));
}

inline size_t ColorPalette::colorPairHash(const std::pair<uint16_t, uint16_t>& pair) const
{
    return std::hash<uint64_t>()(
        pair.first << 16 |
        pair.second << 0);
}
}
