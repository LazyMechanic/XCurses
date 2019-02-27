#pragma once

#include <XCurses/Window.h>

namespace xcur {
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
     * \brief Window
     */
    Object::WeakPtr<Window> m_window;
};
}