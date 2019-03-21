#include <XCurses/Graphics/Inputtable.h>

#include <algorithm>

namespace xcur {
Inputtable::Inputtable(Vector2u& size) :
    m_screenCursorPosition(0, 0),
    m_cursorState(CursorState::Normal),
    m_widgetSize(size)
{
}

void Inputtable::setScreenCursorPosition(const Vector2u& position)
{
    m_screenCursorPosition.x = std::min<uint32_t>(position.x, m_widgetSize.x);
    m_screenCursorPosition.y = std::min<uint32_t>(position.y, m_widgetSize.y);
}

Vector2u Inputtable::getCursorPosition() const
{
    return m_screenCursorPosition;
}

void Inputtable::setCursorState(CursorState state)
{
    m_cursorState = state;
}

CursorState Inputtable::getCursorState() const
{
    return m_cursorState;
}
}
