#pragma once

#include <XCurses/System/Vector2.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
class RootContainer : public Container
{
public:
    /**
     * \brief Create RootContainer
     * \return Smart ptr to RootContainer
     */
    static Object::Ptr<RootContainer> create();

    /**
     * \brief Call for update object state
     * \param dt Delta time
     */
    void update(float dt) override;

private:
    /**
     * \brief Default RootContainer constructor
     */
    RootContainer();
};
}