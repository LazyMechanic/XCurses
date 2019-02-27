#pragma once

#include <XCurses/Char.h>

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
    explicit Border(const Char& ch);

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
    Border(Char _leftSide,
        Char _rightSide,
        Char _topSide,
        Char _bottomSide,
        Char _topLeftCorner,
        Char _topRightCorner,
        Char _bottomLeftCorner,
        Char _bottomRightCorner);

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

    static const Border Blank;      // Blank predefined border
    static const Border Simple;     // Simple predefined border
    static const Border Default;    // Default predefined border
    static const Border Wide;       // Wide predefined border

    /**
     * \brief Left side character
     */
    Char leftSide;

    /**
     * \brief Right side character
     */
    Char rightSide;

    /**
     * \brief Top side character
     */
    Char topSide;

    /**
     * \brief Bottom side character
     */
    Char bottomSide;

    /**
     * \brief Top-left corner character
     */
    Char topLeftCorner;

    /**
     * \brief Top-right corner character
     */
    Char topRightCorner;

    /**
     * \brief Bottom-left corner character
     */
    Char bottomLeftCorner;

    /**
     * \brief Bottom-right corner character
     */
    Char bottomRightCorner;
};
}