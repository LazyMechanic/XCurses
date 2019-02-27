#pragma once

#include <cstdint>

namespace xcur {
class Position {
public:
    /**
	 * \brief Default Position constructor. Construct this with 0
	 * position
	 */
	Position();

    /**
     * \brief Position constructor with specific params
     * \param x X coordinate
     * \param y Y coordinate
     */
    Position(uint32_t x, uint32_t y);

    /**
	 * \brief Copy Position constructor
	 */
	Position(const Position&) = default;

	/**
	 * \brief Copy Position constructor
	 */
	Position(Position&&) = default;

	/**
	 * \brief Default copy assignment operator
	 * \return Reference to \a this
	 */
	Position& operator =(const Position&) = default;

	/**
	 * \brief Default move assignment operator
	 * \return Reference to \a this
	 */
	Position& operator =(Position&&) = default;

    /**
	 * \brief Position destructor
	 */
	~Position() = default;

    /**
	 * \brief X coordinate
	 */
	uint32_t x;

    /**
	 * \brief Y coordinate
	 */
	uint32_t y;
};

/**
 * \brief Overload of the == operator
 * This operator compares two positions and check if they are equal.
 * \param left Left operand
 * \param right Right operand
 * \return True if positions are equal, false if they are different
 */
bool operator ==(const Position& left, const Position& right);

/**
 * \brief Overload of the != operator.
 * This operator compares two positions and check if they are different.
 * \param left Left operand
 * \param right Right operand
 * \return True if positions are different, false if they are equal
 */
bool operator !=(const Position& left, const Position& right);

/**
 * \brief Overload of the binary + operator.
 * This operator returns the component-wise sum of two positions
 * \param left Left operand
 * \param right Right operand
 * \return Result of \a left + \a right
 */
Position operator +(const Position& left, const Position& right);

/**
 * \brief Overload of the binary - operator.
 * This operator returns the component-wise subtraction of two positions.
 * \param left Left operand
 * \param right Right operand
 * \return Result of \a left - \a right
 */
Position operator -(const Position& left, const Position& right);

/**
 * \brief Overload of the binary += operator.
 * This operator computes the component-wise sum of two positions,
 * and assigns the result to the left operand.
 * \param left Left operand
 * \param right Right operand
 * \return Reference to \a left
 */
Position& operator +=(Position& left, const Position& right);

/**
 * \brief Overload of the binary -= operator.
 * This operator computes the component-wise subtraction of two positions,
 * and assigns the result to the left operand.
 * \param left Left operand
 * \param right Right operand
 * \return Reference to \a left
 */
Position& operator -=(Position& left, const Position& right);
}