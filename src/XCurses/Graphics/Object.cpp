#include <XCurses/Graphics/Object.h>

namespace xcur {
uint64_t Object::nextId = 0;

uint64_t Object::getId() const
{
    return m_id;
}

Object::Object() :
    m_id(Object::nextId++)
{
}
}
