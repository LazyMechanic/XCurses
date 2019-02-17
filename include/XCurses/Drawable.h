#pragma once

#include <XCurses/Object.h>

namespace xcur {
class Drawable : virtual public Object
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

protected:
    /**
	 * \brief Default drawable constructor
	 */
	Drawable() = default;
};
}