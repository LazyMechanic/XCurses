#pragma once

#include <XCurses/System/Vector2.h>
#include <XCurses/System/CursorState.h>

namespace xcur {
/**
 * \brief Inherit this class if you need widget with input field
 */
class Inputtable
{
public:
    /**
     * \brief Inputtable destructor.
     */
    virtual ~Inputtable() = default;

    /**
     * \brief Set screen cursor position. 
     * Position coordinates that exceed widget size are clamped to widget size.
     * \param position New cursor position
     */
    void setScreenCursorPosition(const Vector2u& position);

    /**
     * \brief Get current cursor position
     * \return Coordinate
     */
    Vector2u getCursorPosition() const;

    /**
     * \brief Set new cursor state
     * \param state Cursor state
     */
    void setCursorState(CursorState state);

    /**
     * \brief Get cursor state
     * \return Cursor state
     */
    CursorState getCursorState() const;

protected:
    /**
     * \brief Default Inputtable constructor
     * \param size Widget size. The value do not changes by this class.
     * It needed for clamping cursor position
     */
    explicit Inputtable(Vector2u& size);

    /**
     * \brief Current screen cursor position
     */
    Vector2u m_screenCursorPosition;

    /**
     * \brief Cursor state
     */
    CursorState m_cursorState;

private:
    /**
     * \brief Heir widget size
     */
    Vector2u& m_widgetSize;
};
}