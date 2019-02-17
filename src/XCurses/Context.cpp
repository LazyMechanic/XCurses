#include <XCurses/Context.h>

#include <algorithm>

#include <XCurses/Input.h>

namespace xcur {
void Context::handleEvents()
{
	// TODO: fill handleEvents() function
}

void Context::update(float dt)
{
	invokeTasks();
	updateComponents(dt);
}

void Context::draw()
{
    // TODO: fill draw() function
}

void Context::add(const Object::Ptr<RootObject>& object)
{
	addTask([this, &object]() {
	    const Status tryAddStatus = tryAdd(object);
        // If adding is successful
        if (tryAddStatus == Status::Ok) {
			m_rootObjects.push_back(object);
        }
	});
}

void Context::add(const Object::Ptr<Widget>& widget)
{
	addTask([this, &widget]() {
		tryAdd(widget);
	});
}

void Context::remove(const Object::Ptr<RootObject>& object)
{
	addTask([this, &object]() {
	    const Status tryRemoveStatus = tryRemove(object);
		// If removing is successful
		if (tryRemoveStatus == Status::Ok) {
			auto foundRootObject = std::find_if(m_rootObjects.begin(), m_rootObjects.end(), [&object](const Object::Ptr<RootObject>& checkObject) {
				return object->getId() == checkObject->getId();
			});
            // If root object exists
            if (foundRootObject != m_rootObjects.end()) {
				m_rootObjects.erase(foundRootObject);
            }
		}
	});
}

void Context::remove(const Object::Ptr<Widget>& widget)
{
	addTask([this, &widget]() {
		tryRemove(widget);
	});
}

void Context::addTask(const std::function<void()>& task)
{
	m_tasks.push_back(task);
}

Core* Context::getCore()
{
	return m_core;
}

Context::Context() :
    m_core(nullptr)
{
}

void Context::invokeTasks()
{
    for (auto taskIt = m_tasks.begin(); taskIt != m_tasks.end(); ++taskIt) {
		(*taskIt)();
    }
}

void Context::updateComponents(float dt)
{
    for (auto componentIt = m_allComponents.begin(); componentIt != m_allComponents.end(); ++componentIt) {
		auto sharedComponent = componentIt->lock();
        // If the component was destroy
        if (sharedComponent == nullptr) {
            // Go to next component
			componentIt = m_allComponents.erase(componentIt);
			continue;
        }

		sharedComponent->update(dt);
    }
}

std::list<Object::WeakPtr<ContextComponent>>::iterator Context::findComponent(
    const Object::Ptr<ContextComponent>& component)
{
	return std::find_if(m_allComponents.begin(), m_allComponents.end(), [&component](const Object::WeakPtr<ContextComponent>& checkComponent) {
		return component->getId() == checkComponent.lock()->getId();
	});
}

Status Context::tryAdd(const Object::Ptr<ContextComponent>& component)
{
	auto foundComponent = findComponent(component);
	// If the component already exists
	if (foundComponent != m_allComponents.end()) {
		return Status::Err;
	}

	component->m_context = shared_from_this();
	m_allComponents.push_back(component);
	return Status::Ok;
}

Status Context::tryRemove(const Object::Ptr<ContextComponent>& component)
{
	auto foundComponent = findComponent(component);
	// If the component not found
	if (foundComponent == m_allComponents.end()) {
		return Status::Err;
	}

	component->m_context.reset();
	m_allComponents.erase(foundComponent);
	return Status::Ok;
}
}
