#include <XCurses/ColorPalette.h>

namespace xcur {
const uint16_t ColorPalette::maxNumberOfColors = 16;
const uint16_t ColorPalette::maxNumberOfColorPairs = 256;

ColorPalette::ColorPalette(const std::initializer_list<Color>& list) :
    m_curColorId(0),
	m_colors(0, std::bind(&ColorPalette::colorHash, this, std::placeholders::_1)),
	m_colorPairs(0, std::bind(&ColorPalette::colorPairHash, this, std::placeholders::_1))
{
    if (list.size() > maxNumberOfColors) {
		throw std::length_error("Number of colors in palette more than maximum");
    }

	for (auto it = list.begin(); it != list.end(); ++it) {
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

inline size_t ColorPalette::colorHash(const Color& color) const
{
	size_t hash = std::hash<uint32_t>()(
		(color.r << 16) |
		(color.g << 8) |
		(color.b << 0));
	return hash;
}

inline size_t ColorPalette::colorPairHash(const std::pair<Color, Color>& pair) const
{
	size_t hash = std::hash<uint64_t>()(
		(uint64_t(pair.first.r) << 40) |
		(uint64_t(pair.first.g) << 32) |
		(uint64_t(pair.first.b) << 24) |
		(pair.second.r << 16) |
		(pair.second.g << 8) |
		(pair.second.b << 0));
	return hash;
}
}
