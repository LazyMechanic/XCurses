#include <XCurses/Graphics/VirtualScreen.h>

#include <PDCurses/curses.h>

#include <XCurses/System/Core.h>
#include <XCurses/Graphics/Container.h>
#include <complex.h>

namespace xcur {
Object::Ptr<VirtualScreen> VirtualScreen::create()
{
    return std::shared_ptr<VirtualScreen>(new VirtualScreen());
}

void VirtualScreen::update(float dt)
{
    const auto activeWidget = getActiveInputWidget();
    const auto activeInputWidget = std::dynamic_pointer_cast<Inputtable>(activeWidget);
    // If activeInputWidget is not nullptr
    if (activeWidget != nullptr) {
        Vector2i endPosition = activeInputWidget->getScreenCursorPosition() + activeWidget->getPosition();
        auto parent = activeWidget->getParent();
        // Pass through all parent widgets
        while (parent != nullptr) {
            endPosition += parent->getPosition();
            parent = parent->getParent();
        }

        wmove(stdscr, endPosition.y, endPosition.x);
        curs_set(activeInputWidget->getCursorState());
    }
    else {
        wmove(stdscr, 0, 0);
        curs_set(CursorState::Hidden);
    }

    this->clear();
}

void VirtualScreen::draw() const
{
    wrefresh(stdscr);
    touchwin(stdscr);
}

void VirtualScreen::addChar(const Char& ch, const Vector2i& position)
{
    if (position.x < stdscr->_maxx && 
        position.y < stdscr->_maxy) 
    {
        stdscr->_y[position.y][position.x] = ch.toCursesChar();
    }
}

void VirtualScreen::addString(const String& str, const Vector2i& position)
{
    // If position out of stdscr size
    if (position.x > stdscr->_maxx ||
        position.y > stdscr->_maxy)
    {
        return;
    }

    Vector2i nextPosition = position;
    for (auto& ch : str) {
        // If next X position is end of row
        if (nextPosition.x > stdscr->_maxx) {
            break;
        }

        addChar(ch, nextPosition);
        nextPosition.x++;
    }
}

Object::Ptr<Widget> VirtualScreen::getActiveInputWidget() const
{
    return m_activeInputWidget.lock();
}

bool VirtualScreen::isActiveInputWidget(Object::Ptr<Widget> inputWidget) const
{
    return inputWidget == m_activeInputWidget.lock();
}

void VirtualScreen::clear() const
{
    for (int column = 0; column < stdscr->_maxx; ++column) {
        for (int row = 0; row < stdscr->_maxy; ++row) {
            stdscr->_y[row][column] = ' ';
        }
    }
}
}
