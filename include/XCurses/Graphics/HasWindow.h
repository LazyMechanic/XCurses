#pragma once

#include <XCurses/Graphics/Window.h>

namespace xcur {
/**
 * \brief Class provides interface for using xcur::Window.
 * You must inherit from this class for objects that need Window
 */
class HasWindow
{
public:
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
     * \brief Default HasWindow constructor.
     */
    HasWindow() = default;

    /**
     * \brief Window
     */
    Object::WeakPtr<Window> m_window;
};
}