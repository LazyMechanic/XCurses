#include <XCurses/ColorPalette.h>

namespace xcur {
const uint16_t ColorPalette::maxNumberOfColors = 16;
const uint16_t ColorPalette::maxNumberOfColorPairs = 256;

ColorPalette::ColorPalette() :  
    m_curColorId(0),
    m_curColorPairId(0),
	m_colors(0, std::bind(&ColorPalette::colorHash, this, std::placeholders::_1)),
	m_colorPairs(0, std::bind(&ColorPalette::colorPairHash, this, std::placeholders::_1))
{
}

ColorPalette::ColorPalette(const std::list<Color>& colorList) :
    m_curColorId(0),
	m_curColorPairId(0),
	m_colors(0, std::bind(&ColorPalette::colorHash, this, std::placeholders::_1)),
	m_colorPairs(0, std::bind(&ColorPalette::colorPairHash, this, std::placeholders::_1))
{
	for (auto it = colorList.begin(); it != colorList.end() && m_curColorId >= maxNumberOfColors; ++it) {
		m_colors[*it] = m_curColorId++;
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

    // If all right then insert new color and delete previous
	m_colors[to] = fromIt->second;
	m_colors.erase(fromIt);

	return Status::Ok;
}

Status ColorPalette::swapColor(uint16_t from, const Color& to)
{
	auto toIt = m_colors.find(to);
	// If new color already exists
	if (toIt != m_colors.end()) {
		return Status::Err;
	}

	auto fromIt = m_colors.begin();
    for (; fromIt != m_colors.end(); ++fromIt) {
        // If the color in palette is found
        if (fromIt->second == from) {
			break;
        }
    }

	// If the color in palette not found
	if (fromIt == m_colors.end()) {
		return Status::Err;
	}

	// If all right then insert new color and delete previous
	m_colors[to] = fromIt->second;
	m_colors.erase(fromIt);

	return Status::Ok;
}

inline ColorPalette::ConstColorIterator ColorPalette::findColor(const Color& color) const
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
	auto foregroundIt = m_colors.find(colorPair.first);
	auto backgroundIt = m_colors.find(colorPair.second);

	if (foregroundIt == m_colors.end() ||
		backgroundIt == m_colors.end())
	{
		return m_colorPairs.end();
	}

	return m_colorPairs.find(std::make_pair(foregroundIt->second, backgroundIt->second));
}

inline ColorPalette::ConstColorIterator ColorPalette::colorBegin() const
{
	return m_colors.begin();
}

inline ColorPalette::ConstColorPairIterator ColorPalette::colorPairBegin() const
{
	return m_colorPairs.begin();
}

inline ColorPalette::ConstColorIterator ColorPalette::colorEnd() const
{
	return m_colors.end();
}

inline ColorPalette::ConstColorPairIterator ColorPalette::colorPairEnd() const
{
	return m_colorPairs.end();
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
