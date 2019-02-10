#pragma once

#include <list>
#include <functional>
#include <unordered_map>

#include <XCurses/Color.h>
#include <XCurses/Status.h>

namespace xcur {
class ColorPalette
{
public:	
    /**
     * \brief Const iterator alias
     */
    using ConstColorIterator = std::unordered_map<Color, uint16_t, std::function<size_t(const Color&)>>::const_iterator;
	
    /**
     * \brief Const iterator alias
     */
    using ConstColorPairIterator = std::unordered_map<std::pair<uint16_t, uint16_t>, uint8_t, std::function<size_t(const std::pair<uint16_t, uint16_t>&)>>::const_iterator;

    /**
	 * \brief Default ColorPalette constructor. Construct empty palette 
	 */
	ColorPalette();

	/**
	 * \brief Construct color palette with specific colors. If the number of colors in list
	 * is greater than the maximum, then inserting only first N colors where
	 * N is (maxNumberOfColors - 3) including default colors. 
	 * Same colors are discarded.
	 * If after create palette don't set colors by default then first call initPair() will do it
	 * if possible (colors are exist)
	 * \param colorList Color palette
	 */
	ColorPalette(const std::list<Color>& colorList);

    /**
	 * \brief Copy ColorPalette constructor
	 */
	ColorPalette(const ColorPalette&) = default;

    /**
	 * \brief Move ColorPalette constructor
	 */
	ColorPalette(ColorPalette&&) = default;

	/**
	 * \brief Default copy assignment operator
	 * \return Reference to \a this
	 */
	ColorPalette& operator =(const ColorPalette&) = default;
    
	/**
	 * \brief Default move assignment operator
	 * \return Reference to \a this
	 */
	ColorPalette& operator =(ColorPalette&&) = default;

    /**
	 * \brief ColorPalette destructor
	 */
	~ColorPalette() = default;

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
	 * \return Ok if the color swapping is successfully, Err if new color already exists or
	 * color for swap not found in palette
	 */
	Status swapColor(const Color& from, const Color& to);

    /**
	 * \brief Change colors by default. After that the calling getColorPairId(...) with wrong colors
	 * returns default id
	 * \param foreground Foreground (text) color
	 * \param background Background color
	 * \return Ok if successful, Err if colors don't found
	 */
	Status setDefaultColorPair(const Color& foreground, const Color& background);

	/**
	 * \brief Change colors by default. After that the calling getColorPairId(...) with wrong colors
	 * returns default id
	 * \param colorPair Foreground and background color
	 * \return Ok if successful, Err if colors don't found
	 */
	Status setDefaultColorPair(const std::pair<Color, Color>& colorPair);

    /**
	 * \brief Get id of default color pair
	 * \return Color pair id
	 */
	uint8_t getDefaultColorPairId() const;

    /**
	 * \brief Init color pair
	 * \param foreground Foreground (text) color
	 * \param background Background color
	 * \return Ok if successful, Err if colors don't found or if pair already exists or if
	 * palette stored maximum of color pairs
	 */
	Status initColorPair(const Color& foreground, const Color& background);

	/**
	 * \brief Init color pair
	 * \param colorPair Foreground and background color
	 * \return Ok if successful, Err if colors don't found or if pair already exists or if
	 * palette stored maximum of color pairs
	 */
	Status initColorPair(const std::pair<Color, Color>& colorPair);

    /**
	 * \brief Get the color pair id. If the pair doesn't exist then init them and return the 
	 * previously created pair
	 * \param foreground Foreground (text) color
	 * \param background Background color
	 * \return Needed pair id if colors are existed, Default pair id (or 0) if colors not found or
	 * if color pair nonexistent and palette stored maximum of color pairs
	 */
	uint8_t getColorPairId(const Color& foreground, const Color& background);

	/**
	 * \brief Get the color pair id. If the pair doesn't exist then init them and return the
	 * previously created pair
	 * \param colorPair Foreground and background color
	 * \return Needed pair id if colors are existed, Default pair id (or 0) if colors not found or
	 * if color pair nonexistent and palette stored maximum of color pairs
	 */
	uint8_t getColorPairId(const std::pair<Color, Color>& colorPair);

	/**
     * \brief Find the color and its id in palette
     * \param color Color in palette
     * \return Const iterator to the pair of color and id
     */
	ConstColorIterator findColor(const Color& color) const;

	/**
	 * \brief Find the pair of foreground and background and id
	 * \param foreground Foreground (text) color
	 * \param background Background color
	 * \return Const iterator to the pair of pair of foreground and background and id
	 */
	ConstColorPairIterator findColorPair(const Color& foreground, const Color& background) const;

	/**
	 * \brief Find the pair of foreground and background and id
	 * \param colorPair Foreground and background color
	 * \return Const iterator to the pair of pair of foreground and background and id
	 */
	ConstColorPairIterator findColorPair(const std::pair<Color, Color>& colorPair) const;

    /**
	 * \brief Wrapper over color begin() const iterator
	 * \return Const begin iterator
	 */
	ConstColorIterator colorBegin() const;

    /**
	 * \brief Wrapper over color pair begin() const iterator
	 * \return Const begin iterator
	 */
	ConstColorPairIterator colorPairBegin() const;

	/**
	 * \brief Wrapper over color end() const iterator
	 * \return Const end iterator
	 */
	ConstColorIterator colorEnd() const;

	/**
	 * \brief Wrapper over color pair end() const iterator
	 * \return Const end iterator
	 */
	ConstColorPairIterator colorPairEnd() const;

    /**
	 * \brief Get size of color map
	 * \return Size
	 */
	size_t numberOfColors() const;

    /**
	 * \brief Get size of color pair map
	 * \return Size
	 */
	size_t numberOfColorPairs() const;

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
	size_t colorPairHash(const std::pair<uint16_t, uint16_t>& pair) const;

    /**
	 * \brief Current color id for curses
	 */
	uint16_t m_curColorId;

	/**
	 * \brief Current color pair id for curses
	 */
	uint8_t m_curColorPairId;

	/**
	 * \brief Default color pair id
	 */
	uint8_t m_defaultColorPairId;

    /**
	 * \brief All colors in palette
	 */
	std::unordered_map<Color, uint16_t, std::function<size_t(const Color&)>> m_colors;

    /**
	 * \brief All initialized color pairs. First uint16_t is foreground id, second - background
	 */
	std::unordered_map<std::pair<uint16_t, uint16_t>, uint8_t, std::function<size_t(const std::pair<uint16_t, uint16_t>&)>> m_colorPairs;
};
}
