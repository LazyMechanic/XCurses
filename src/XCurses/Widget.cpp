#include <XCurses/Widget.h>

#include <XCurses/Window.h>

namespace xcur {
uint32_t Widget::nextWidgetId = 0;

Widget::Widget() :
    m_id(nextWidgetId++),
    m_parentWindow(std::weak_ptr<Window>())
{
}

void Widget::setParentWindow(const std::shared_ptr<Window>& window)
{
    const std::shared_ptr<Window> oldWindow = m_parentWindow.lock();
    // If new window and old window is similar
	if (oldWindow == window) {
		return;
	}

	m_parentWindow = window;
}

std::shared_ptr<Window> Widget::getParentWindow() const
{
	return m_parentWindow.lock();
}

uint32_t Widget::getId() const
{
	return m_id;
}

void Widget::draw()
{
}
}
