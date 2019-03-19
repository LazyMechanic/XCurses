#include <XCurses/Graphics/VirtualScreen.h>

#include <stdexcept>

#include <PDCurses/curses.h>

#include <XCurses/System/Core.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
Object::Ptr<VirtualScreen> VirtualScreen::create()
{
    return std::shared_ptr<VirtualScreen>(new VirtualScreen());
}

void VirtualScreen::update(float dt)
{
    const auto activeInputWidget = getActiveInputWidget();
    // If activeInputWidget is not Inputtable::None
    if (activeInputWidget != Inputtable::None) {
        Vector2u endPosition = activeInputWidget->getCursorPosition();
        auto parent = activeInputWidget->getParent();
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

void VirtualScreen::addChar(const Char& ch, const Vector2u& position)
{
    if (position.x < stdscr->_maxx && 
        position.y < stdscr->_maxy) 
    {
        stdscr->_y[position.y][position.x] = ch.toCursesChar();
    }
}

void VirtualScreen::addString(const String& str, const Vector2u& position)
{
    // If position out of stdscr size
    if (position.x > stdscr->_maxx ||
        position.y > stdscr->_maxy)
    {
        return;
    }

    Vector2u nextPosition = position;
    for (auto& ch : str) {
        // If next X position is end of row
        if (nextPosition.x > stdscr->_maxx) {
            break;
        }

        addChar(ch, nextPosition);
        nextPosition.x++;
    }
}

void VirtualScreen::setActiveInputWidget(Object::Ptr<Inputtable> inputWidget)
{
    m_activeInputWidget = inputWidget;
}

Object::Ptr<Inputtable> VirtualScreen::getActiveInputWidget() const
{
    return m_activeInputWidget.lock();
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
