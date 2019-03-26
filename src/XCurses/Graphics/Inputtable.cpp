#include <XCurses/Graphics/Inputtable.h>

#include <algorithm>

namespace xcur {
Inputtable::Inputtable(Vector2i& size) :
    m_screenCursorPosition(0, 0),
    m_cursorState(CursorState::Normal),
    m_widgetSize(size)
{
}

void Inputtable::setScreenCursorPosition(const Vector2i& position)
{
    m_screenCursorPosition.x = std::min(position.x, m_widgetSize.x);
    m_screenCursorPosition.y = std::min(position.y, m_widgetSize.y);
}

Vector2i Inputtable::getScreenCursorPosition() const
{
    return m_screenCursorPosition;
}

void Inputtable::setScreenCursorState(CursorState state)
{
    m_cursorState = state;
}

CursorState Inputtable::getCursorState() const
{
    return m_cursorState;
}
}
