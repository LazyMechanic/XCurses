#pragma once

#include <XCurses/Text/Attribute.h>

#pragma pack(push, 1)

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
    enum Key
    {
        Backspace = 0x08,
        Tab = 0x09,
        LineFeed = 0x0A,
        Delete = 0x7F,
    };

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
     * \brief Overload of the == operator
     * This operator compares two chars and check if their symbol values are equal
     * \param right Right operand
     * \return True if symbol values of chars are equal, false if they are different
     */
    bool operator ==(const Char& right) const;

    /**
     * \brief Overload of the == operator
     * This operator compares char and curses char (uint32_t) and check if their symbol values
     * are equal
     * \param right Right operand
     * \return True if symbol values of chars are equal, false if they are different
     */
    bool operator ==(uint32_t right) const;

    /**
     * \brief Overload of the != operator
     * This operator compares two chars and check if their symbol values are different
     * \param right Right operand
     * \return True if symbol values of chars are different, false if they are equal
     */
    bool operator !=(const Char& right) const;

    /**
     * \brief Overload of the != operator
     * This operator compares char and curses char (uint32_t) and check if their symbol values
     * are different
     * \param right Right operand
     * \return True if symbol values of chars are different, false if they are equal
     */
    bool operator !=(uint32_t right) const;

    /**
     * \brief Overload of the > operator
     * This operator compares two chars and check if symbol value \a this more than 
     * symbol value of \a right
     * \param right Right operand
     * \return True if symbol value of \a this is more than symbol value of \a right,
     * false otherwise
     */
    bool operator >(const Char& right) const;

    /**
     * \brief Overload of the > operator
     * This operator compares char and curses char (uint32_t) and check if symbol value 
     * of \a this more than symbol value of \a right
     * \param right Right operand
     * \return True if symbol value of \a this is more than symbol value of \a right,
     * false otherwise
     */
    bool operator >(uint32_t right) const;

    /**
     * \brief Overload of the < operator
     * This operator compares two chars and check if symbol value \a this less than
     * symbol value of \a right
     * \param right Right operand
     * \return True if symbol value of \a this is less than symbol value of \a right,
     * false otherwise
     */
    bool operator <(const Char& right) const;

    /**
     * \brief Overload of the < operator
     * This operator compares char and curses char (uint32_t) and check if symbol value
     * of \a this less than symbol value of \a right
     * \param right Right operand
     * \return True if symbol value of \a this is less than symbol value of \a right,
     * false otherwise
     */
    bool operator <(uint32_t right) const;

    /**
     * \brief Overload of the >= operator
     * This operator compares two chars and check if symbol value \a this more or equal than
     * symbol value of \a right
     * \param right Right operand
     * \return True if symbol value of \a this is more or equal than symbol value of \a right,
     * false otherwise
     */
    bool operator >=(const Char& right) const;

    /**
     * \brief Overload of the >= operator
     * This operator compares char and curses char (uint32_t) and check if symbol value
     * of \a this more or equal than symbol value of \a right
     * \param right Right operand
     * \return True if symbol value of \a this is more or equal than symbol value of \a right,
     * false otherwise
     */
    bool operator >=(uint32_t right) const;

    /**
     * \brief Overload of the <= operator
     * This operator compares two chars and check if symbol value \a this less or equal than
     * symbol value of \a right
     * \param right Right operand
     * \return True if symbol value of \a this is less or equal than symbol value of \a right,
     * false otherwise
     */
    bool operator <=(const Char& right) const;

    /**
     * \brief Overload of the <= operator
     * This operator compares char and curses char (uint32_t) and check if symbol value
     * of \a this less or equal than symbol value of \a right
     * \param right Right operand
     * \return True if symbol value of \a this is less or equal than symbol value of \a right,
     * false otherwise
     */
    bool operator <=(uint32_t right) const;

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
     * \brief Convert char to ansi char.
     * Character that does not fit in the target encoding are
     * discarded from the returned char.
     * \return Ansi char
     */
    char toAnsiChar() const;

    /**
     * \brief Convert char to wide char.
     * Character that does not fit in the target encoding are
     * discarded from the returned char.
     * \return Wide char
     */
    wchar_t toWideChar() const;

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
     * \brief Check if \a left and \a right is equal including color pair id and attribute
     * \param left Left operand
     * \param right Left operand
     * \return True if color pair id, attribute and symbol are equal in two chars, false if
     * they different
     */
    static bool isFullEqual(const Char& left, const Char& right);

    /**
     * \brief Symbol
     */
    uint16_t symbol;

    /**
     * \brief Attribute
     */
    Attribute attribute;

    /**
     * \brief Color pair id
     */
    uint8_t colorPairId;
};
}

#pragma pack(pop)
