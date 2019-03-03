#pragma once

#include <XCurses/Text/Attribute.h>

namespace xcur {
/**
 * \brief Simple wrapper over curses chtype. Allows easy access to
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
     * \param colorPairId Color pair id
     * \param attr Attribute
     * \param ch Character
     */
    Char(uint8_t colorPairId, Attribute attr, uint16_t ch);

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
     * \brief Operator convert to uint32_t
     */
    operator uint32_t() const;

    /**
     * \brief Char destructor
     */
    ~Char() = default;

    /**
     * \brief Char with value is 0xffff (-1 in signed or 4294967295 in unsigned)
     */
    static Char Err;

    /**
     * \brief Make up color pair, attr and character in uint32_t
     * \return Curses character
     */
    uint32_t toCursesChar() const;

    /**
     * \brief Set only character value
     * \param ch Character
     */
    void setChar(uint16_t ch);

    /**
     * \brief Set attribute
     * \param attr Attribute
     */
    void setAttr(const Attribute& attr);

    /**
     * \brief Set color pair id
     * \param id Pair id
     */
    void setColorPairId(uint8_t id);

    /**
     * \brief Get only character value
     * \return Character
     */
    uint16_t getChar() const;

    /**
     * \brief Get attribute
     * \return Attribute
     */
    Attribute getAttr() const;

    /**
     * \brief Get color pair id
     * \return Color pair id
     */
    uint8_t getColorPairId() const;

private:
    /**
     * \brief Data of char
     */
    uint32_t m_data;
};
}
