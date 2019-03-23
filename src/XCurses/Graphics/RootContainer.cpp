#include <XCurses/Graphics/RootContainer.h>

#include <XCurses/System/Curses.h>

namespace xcur {
Object::Ptr<RootContainer> RootContainer::create()
{
    return std::shared_ptr<RootContainer>(new RootContainer());
}

void RootContainer::update(float dt)
{
    setSize(Curses::getTerminalSize());
}

RootContainer::RootContainer() :
    Container(Area(Vector2i::Zero, Curses::getTerminalSize()))
{
}
}
