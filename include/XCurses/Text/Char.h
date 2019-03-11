#pragma once

#include <XCurses/Text/Attribute.h>

namespace xcur {
/**
 * \brief Simple wrapper over curses chtype. Allows easy access to
 * color pair id, attributes and symbol. This char works only
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
     * \brief Construct the char with specific params
     * \param colorPairId Color pair id
     * \param attr Attribute
     * \param symbol Symbol
     */
    Char(uint8_t colorPairId, Attribute attr, uint16_t symbol);

	/**
	 * \brief Construct the char with specific character.
	 * Character may be ansi char, wide char or curses char
	 * \param ch Character
	 */
	Char(uint32_t ch);

    /**
     * \brief Copy char constructor
     */
    Char(const Char&) = default;

    /**
     * \brief Move char constructor
     */
    Char(Char&&) = default;

	/**
	 * \brief Overload of the binary = operator.
	 * \param right Right operand
	 * \return Reference to \a this
	 */
	Char& operator =(uint32_t right);

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
     * \brief Char destructor
     */
    ~Char() = default;

    /**
     * \brief Char with value is 0xffff (-1 in signed or 4294967295 in unsigned)
     */
    static Char Err;

    /**
     * \brief Convert color pair, attr and symbol to uint32_t
     * \return Curses character
     */
    uint32_t toCursesChar() const;

	/**
	 * \brief Get color pair id from curses char
	 * \return Color pair id
	 */
	static uint8_t getColorPairId(uint32_t ch);

    /**
     * \brief Get attribute from curses char
     * \return Attribute
     */
    static Attribute getAttribute(uint32_t ch);

	/**
	 * \brief Get character symbol from curses char
	 * \return Symbol
	 */
	static uint16_t getSymbol(uint32_t ch);

    /**
	 * \brief Color pair id
	 */
	uint8_t colorPairId;

    /**
	 * \brief Attribute
	 */
	Attribute attribute;

    /**
	 * \brief Symbol
	 */
	uint16_t symbol;
};
}
