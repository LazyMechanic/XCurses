#pragma once

#include <cstdint>

namespace xcur {
class Status
{
public:
    /**
     * \brief Status code
     */
    enum Code
    {
        Err = -1,
        Ok = 0
    };

    /**
     * \brief Default Status constructor. Construct the status with Ok code
     */
    Status();

    /**
     * \brief Construct the status with specific code
     * \param code Code number (e.g. Status::Code::Ok)
     */
    Status(int32_t code);

    /**
     * \brief Move Status constructor
     */
    Status(Status&&) = default;

    /**
     * \brief Default copy assignment operator
     * \return Reference to \a this
     */
    Status& operator =(const Status&) = default;

    /**
     * \brief Default move assignment operator
     * \return Reference to \a this
     */
    Status& operator =(Status&&) = default;

    /**
     * \brief Overload of the binary = operator
     * \param right Status code
     * \return Reference to /a this
     */
    Status& operator =(const int32_t& right);

	/**
	 * \brief Overload of the == operator
	 * \param right Right operand
	 * \return True if status codes are equal, false if they are different
	 */
	bool operator ==(const int32_t& right) const;

	/**
	 * \brief Overload of the == operator
	 * \param right Right operand
	 * \return True if status codes are equal, false if they are different
	 */
	bool operator ==(const Status& right) const;

	/**
	 * \brief Overload of the != operator
	 * \param right Right operand
	 * \return True if status codes are different, false if they are equal
	 */
	bool operator !=(const int32_t& right) const;

	/**
	 * \brief Overload of the != operator
	 * \param right Right operand
	 * \return True if status codes are different, false if they are equal
	 */
	bool operator !=(const Status& right) const;

    /**
     * \brief Status destructor
     */
    ~Status() = default;

    /**
     * \brief Status code
     */
    int32_t code;
};
}