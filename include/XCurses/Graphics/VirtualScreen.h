#pragma once

#include <vector>

#include <XCurses/Text/Char.h>
#include <XCurses/System/Object.h>
#include <XCurses/System/Vector2.h>
#include <XCurses/System/Inputtable.h>
#include <XCurses/Graphics/Drawable.h>
#include <XCurses/Graphics/Behaviour.h>

struct _win;

namespace xcur { 
class VirtualScreen :
    public Object,
    public Drawable,
    public Behaviour
{
public:
    /**
     * \brief Create VirtualScreen
     * \return Smart ptr to VirtualScreen
     */
    static Object::Ptr<VirtualScreen> create();

    /**
     * \brief VirtualScreen destructor
     */
    ~VirtualScreen() = default;

    /**
     * \brief Call for update object state
     * \param dt Delta time
     */
    void update(float dt) override;

    /**
     * \brief Call for draw object
     */
    void draw() const override;

    /**
     * \brief Add character in virtual screen. If position more than screen size then
     * do nothing
     * \param ch Character
     * \param position Position
     */
    void addChar(const Char& ch, const Vector2u& position);

    /**
     * \brief Set active inputtable widget
     * \param inputWidget Widget which need set active. If it is Inputtable::None then off cursor
     */
    void setActiveInputWidget(Object::Ptr<Inputtable> inputWidget);

    /**
     * \brief Get active inputtable widget
     * \return Smart ptr to active inputtable widget
     */
    Object::Ptr<Inputtable> getActiveInputWidget() const;

    /**
     * \brief Clear screen
     */
    void clear() const;

    /**
     * \brief Resize screen
     * \param size New size
     */
    void resize(const Vector2u& size);

    /**
     * \brief Get ptr to curses window
     * \return Ptr to curses window
     */
    _win* getCursesWindow() const;

private:
    /**
     * \brief Default VirtualScreen constructor. Construct window with terminal size
     */
    VirtualScreen();

    /**
     * \brief State of refresh
     */
    bool m_screenNeedRefresh;

    /**
     * \brief Virtual screen size
     */
    Vector2u m_size;

    /**
     * \brief Current cursor position
     */
    Vector2u m_cursorPosition;

    /**
     * \brief Cursor state
     */
    CursorState m_cursorState;

    /**
     * \brief Active input widget
     */
    Object::WeakPtr<Inputtable> m_activeInputWidget;

    /**
     * \brief Curses window
     */
    _win* m_cursesWindow;
};
}
