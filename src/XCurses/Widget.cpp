#include <XCurses/Widget.h>

namespace xcur {
uint32_t Widget::nextWidgetId = 0;

Widget::Widget() :
    m_widgetId(nextWidgetId++)
{
}

Widget::Widget(const Widget& widget)
{
}

Widget::Widget(Widget&& widget)
{
}

uint32_t Widget::getId() const
{
	return m_widgetId;
}

void Widget::setParentWindow(Window* win)
{
	m_parentWindow = win;
}
}
