#include <XCurses/Context.h>

#include <algorithm>

#include <XCurses/Core.h>
#include <XCurses/Input.h>
#include <XCurses/Widget.h>
#include <XCurses/TreeNode.h>
#include <XCurses/Container.h>
#include <XCurses/ContextSystem.h>

namespace xcur {
Context::Context() :
	m_contextSystem(nullptr)
{
}

void Context::handleEvents()
{
	// TODO: fill handleEvents() function
}

void Context::update(float dt)
{
	m_widgetTreeRoot->update(dt);
}

void Context::draw()
{
	m_widgetTreeRoot->draw();
}

void Context::add(Object::Ptr<Widget> widget)
{
	auto container = std::dynamic_pointer_cast<Container>(widget);
    // If widget is container
    if (container != nullptr) {
		addContainerWidget(container);
    }
	else {
		addSingleWidget(widget);
	}
}

void Context::remove(Object::Ptr<Widget> widget)
{
	auto foundNode = m_widgetTreeRoot->findByWidget(widget);
    // If node found
    if (foundNode != nullptr) {
		foundNode->getParent()->remove(widget);
    }
}

bool Context::has(Object::Ptr<Widget> widget) const
{
	return m_widgetTreeRoot->has(widget);
}

Core* Context::getCore() const
{
	return m_contextSystem->getCore();
}

void Context::setContextSystem(ContextSystem* contextSystem)
{
	m_contextSystem = contextSystem;
}

ContextSystem* Context::getContextSystem() const
{
	return m_contextSystem;
}

void Context::addContainerWidget(Object::Ptr<Container> container)
{
	addSingleWidget(container);
	for (auto childIt = container->begin(); childIt != container->end(); ++childIt) {
		add(*childIt);
    }
}

void Context::addSingleWidget(Object::Ptr<Widget> widget)
{
    // If widget already exists
    if (has(widget)) {
		return;
    }

	// If widget has parent
	if (widget->getParent() != nullptr) {
		auto parent = m_widgetTreeRoot->findByWidget(std::dynamic_pointer_cast<Widget>(widget->getParent()));
		// If parent found
		if (parent != nullptr) {
			parent->add(widget);
		}
		// If parent is wrong
		else {
			return;
		}
	}
	else {
		m_rootWidget->add(widget);
		m_widgetTreeRoot->add(widget);
	}
}
}
