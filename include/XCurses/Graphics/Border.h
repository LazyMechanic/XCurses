#pragma once

#include <XCurses/Text/Char.h>
#include <XCurses/Graphics/Widget.h>

namespace xcur {
struct BorderTraits
{
    /**
     * \brief Blank predefined border
     */
    static const BorderTraits Blank;

    /**
     * \brief Simple predefined border
     */
    static const BorderTraits Simple;

    /**
     * \brief Default predefined border
     */
    static const BorderTraits Default;

    /**
     * \brief Wide predefined border
     */
    static const BorderTraits Wide;

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

/**
 * \brief The container for window border.
 */
class Border : public Widget
{
public:
    /**
     * \brief Create Border::Default.
     */
    static Object::Ptr<Border> create();

    /**
     * \brief Create border with one char on all sides
     * \param ch Char for border
     */
    static Object::Ptr<Border> create(const Char& ch);

    /**
     * \brief Create border with specific characters.
     * \param borderTraits Border traits
     */
    static Object::Ptr<Border> create(const BorderTraits& borderTraits);

    /**
     * \brief Border destructor
     */
    ~Border() = default;

    /**
     * \brief Call function for draw the object
     */
    void draw() const override;

    /**
     * \brief Border traits
     */
    BorderTraits borderTraits;

protected:
    /**
     * \brief Construct border with specific traits
     */
    Border(const BorderTraits& borderTraits);
};
}