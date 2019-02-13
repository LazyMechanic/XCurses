#include <PDCurses/curses.h>

#include <algorithm>

#include <XCurses/Window.h>

namespace xcur {
uint32_t Window::nextWindowId = 0;

Window::Window() :
    m_id(nextWindowId++),
    m_core(nullptr)
{
}

size_t Window::widgetHash(const uint32_t& id)
{
	return std::hash<uint32_t>()(id);
}

Window::~Window()
{
	delwin(m_win);
}

void Window::update(const float dt)
{
}

void Window::addWidget(const Widget::Ptr<>& widget)
{
	m_addWidgets.push_back(widget);
}

void Window::removeWidget(const Widget::Ptr<>& widget)
{
	m_removeWidgets.push_back(widget);
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

size_t Window::numberOfWidgets() const
{
	return m_widgets.size();
}

_win* Window::getCursesWin() const
{
	return m_win;
}

Core* const Window::getCore() const
{
	return m_core;
}

uint32_t Window::getId() const
{
	return m_id;
}

void Window::draw()
{
    // Clear the window
	wclear(m_win);
    // Draw border
	updateCursesBorder();
    // Draw widgets
	for (auto& widget : m_widgets) {
		widget->draw();
	}
}

void Window::updateWidgets()
{
    // Add widgets
	tryAddWidgets();
    // Remove widgets
	tryRemoveWidgets();
}

void Window::tryAddWidgets()
{
	for (auto& widget : m_addWidgets) {
		auto widgetIt = findWidget(widget);
		// If widget nonexistent
		if (widgetIt == m_widgets.end()) {
			m_widgets.push_back(widget);
		}
	}
    // Clear widget queue for add
	m_addWidgets.clear();
}

void Window::tryRemoveWidgets()
{
	for (auto& widget : m_removeWidgets) {
		auto widgetIt = findWidget(widget);
		// If the widget exists
		if (widgetIt != m_widgets.end()) {
		    m_widgets.erase(widgetIt);
		}
	}
	// Clear widget queue for remove
	m_removeWidgets.clear();
}

std::list<Widget::Ptr<>>::iterator Window::findWidget(const Widget::Ptr<>& widget)
{
	return std::find_if(m_widgets.begin(), m_widgets.end(), [&widget](const Widget::Ptr<>& findWidget) {
		return widget->getId() == findWidget->getId();
	});
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
