#pragma once

namespace xcur {
/**
 * \brief Abstract class for \a update() function.
 * You must inherit from this class for objects that has application logic
 */
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