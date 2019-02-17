#pragma once

#include <XCurses/Drawable.h>
#include <XCurses/Behaviour.h>
#include <XCurses/ContextComponent.h>

namespace xcur {
class RootObject : virtual public ContextComponent
{
public:
    /**
	 * \brief RootObject destructor
	 */
	virtual ~RootObject() = default;

	/**
	 * \brief Call for update object state
	 * \param dt Delta time
	 */
    virtual void update(float dt) override = 0;

	/**
	 * \brief Call function for draw the object
	 */
    virtual void draw() override = 0;

protected:
    /**
	 * \brief Default root constructor
	 */
	RootObject() = default;
};
}