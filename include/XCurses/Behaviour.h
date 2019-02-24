#pragma once

namespace xcur {
class Behaviour
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
};
}