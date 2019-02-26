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
	 * \brief Construct the attr with specific value. Value like in curses ([24..16]/0x00ff0000 bits)
	 * \param attr Attribute value
	 */
	Attribute(uint32_t attr);

    /**
	 * \brief Copy attr constructor
	 */
	Attribute(const Attribute&) = default;

    /**
	 * \brief Move attr constructor
	 */
	Attribute(Attribute&&) = default;

	/**
     * \brief Change attr value. Value like in curses ([24..16]/0x00ff0000 bits)
     * \param attr Attribute
     * \return Reference to /a this
     */
	Attribute& operator =(uint32_t attr);

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

/**
 * \brief Overload of the == operator
 * This operator compares two attributes and check if they are equal.
 * \param left Left operand
 * \param right Right operand
 * \return True if attributes are equal, false if they are different
 */
bool operator ==(const Attribute& left, const Attribute& right);

/**
 * \brief Overload of the == operator
 * This operator compares the attribute and the value and check if they are equal.
 * \param left Left operand
 * \param right Right operand. Value like in curses ([24..16]/0x00ff0000 bits)
 * \return True if attributes are equal, false if they are different
 */
bool operator ==(const Attribute& left, uint32_t right);

/**
 * \brief Overload of the != operator
 * This operator compares two attributes and check if they are different.
 * \param left Left operand
 * \param right Right operand
 * \return True if attributes are different, false if they are equal
 */
bool operator !=(const Attribute& left, const Attribute& right);

/**
 * \brief Overload of the != operator
 * This operator compares the attribute and the value and check if they are different.
 * \param left Left operand
 * \param right Right operand. Value like in curses ([24..16]/0x00ff0000 bits)
 * \return True if attributes are different, false if they are equal
 */
bool operator !=(const Attribute& left, uint32_t right);

/**
 * \brief Overload of the binary | operator
 * This operator returns the component-wise logic OR of two attributes.
 * \param left Left operand
 * \param right Right operand
 * \return Result of \a left | \a right
 */
Attribute operator |(const Attribute& left, const Attribute& right);

/**
 * \brief Overload of the binary | operator
 * This operator returns the component-wise logic OR of two attributes.
 * \param left Left operand
 * \param right Right operand. Value like in curses ([24..16]/0x00ff0000 bits)
 * \return Result of \a left | \a right
 */
Attribute operator |(const Attribute& left, uint32_t right);

/**
 * \brief Overload of the binary & operator
 * This operator returns the component-wise logic AND of two attributes.
 * \param left Left operand
 * \param right Right operand
 * \return Result of \a left & \a right
 */
Attribute operator &(const Attribute& left, const Attribute& right);

/**
 * \brief Overload of the binary & operator
 * This operator returns the component-wise logic AND of two attributes.
 * \param left Left operand
 * \param right Right operand. Value like in curses ([24..16]/0x00ff0000 bits)
 * \return Result of \a left & \a right
 */
Attribute operator &(const Attribute& left, uint32_t right);

/**
 * \brief Overload of the binary | operator
 * This operator returns the component-wise logic OR of two attributes,
 * and assigns the result to the left operand
 * \param left Left operand
 * \param right Right operand
 * \return Result of \a left | \a right
 */
Attribute& operator |=(Attribute& left, const Attribute& right);

/**
 * \brief Overload of the binary | operator
 * This operator returns the component-wise logic OR of two attributes,
 * and assigns the result to the left operand
 * \param left Left operand
 * \param right Right operand. Value like in curses ([24..16]/0x00ff0000 bits)
 * \return Result of \a left | \a right
 */
Attribute& operator |=(Attribute& left, uint32_t right);

/**
 * \brief Overload of the binary & operator
 * This operator returns the component-wise logic AND of two attributes,
 * and assigns the result to the left operand
 * \param left Left operand
 * \param right Right operand
 * \return Result of \a left & \a right
 */
Attribute& operator &=(Attribute& left, const Attribute& right);

/**
 * \brief Overload of the binary & operator
 * This operator returns the component-wise logic AND of two attributes,
 * and assigns the result to the left operand
 * \param left Left operand
 * \param right Right operand. Value like in curses ([24..16]/0x00ff0000 bits)
 * \return Result of \a left & \a right
 */
Attribute& operator &=(Attribute& left, uint32_t right);
}