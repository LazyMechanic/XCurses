#include <XCurses/Container.h>

#include <algorithm>

namespace xcur {
void Container::update(float dt)
{
    /* full virtual func */
}

void Container::draw()
{
    /* full virtual func */
}

Status Container::add(Object::Ptr<Widget> widget)
{
    // If widget has parent already
    if (widget->getParent() != nullptr) {
		return Status::Err;
    }

	widget->setParent(std::dynamic_pointer_cast<Container>(shared_from_this()));
	m_childWidgets.push_back(widget);

    // If container was added in context and has ptr to it
    if (getContext() != nullptr) {
		getContext()->add(widget);
    }

	return Status::Ok;
}

Status Container::remove(Object::Ptr<Widget> widget)
{
	auto widgetIt = find(widget);
    // If widget not found
    if (widgetIt == m_childWidgets.end()) {
		return Status::Err;
    }

	m_childWidgets.erase(widgetIt);

	// If container was added in context and has ptr to it
	if (getContext() != nullptr) {
		getContext()->remove(widget);
	}

    return Status::Ok;
}

bool Container::has(Object::Ptr<Widget> widget)
{
	return find(widget) != m_childWidgets.end();
}

std::list<Object::Ptr<Widget>>::const_iterator Container::begin() const
{
	return m_childWidgets.begin();
}

std::list<Object::Ptr<Widget>>::const_iterator Container::end() const
{
	return m_childWidgets.end();
}

std::list<Object::Ptr<Widget>>::const_iterator Container::find(Object::Ptr<Widget> widget) const
{
	return std::find_if(
		m_childWidgets.begin(),
		m_childWidgets.end(),
		[&widget](const Object::Ptr<Widget>& checkWidget) {
		return widget == checkWidget;
	});
}
}
