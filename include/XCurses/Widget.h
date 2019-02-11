#pragma once
#include <memory>
#include <cstdint>

#include <XCurses/Status.h>

namespace xcur {
class Widget
{
public:
	friend class Window;

	using Ptr = std::shared_ptr<Widget>;

	Widget();

	Widget(const Widget& widget);

	Widget(Widget&& widget);

	uint32_t getId() const;

protected:
	Window* m_parentWindow;

	const uint32_t m_widgetId;

private:
	static uint32_t nextWidgetId;
};
}
