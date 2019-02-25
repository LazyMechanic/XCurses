#include <XCurses/Context.h>

#include <algorithm>

#include <XCurses/Input.h>
#include <XCurses/Widget.h>
#include <XCurses/TreeNode.h>
#include <XCurses/Container.h>
#include <XCurses/ContextSystem.h>

namespace xcur {
Context::Context() :
	m_contextSystem(nullptr),
    m_rootWidget(Object::create<Container>()),
	m_widgetTreeRoot(Object::create<detail::TreeNode>(m_rootWidget))
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

Status Context::add(Object::Ptr<Widget> widget)
{
    // If widget already exists
    if (has(widget)) {
		return Status::Err;
    }

	auto container = std::dynamic_pointer_cast<Container>(widget);
    // If widget is container
    if (container != nullptr) {
		return addContainerWidget(container);
    }
	else {
		return addSingleWidget(widget);
	}
}

Status Context::remove(Object::Ptr<Widget> widget)
{
	auto foundNode = m_widgetTreeRoot->findInSubtreeByWidget(widget);
    // If node not found
    if (foundNode == nullptr) {
		return Status::Err;
    }

	foundNode->getParent()->remove(widget);
	widget->setContext(nullptr);
	return Status::Ok;
}

bool Context::has(Object::Ptr<Widget> widget) const
{
	return m_widgetTreeRoot->has(widget);
}

void Context::widgetToFront(Object::Ptr<Widget> widget)
{
	auto foundNode = m_widgetTreeRoot->findInSubtreeByWidget(widget);
    // if node found
    if (foundNode != nullptr) {
		foundNode->getParent()->widgetToFront(widget);
    }
}

void Context::setContextSystem(ContextSystem* contextSystem)
{
	m_contextSystem = contextSystem;
}

ContextSystem* Context::getContextSystem() const
{
	return m_contextSystem;
}

Status Context::addContainerWidget(Object::Ptr<Container> container)
{
	Status addStatus = addSingleWidget(container);
	// If add container end with error
	if (addStatus == Status::Err) {
		return Status::Err;
	}
	for (auto childIt = container->begin(); childIt != container->end(); ++childIt) {
		add(*childIt);
    }
	return Status::Ok;
}

Status Context::addSingleWidget(Object::Ptr<Widget> widget)
{
	// If widget has parent
	if (widget->getParent() != nullptr) {
		auto parent = m_widgetTreeRoot->findInSubtreeByWidget(std::dynamic_pointer_cast<Widget>(widget->getParent()));
		// If parent is wrong
		if (parent == nullptr) {
			return Status::Err;
		}
		parent->add(widget);
	}
	else {
		m_rootWidget->add(widget);
		m_widgetTreeRoot->add(widget);
	}
	widget->setContext(shared_from_this());

	return Status::Ok;
}
}
