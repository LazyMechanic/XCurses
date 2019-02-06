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
	 * \brief Construct thea attr with specific value, where value is
	 * curses attr
	 * \param ch Attribute value
	 */
	Attribute(uint32_t ch);

    /**
	 * \brief Convert attr to curses attr
	 */
	operator uint32_t() const;

    /**
	 * \brief Copy attr constructor
	 */
	Attribute(const Attribute&) = default;

    /**
	 * \brief Move attr constructor
	 */
	Attribute(Attribute&&) = default;

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
	 * \brief Find specific value in attr
	 * \param attr Attr with specific value
	 * \return True if attribute has specific attr, false if doesn't 
	 */
	bool has(const Attribute& attr) const;

    /**
	 * \brief Attribute value
	 */
	uint8_t value;
};
}