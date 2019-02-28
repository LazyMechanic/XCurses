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
    public Container
{
public:
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
     * \brief Add character into window on the position and advance cursor position.
     * If position is out of window then do nothing
     * \param ch Character
     * \param pos Position
     */
    void addChar(const Char& ch, const Vector2u& pos) const;

    /**
     * \brief Move cursor to new position. If new position is out of window then do nothing
     * \param newPos New position
     */
    void setCursorPosition(const Vector2u& newPos) const;

    /**
	 * \brief Get cursor position x component
	 * \return X coordinate
	 */
	uint32_t getCursorPositionX() const;

    /**
	 * \brief Get cursor position y component
	 * \return Y coordinate
	 */
	uint32_t getCursorPositionY() const;

    /**
     * \brief Get window cursor position
     * \return Position
     */
	Vector2u getCursorPosition() const;

    /**
	 * \brief Set position. If newPos > (oldPos + windowSize) then do nothing
	 * \param newPos New position
	 */
	void setPosition(const Vector2u& newPos) override;

	/**
	 * \brief Set position. New position = Old position + deltaPos
	 * \param deltaPos Delta position
	 */
	void move(const Vector2u& deltaPos) override;

    /**
	 * \brief Resize window
	 * \param newSize New size
	 * \return Ok if successful, Err otherwise
	 */
	Status resize(const Vector2u& newSize) const;

    /**
	 * \brief Get window width
	 * \return Width
	 */
	uint32_t getWidth() const;

    /**
	 * \brief Get window height
	 * \return Height
	 */
	uint32_t getHeight() const;

    /**
	 * \brief Get window size
	 * \return Window size
	 */
	Vector2u getSize() const;

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
    void drawCursesBorder() const;

    /**
     * \brief Background char
     */
    Char m_backgroundChar;

	/**
	 * \brief Border container
	 */
	Border m_border;

private:    
    /**
     * \brief PDCurses window pointer
     */
    _win* m_win;
};
}
