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

VirtualScreen::VirtualScreen() :
    m_cursorPosition(Vector2u::Zero),
    m_cursorState(CursorState::Hidden),
    m_screenNeedRefresh(true)
{
    if (!Core::isInit()) {
        throw std::runtime_error("Core didn't initialized");
    }

    m_size = Core::getTerminalSize();

    m_cursesWindow = newwin(m_size.y, m_size.x, 0, 0);
}

void VirtualScreen::update(float dt)
{
    m_screenNeedRefresh = false;

    if (m_size != Core::getTerminalSize()) {
        this->resize(Core::getTerminalSize());
    }

    const auto activeInputWidget = getActiveInputWidget();
    // If activeInputWidget is not Inputtable::None
    if (activeInputWidget != nullptr) {
        Vector2u endPosition = activeInputWidget->getCursorPosition();
        auto parent = activeInputWidget->getParent();
        // Pass through all parent widgets
        while (parent != nullptr) {
            endPosition += parent->getPosition();
            parent = parent->getParent();
        }

        wmove(m_cursesWindow, endPosition.y, endPosition.x);
        curs_set(activeInputWidget->getCursorState());
    }
    else {
        wmove(m_cursesWindow, 0, 0);
        curs_set(CursorState::Hidden);
    }

    this->clear();
}

void VirtualScreen::draw() const
{
    if (m_screenNeedRefresh) {
        wrefresh(m_cursesWindow);
        touchwin(m_cursesWindow);
    }
}

void VirtualScreen::addChar(const Char& ch, const Vector2u& position)
{
    if (position.x < m_cursesWindow->_maxx && 
        position.y < m_cursesWindow->_maxy) 
    {
        m_cursesWindow->_y[position.y][position.x] = ch.toCursesChar();
    }
    m_screenNeedRefresh = true;
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
    wclear(m_cursesWindow);
}

void VirtualScreen::resize(const Vector2u& size) 
{
    wresize(m_cursesWindow, size.y, size.x);
    m_size = Vector2u(m_cursesWindow->_maxx, m_cursesWindow->_maxy);
}
}
