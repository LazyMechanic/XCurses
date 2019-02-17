#pragma once

#include <XCurses/Object.h>

namespace xcur {
class Behaviour : virtual public Object
{
public:
    /**
	 * \brief Behaviour destructor
	 */
	virtual ~Behaviour() = default;

    /**
	 * \brief Call for update object state
	 * \param dt Delta time
	 */
	virtual void update(float dt) = 0;

protected:
	Behaviour() = default;
};
}