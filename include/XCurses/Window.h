#pragma once

#include <list>
#include <memory>

#include <XCurses/Border.h>
#include <XCurses/Widget.h>
#include <XCurses/Container.h>

struct _win;

namespace xcur {

class Window :
    public Container,
    public std::enable_shared_from_this<Window>
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
     * \brief Get shared ptr from this object
     * \return Smart ptr to this
     */
    Object::Ptr<Window> getSharedFromThis();

    /**
	 * \brief Border container
	 */
	Border m_border;

private:
    /**
	 * \brief Call curses function for redraw border
	 */
	void updateCursesBorder();
    
	/**
	 * \brief PDCurses window pointer
	 */
	_win* m_win;
};
}
