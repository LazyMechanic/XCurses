#pragma once

#include <list>
#include <memory>

#include <XCurses/Border.h>
#include <XCurses/Widget.h>
#include <XCurses/RootObject.h>

struct _win;

namespace xcur {
class Window : public RootObject, public std::enable_shared_from_this<Window>
{
public:
	friend class Core;

    /**
	 * \brief Window destructor
	 */
	virtual ~Window();

    /**
	 * \brief Function calling every tick. Virtual function
	 * \param dt Delta time
	 */
	virtual void update(float dt) override;

	virtual void draw() override;

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
	 * \brief Default Window constructor
	 */
	Window();

    /**
	 * \brief Container of widgets
	 */
	Object::Ptr<Container> m_rootWindowContainer;

    /**
	 * \brief Border container
	 */
	Border m_border;

private:
    /**
	 * \brief Call curses function for redraw border
	 */
	void updateCursesBorder() const;
    
	/**
	 * \brief PDCurses window pointer
	 */
	_win* m_win;
};
}
