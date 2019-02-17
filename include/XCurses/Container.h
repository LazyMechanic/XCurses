#pragma once

#include <list>

#include <XCurses/Widget.h>

namespace xcur {
class Container : public Widget, std::enable_shared_from_this<Container>
{
public:
    /**
	 * \brief Container destructor
	 */
	virtual ~Container() = default;

	/**
     * \brief Add new widget
     * \param widget Widget
     * \return Ok if widget added successfully, Err if widget already exists, or
     * if widget already added in another window
     */
	virtual void add(const Object::Ptr<Widget>& widget) final;

	/**
	 * \brief Remove the widget
	 * \param widget Widget
	 * \return Ok if widget removed successfully, Err if widget not found
	 */
	virtual void remove(const Object::Ptr<Widget>& widget) final;

protected:
	/**
	 * \brief Default container constructor
	 */
	Container() = default;

	/**
	 * \brief Find the widget in m_widgets
	 * \param widget Widget
	 * \return Iterator to widget if it found, end iterator if the widget
	 * not found
	 */
	std::list<Object::Ptr<Widget>>::iterator findWidget(const Object::Ptr<Widget>& widget);

	/**
	 * \brief Container of widgets
	 */
	std::list<Object::Ptr<Widget>> m_widgets;
};
}