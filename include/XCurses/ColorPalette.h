#pragma once

#include <functional>
#include <unordered_map>

#include <XCurses/Color.h>
#include <XCurses/Status.h>

namespace xcur {
class ColorPalette
{
public:
	friend class ColorSystem;
    /**
	 * \brief Construct color palette with specific colors
	 * \param list Color palette
	 */
	ColorPalette(const std::initializer_list<Color>& list);

    /**
	 * \brief 
	 * \param color 
	 * \return Ok if color insert is successful, Err if the color already exists or
	 * color palette is full (number of colors is maximum)
	 */
	Status addColor(const Color& color);

    /**
	 * \brief Swap color in palette
	 * \param from Color in palette for swap
	 * \param to New color
	 * \return Ok if color swapping is successfully, Err if new color already exists or
	 * color for swap not found in palette
	 */
	Status swapColor(const Color& from, const Color& to);

    /**
	 * \brief Swap color in palette
	 * \param from Color id in palette for swap
	 * \param to New color
	 * \return Ok if color swapping is successfully, Err if new color already exists or
	 * color for swap not found in palette
	 */
	Status swapColor(uint16_t from, const Color& to);

    /**
	 * \brief Maximum number of colors. Depends on terminal
	 */
	static const uint16_t maxNumberOfColors;

    /**
	 * \brief Maximum number of color pairs
	 */
	static const uint16_t maxNumberOfColorPairs;

private:
    /**
	 * \brief Function for hashing color
	 * \param color Hashable object
	 * \return Hash
	 */
	size_t colorHash(const Color& color) const;

	/**
	 * \brief Function for hashing color pair
	 * \param pair Hashable object
	 * \return Hash
	 */
	size_t colorPairHash(const std::pair<Color, Color>& pair) const;

    /**
	 * \brief Current color id for curses
	 */
	uint16_t m_curColorId;

    /**
	 * \brief All colors in palette
	 */
	std::unordered_map<Color, uint16_t, std::function<size_t(const Color&)>> m_colors;

    /**
	 * \brief All initialized color pairs
	 */
	std::unordered_map<std::pair<Color, Color>, uint16_t, std::function<size_t(const std::pair<Color, Color>&)>> m_colorPairs;
};
}
