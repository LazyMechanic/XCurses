#pragma once

#include <list>
#include <memory>

#include <XCurses/Border.h>
#include <XCurses/Widget.h>
#include <XCurses/Vector.h>
#include <XCurses/Container.h>

struct _win;

namespace xcur {

class Window :
    public Container,
    public std::enable_shared_from_this<Window>
{
public:
    /**
     * \brief Vector2<uint32_t> alias
     */
    using Position = Vector2<uint32_t>;

    /**
     * \brief Default Window constructor
     */
    Window();

    /**
     * \brief Window destructor
     */
    virtual ~Window();

    /**
     * \brief Call for update object state
     * \param dt Delta time
     */
    virtual void update(float dt) override;

    /**
     * \brief Call function for draw the object
     */
    void draw() override final;



    /**
     * \brief Add character into window and advance cursor position
     * \param ch Character
     */
    void addChar(const Char& ch) const;

    /**
     * \brief Add character into window on the position and advance 
     * cursor position
     * \param ch Character
     * \param pos Position
     */
    void addChar(const Char& ch, const Window::Position& pos) const;

    /**
     * \brief Move cursor to new position. If new position is out of window then do nothing
     * \param newPos New position
     */
    void moveCursor(const Window::Position& newPos) const;

    /**
     * \brief Get window cursor position
     * \return Position
     */
    Window::Position getCursorPosition() const;

    /**
     * \brief Set new border
     * \param border Border
     */
    virtual void setBorder(const Border& border) final;

    /**
     * \brief Get current border
     * \return Border
     */
    virtual Border getBorder() const final;

    /**
     * \brief Get curses window
     * \return Raw ptr to curses window
     */
    virtual _win* getCursesWin() const final;

protected:
    /**
     * \brief Call curses function for redraw border
     */
    void updateCursesBorder() const;

    /**
     * \brief Get shared ptr from this object
     * \return Smart ptr to this
     */
    Object::Ptr<Window> getSharedFromThis();

    /**
     * \brief Border container
     */
    Border m_border;

    /**
     * \brief Background char
     */
    Char m_backgroundChar;

private:    
    /**
     * \brief PDCurses window pointer
     */
    _win* m_win;
};
}
