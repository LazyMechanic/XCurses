#pragma once

#include <cstdint>

namespace xcur {
class Attribute
{
public:
    /**
	 * \brief Default attr constructor. Construct the attribute with 0 value
	 */
	Attribute();

    /**
	 * \brief Construct the attr with specific value
	 * \param attr Attribute value
	 */
	Attribute(uint8_t attr);

    /**
	 * \brief Copy attr constructor
	 */
	Attribute(const Attribute&) = default;

    /**
	 * \brief Move attr constructor
	 */
	Attribute(Attribute&&) = default;

	/**
     * \brief Change attr value
     * \param attr Attribute
     * \return Reference to /a this
     */
	Attribute& operator =(uint8_t attr);

    /**
	 * \brief Default copy assignment operator
	 * \return Reference to /a this
	 */
	Attribute& operator =(const Attribute&) = default;

	/**
	 * \brief Default move assignment operator
	 * \return Reference to \a this
	 */
	Attribute& operator =(Attribute&&) = default;

    /**
	 * \brief Attribute destructor
	 */
	~Attribute() = default;

	/**
	 * \brief Convert member value to curses style attr
	 * \return Curses style attr
	 */
	uint32_t toCursesAttr() const;

    /**
	 * \brief Convert curses attr to member value
	 * \param attr 
	 * \return 
	 */
	static uint8_t fromCursesAttr(uint32_t attr);

    /**
	 * \brief Find specific value in attr
	 * \param attr Attr with specific value
	 * \return True if attribute has specific attr, false if doesn't 
	 */
	bool has(const Attribute& attr) const;

	static const Attribute Normal;      // Normal predefined attribute
	static const Attribute AltCharset;  // AltCharset predefined attribute
	static const Attribute Right;       // Right predefined attribute
	static const Attribute Left;        // Left predefined attribute
	static const Attribute Italic;      // Italic predefined attribute
	static const Attribute Underline;   // Underline predefined attribute
	static const Attribute Reverse;     // Reverse predefined attribute
	static const Attribute Blink;       // Blink predefined attribute
	static const Attribute Bold;        // Bold predefined attribute

    /**
	 * \brief Attribute value
	 */
	uint8_t value;
};
}