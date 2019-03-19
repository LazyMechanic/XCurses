#include <XCurses/Graphics/Inputtable.h>

#include <algorithm>

namespace xcur {
const Object::Ptr<Inputtable> Inputtable::None = nullptr;

Inputtable::Inputtable() :
    m_cursorPosition(0, 0),
    m_cursorState(CursorState::Normal)
{
}

void Inputtable::setCursorPosition(const Vector2u& newPosition)
{
    m_cursorPosition.x = std::min<uint32_t>(newPosition.x, m_size.x);
    m_cursorPosition.y = std::min<uint32_t>(newPosition.y, m_size.y);
}

Vector2u Inputtable::getCursorPosition() const
{
    return m_cursorPosition;
}

void Inputtable::setCursorState(CursorState newState)
{
    m_cursorState = newState;
}

CursorState Inputtable::getCursorState() const
{
    return m_cursorState;
}
}
