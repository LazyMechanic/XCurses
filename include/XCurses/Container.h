#pragma once

#include <list>

#include <XCurses/Widget.h>
#include <XCurses/Context.h>

namespace xcur {
namespace detail {
class TreeNode;
}

class Container : public Widget, std::enable_shared_from_this<Container>
{
public:
	friend class detail::TreeNode;

    /**
	 * \brief Container destructor
	 */
	virtual ~Container() = default;

	/**
     * \brief Add new widget
     * \param widget Widget
     */
	virtual void add(const Object::Ptr<Widget>& widget);

	/**
	 * \brief Remove the widget
	 * \param widget Widget
	 */
	virtual void remove(const Object::Ptr<Widget>& widget);

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
