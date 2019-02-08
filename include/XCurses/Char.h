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
