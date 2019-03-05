#pragma once

#include <XCurses/Graphics/Window.h>

namespace xcur {
class HasWindow
{
public:
	/**
	 * \brief Default HasWindow constructor.
	 */
	HasWindow() = default;

	/**
	 * \brief Copy HasWindow constructor
	 */
	HasWindow(const HasWindow&) = default;

	/**
	 * \brief Move HasWindow constructor
	 */
	HasWindow(HasWindow&&) = default;

	/**
	 * \brief Default copy assignment operator
	 * \return Reference to \a this
	 */
	HasWindow& operator =(const HasWindow&) = default;

	/**
	 * \brief Default move assignment operator
	 * \return Reference to \a this
	 */
	HasWindow& operator =(HasWindow&&) = default;

    /**
     * \brief HasWindow destructor
     */
    virtual ~HasWindow() = default;

    /**
     * \brief Set window
     * \param window Window
     */
    void setWindow(Object::Ptr<Window> window);

    /**
     * \brief Get window
     * \return Smart ptr to window
     */
    Object::Ptr<Window> getWindow() const;

protected:
    /**
     * \brief Window
     */
    Object::WeakPtr<Window> m_window;
};
}