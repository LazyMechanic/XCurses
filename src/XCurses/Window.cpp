#include <PDCurses/curses.h>

#include <XCurses/Window.h>

namespace xcur {
Window::Window()
{
}

Window::Window(const Window&)
{
}

Window::Window(Window&&)
{
}

Window::~Window()
{
	delwin(m_win);
}

Widget::Ptr Window::addWidget(const Widget& widget)
{
	auto widgetIt = m_widgets.find(widget.getId());
    // If widget already exists
    if (widgetIt != m_widgets.end()) {
		return widgetIt->second;
    }

    m_widgets.
}

Widget::Ptr Window::findWidgetById(uint32_t widgetId)
{
	auto widgetIt = m_widgets.find(widgetId);
    // If the widget not found
    if (widgetIt == m_widgets.end()) {
		return Widget::Ptr(nullptr);
    }

	return widgetIt->second;
}

_win* Window::getCursesWin()
{
	return m_win;
}

void Window::draw()
{
	wnoutrefresh(m_win);
}
}