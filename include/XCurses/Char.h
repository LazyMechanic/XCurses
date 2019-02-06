#pragma once

#include <utility>

#include <PDCurses/curses.h>

#include <XCurses/Color.h>
#include <XCurses/Status.h>
#include <XCurses/Attribute.h>

namespace xcur {
/**
 * \brief Simply wrapper over curses chtype. Allows easy access to
 * color pair id, attributes and raw character. This char works only
 * with wide character (2 bytes for encoding) and support UCS-2 unicode
 * encoding
 * to 
 */
class Char
{
public:
    /**
	 * \brief Default char constructor. Construct the char with normal attribute
	 * 0 color pair and 0 character
	 */
	Char();

    /**
	 * \brief Construct the char with specific character
	 * \param ch Character
	 */
	Char(uint16_t ch);

    /**
	 * \brief Construct the char with specific params
	 * \param _colorPairId Color pair id
	 * \param _attr Attribute
	 * \param ch Character
	 */
	Char(uint8_t _colorPairId, Attribute _attr, uint16_t ch);

    /**
	 * \brief Copy char constructor
	 */
	Char(const Char&) = default;

    /**
	 * \brief Move char constructor
	 */
	Char(Char&&) = default;

    /**
	 * \brief Default copy assignment operator
	 * \return Reference to \a this
	 */
	Char& operator =(const Char&) = default;

    /**
	 * \brief Default move assignment operator
	 * \return Reference to \a this
	 */
	Char& operator =(Char&&) = default;

	/**
	 * \brief Change character
	 * \param ch Character
	 * \return Reference to /a this
	 */
	Char& operator =(uint16_t ch);

    /**
	 * \brief Char destructor
	 */
	~Char() = default;

    /**
	 * \brief Make up color pair, attr and character in uint32_t
	 * \return Curses character
	 */
	uint32_t toCursesChar() const;

    /**
	 * \brief Update foreground color
	 * \param foreground Foreground (text) color
	 * \return Ok if the color exists in current palette, Err if the color
	 * not found
	 */
	Status setForeground(const Color& foreground);

	/**
	 * \brief Update background color
	 * \param background Background color
	 * \return Ok if the color exists in current palette, Err if the color
	 * not found
	 */
	Status setBackground(const Color& background);

    /**
	 * \brief Update both colors
	 * \param foreground Foreground (text) color
	 * \param background Background color
	 * \return Ok if colors exist in current palette, Err if the colors
	 * not found
	 */
	Status setColors(const Color& foreground, const Color& background);

	/**
	 * \brief Update both colors
	 * \param pair Foreground (text) and background color respectively 
	 * \return Ok if colors exist in current palette, Err if the colors
	 * not found
	 */
	Status setColors(const std::pair<Color, Color>& pair);

    /**
	 * \brief Get foreground color
	 * \return foreground color
	 */
	Color getForeground() const;

    /**
	 * \brief Get background color
	 * \return Background color
	 */
	Color getBackground() const;

    /**
	 * \brief Get both colors
	 * \return Pair of foreground and background respectively
	 */
	std::pair<Color, Color> getColors() const;

    /**
	 * \brief Color pair id for curses
	 */
    uint8_t colorPairId;

    /**
	 * \brief Current attr
	 */
	Attribute attr;

    /**
	 * \brief Character
	 */
	uint16_t character;
};
}
