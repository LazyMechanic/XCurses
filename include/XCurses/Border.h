#pragma once

#include <cstdint>

namespace xcur {
/**
 * \brief Container for window border.
 */
class Border
{
public:
    /**
	 * \brief Default Border constructor. Creates Border::Default.
	 */
	Border();

    /**
     * \brief Construct the border with one char on all sides
     * \param ch Char for border
     */
    explicit Border(uint32_t ch);

    /**
	 * \brief Construct the border with specific characters.
	 * \param _leftSide Char for left side
	 * \param _rightSide Char for right side
	 * \param _topSide Char for top side
	 * \param _bottomSide Char for bottom side
	 * \param _topLeftCorner Char for top-left corner
	 * \param _topRightCorner Char for top-right corner
	 * \param _bottomLeftCorner Char for bottom-left corner
	 * \param _bottomRightCorner Char for bottom-right corner
	 */
	Border(uint32_t _leftSide,
		uint32_t _rightSide,
		uint32_t _topSide,
		uint32_t _bottomSide,
		uint32_t _topLeftCorner,
		uint32_t _topRightCorner,
		uint32_t _bottomLeftCorner,
		uint32_t _bottomRightCorner
	);

    /**
	 * \brief Copy Border constructor
	 */
	Border(const Border&) = default;

	/**
	 * \brief Move Border constructor
	 */
	Border(Border&&) = default;

	/**
	 * \brief Border destructor
	 */
	~Border() = default;

    /**
	 * \brief Default copy assignment operator
	 * \return Reference to \a this
	 */
	Border& operator =(const Border&) = default;

	/**
	 * \brief Default move assignment operator
	 * \return Reference to \a this
	 */
	Border& operator =(Border&&) = default;

	static const Border Blank;      //< Blank predefined border
	static const Border Simple;     //< Simple predefined border
	static const Border Default;    //< Default predefined border
	static const Border Double;     //< Double predefined border

    /**
	 * \brief Left side character
	 */
	uint32_t leftSide;

	/**
	 * \brief Right side character
	 */
	uint32_t rightSide;

	/**
	 * \brief Top side character
	 */
	uint32_t topSide;

	/**
	 * \brief Bottom side character
	 */
	uint32_t bottomSide;

	/**
	 * \brief Top-left corner character
	 */
	uint32_t topLeftCorner;

	/**
	 * \brief Top-right corner character
	 */
	uint32_t topRightCorner;

	/**
	 * \brief Bottom-left corner character
	 */
	uint32_t bottomLeftCorner;

	/**
	 * \brief Bottom-right corner character
	 */
	uint32_t bottomRightCorner;
};
}