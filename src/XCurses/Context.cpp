#include <XCurses/Context.h>

#include <algorithm>

#include <XCurses/Input.h>
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
	for (auto& component : m_allComponents) {
		component->update(dt);
	}
}

void Context::draw()
{
    for (auto& rootObject : m_rootObjects) {
		rootObject->draw();
    }
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
	getContextSystem()->addTask(task);
}

Core* Context::getCore() const
{
	return m_contextSystem->getCore();
}

ContextSystem* Context::getContextSystem() const
{
	return m_contextSystem;
}

void Context::updateComponents(float dt)
{
}

Status Context::tryAdd(const Object::Ptr<ContextComponent>& component)
{
	//auto foundComponent = findComponent(component);
	//// If the component already exists
	//if (foundComponent != m_allComponents.end()) {
	//	return Status::Err;
	//}

	//component->m_context = shared_from_this();
	//m_allComponents.push_back(component);
	//return Status::Ok;

    // TODO: fill try add with tree node
}

Status Context::tryRemove(const Object::Ptr<ContextComponent>& component)
{
	//auto foundComponent = findComponent(component);
	//// If the component not found
	//if (foundComponent == m_allComponents.end()) {
	//	return Status::Err;
	//}

	//component->m_context.reset();
	//m_allComponents.erase(foundComponent);
	//return Status::Ok;

    // TODO: fill try remove with tree node
}
}
