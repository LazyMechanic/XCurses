#pragma once
#include <memory>
#include <cstdint>

#include <XCurses/Status.h>
#include <XCurses/ContextComponent.h>

namespace xcur {
class Window;

class Widget : public ContextComponent, std::enable_shared_from_this<Widget>
{
public:
    /**
	 * \brief Friend class for setup parent widget
	 */
	friend class Container;

	/**
	 * \brief Widget destructor
	 */
	virtual ~Widget();

    /**
	 * \brief Get parent widget container
	 * \return Smart ptr to widget
	 */
	Object::Ptr<Container> getParentWidget() const;

    /**
	 * \brief Get parent window
	 * \return Smart ptr to window
	 */
	Object::Ptr<Window> getParentWindow() const;

protected:
	/**
	 * \brief Default Widget constructor.
	 */
	Widget() = default;

private:
	/**
	 * \brief Ptr to parent widget
	 */
	Object::WeakPtr<Container> m_parentWidget;

    /**
	 * \brief Ptr to parent window
	 */
	Object::WeakPtr<Window> m_parentWindow;
};
}
