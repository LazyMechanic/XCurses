#include <PDCurses/curses.h>

#include <XCurses/Window.h>

namespace xcur {
uint32_t Window::nextWindowId = 0;

Window::Window() :
    m_id(nextWindowId++),
    m_widgets(0, std::bind(&Window::widgetHash, this, std::placeholders::_1))
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

void Window::update(float dt)
{
}

Status Window::addWidget(const Widget::Ptr<>& widget)
{
    const auto widgetIt = m_widgets.find(widget->getId());
	// If widget already exists
	if (widgetIt != m_widgets.end()) {
		return Status::Err;
	}

    if (widget->getParentWindow() != nullptr) {
		return Status::Err;
    }

	m_widgets[widget->getId()] = widget;
	m_widgets[widget->getId()]->setParentWindow(shared_from_this());
	return Status::Ok;
}

Status Window::eraseWidget(const Widget::Ptr<>& widget)
{
	auto widgetIt = m_widgets.find(widget->getId());
	// If widget not found
	if (widgetIt == m_widgets.end()) {
		return Status::Err;
	}

	widgetIt->second->setParentWindow(nullptr);
	m_widgets.erase(widgetIt);
	return Status::Ok;
}

_win* Window::getCursesWin() const
{
	return m_win;
}

uint32_t Window::getId() const
{
	return m_id;
}

void Window::draw()
{
	wclear(m_win);

	// TODO: redraw border

	for (auto& widget : m_widgets) {
		widget.second->draw();
	}
}
}