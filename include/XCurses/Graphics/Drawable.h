#pragma once

namespace xcur {
/**
 * \brief Abstract class for \a draw() function.
 * You must inherit from this class for objects that can drawable
 */
class Drawable
{
public:
    /**
     * \brief Drawable destructor
     */
    virtual ~Drawable() = default;

    /**
     * \brief Call function for draw the object
     */
    virtual void draw() = 0;
};
}