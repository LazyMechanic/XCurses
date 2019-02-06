#pragma once

#include <PDCurses/curses.h>

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
	Char();

	Char(const Char&) = default;

	Char(Char&&) = default;

	Char& operator =(const Char&) = default;

	Char& operator =(Char&&) = default;

	~Char() = default;

    /**
	 * \brief Color pair id for curses
	 */
	uint16_t colorPairId;

    /**
	 * \brief Current attr
	 */
	Attribute attr;

    /**
	 * \brief 
	 */
	uint16_t character;
};
}