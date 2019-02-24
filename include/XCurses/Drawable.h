#pragma once

namespace xcur {
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