#include <XCurses/HasWindow.h>

namespace xcur {
void HasWindow::setWindow(Object::Ptr<Window> window)
{
    m_window = window;
}

Object::Ptr<Window> HasWindow::getWindow() const
{
    return m_window.lock();
}
}
