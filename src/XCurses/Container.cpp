#include <XCurses/Container.h>

#include <algorithm>

#include <XCurses/Context.h>

namespace xcur {
void Container::add(const Object::Ptr<Widget>& widget)
{
    getContext()->addTask([this, &widget]() {
		auto foundWidgetIt = findWidget(widget);
        // If the component already exists
        if (foundWidgetIt != m_widgets.end()) {
			return;
        }

		// Add widget to update() queue
		getContext()->add(widget);

        // Set parent widget
		widget->m_parentWidget = std::enable_shared_from_this<Container>::shared_from_this();
		
        // Set parent window
        widget->m_parentWindow = getParentWindow();
        
        // Add widget to container
		m_widgets.push_back(widget);
	});
}

void Container::remove(const Object::Ptr<Widget>& widget)
{
	getContext()->addTask([this, &widget]() {
		auto foundWidgetIt = findWidget(widget);
		// If the component not found
		if (foundWidgetIt == m_widgets.end()) {
			return;
		}

        // Remove widget from update() queue
		getContext()->remove(widget);

		// Reset parent widget
		widget->m_parentWidget.reset();

		// Reset parent window
		widget->m_parentWindow.reset();

        // Remove widget from container
		m_widgets.erase(foundWidgetIt);
	});
}

std::list<Object::Ptr<Widget>>::iterator Container::findWidget(
	const Object::Ptr<Widget>& widget)
{
	return std::find_if(m_widgets.begin(), m_widgets.end(), [&widget](const Object::Ptr<Widget>& checkWidget) {
		return widget->getId() == checkWidget->getId();
	});
}
}
