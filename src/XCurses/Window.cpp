#include <PDCurses/curses.h>

#include <XCurses/Window.h>
#include <XCurses/Container.h>

namespace xcur {
Window::Window()
{
}

Window::~Window()
{
    delwin(m_win);
}


void Window::update(const float dt)
{
}

void Window::setBorder(const Border& border)
{
    m_border = border;
    updateCursesBorder();
}

Border Window::getBorder() const
{
    return m_border;
}

_win* Window::getCursesWin() const
{
    return m_win;
}

Object::Ptr<Window> Window::getSharedFromThis()
{
    return std::enable_shared_from_this<Window>::shared_from_this();
}

void Window::draw()
{
    // Clear the window
    wclear(m_win);
    // Draw border
    updateCursesBorder();
}

void Window::addChar(const Char& ch) const
{
    waddch(m_win, ch.toCursesChar());
}

void Window::addChar(const Char& ch, const Window::Position& pos) const
{
    mvwaddch(m_win, pos.y, pos.x, ch.toCursesChar());
}

void Window::moveCursor(const Window::Position& newPos) const
{
    wmove(m_win, newPos.y, newPos.x);
}

Window::Position Window::getCursorPosition() const
{
    return Window::Position(getcurx(m_win), getcury(m_win));
}

void Window::updateCursesBorder() const
{
    wborder(m_win,
        m_border.leftSide,
        m_border.rightSide,
        m_border.topSide,
        m_border.bottomSide,
        m_border.topLeftCorner,
        m_border.topRightCorner,
        m_border.bottomLeftCorner,
        m_border.bottomRightCorner);
}
}
