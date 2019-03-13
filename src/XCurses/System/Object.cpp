#include <XCurses/System/Object.h>

namespace xcur {
uint64_t Object::nextId = 0;

Object::Ptr<Object> Object::create()
{
    return std::shared_ptr<Object>(new Object());
}

uint64_t Object::getId() const
{
    return m_id;
}

Object::Object() :
    m_id(Object::nextId++)
{
}
}
