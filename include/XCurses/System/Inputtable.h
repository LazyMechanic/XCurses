#pragma once

#include <XCurses/System/Vector2.h>
#include <XCurses/Graphics/Widget.h>
#include <XCurses/System/CursorState.h>

namespace xcur {
class Inputtable : public Widget
{
public:
    friend class Window;

    /**
     * \brief Create Inputtable
     * \return Smart ptr to Inputtable
     */
    static Object::Ptr<Inputtable> create();

    /**
     * \brief Inputtable destructor.
     */
    virtual ~Inputtable() = default;

    /**
     * \brief Set cursor position. 
     * Position coordinates that exceed widget size are clamped to widget size.
     * \param newPosition New cursor position
     */
    void setCursorPosition(const Vector2u& newPosition);

    /**
     * \brief Get current cursor position
     * \return Coordinate
     */
    Vector2u getCursorPosition() const;

    /**
     * \brief Set new cursor state
     * \param newState Cursor state
     */
    void setCursorState(CursorState newState);

    /**
     * \brief Get cursor state
     * \return Cursor state
     */
    CursorState getCursorState() const;

    /**
     * \brief Get active state
     * \return True if widget is active, false otherwise
     */
    bool isActive() const;

protected:
    /**
     * \brief Default Inputtable constructor.
     */
    Inputtable();

private:
    /**
     * \brief Current cursor position
     */
    Vector2u m_cursorPosition;

    /**
     * \brief Cursor state
     */
    CursorState m_cursorState;

    /**
     * \brief Is widget active
     */
    bool m_isActive;
};
}