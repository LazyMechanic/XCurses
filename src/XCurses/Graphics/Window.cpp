#include <PDCurses/curses.h>

#include <XCurses/Graphics/Window.h>
#include <XCurses/Graphics/Context.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
Object::Ptr<Window> Window::create(const Vector2u& position, const Vector2u& size)
{
	return std::shared_ptr<Window>(new Window(position, size));
}

Window::Window(const Vector2u& position, const Vector2u& size) :
	m_backgroundChar(' '),
	m_border(Border::Default)
{
	m_win = newwin(size.y, size.x, position.y, position.x);
}

Window::~Window()
{
    delwin(m_win);
}


void Window::update(const float dt)
{
	/* full virtual func */
}

void Window::setBorder(const Border& border)
{
    m_border = border;
}

Border Window::getBorder() const
{
    return m_border;
}

_win* Window::getCursesWin() const
{
    return m_win;
}

void Window::draw()
{
    // Clear the window
    wclear(m_win);
    // Draw border
	drawCursesBorder();
    
    if (getContext() != nullptr) {
		getContext()->addWindowToRefresh(std::dynamic_pointer_cast<Window>(shared_from_this()));
    }
}

void Window::addChar(const Char& ch) const
{
	addChar(ch, getCursorPosition());
}

void Window::addChar(const Char& ch, const Vector2u& pos) const
{
    mvwaddch(m_win, pos.y, pos.x, ch.toCursesChar());
}

Char Window::getChar(const Vector2u& pos) const
{
	return Char(mvwinch(m_win, pos.y, pos.x));
}

void Window::setCursorPosition(const Vector2u& newPos) const
{
    wmove(m_win, newPos.y, newPos.x);
}

uint32_t Window::getCursorPositionX() const
{
	return getcurx(m_win);
}

uint32_t Window::getCursorPositionY() const
{
	return getcury(m_win);
}

Vector2u Window::getCursorPosition() const
{
    return Vector2u(getCursorPositionX(), getCursorPositionY());
}

void Window::setPosition(const Vector2u& newPos)
{
	mvwin(m_win, newPos.y, newPos.x);
	m_position = Vector2u(getbegx(m_win), getbegy(m_win));
}

void Window::move(const Vector2u& deltaPos)
{
	setPosition(getPosition() + deltaPos);
}

Status Window::resize(const Vector2u& newSize) const
{
	return wresize(m_win, newSize.y, newSize.x);
}

uint32_t Window::getWidth() const
{
	return getmaxx(m_win);
}

uint32_t Window::getHeight() const
{
	return getmaxy(m_win);
}

Vector2u Window::getSize() const
{
	return Vector2u(getWidth(), getHeight());
}

void Window::setBackground(const Char& ch)
{
	m_backgroundChar = ch;
	bkgdset(m_backgroundChar.toCursesChar());
}

Char Window::getBackground() const
{
	return m_backgroundChar;
}

void Window::drawCursesBorder() const
{
    wborder(m_win,
        m_border.leftSide.toCursesChar(),
        m_border.rightSide.toCursesChar(),
        m_border.topSide.toCursesChar(),
        m_border.bottomSide.toCursesChar(),
        m_border.topLeftCorner.toCursesChar(),
        m_border.topRightCorner.toCursesChar(),
        m_border.bottomLeftCorner.toCursesChar(),
        m_border.bottomRightCorner.toCursesChar());
}
}
