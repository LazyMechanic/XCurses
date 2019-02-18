#include <XCurses/ContextSystem.h>

#include <algorithm>

namespace xcur {
void ContextSystem::handleEvents()
{
}

void ContextSystem::update(float dt)
{
	invokeTasks();
}

void ContextSystem::draw()
{
}

void ContextSystem::push(const Object::Ptr<Context>& context)
{
}

void ContextSystem::add(const Object::Ptr<Context>& context)
{
}

void ContextSystem::pop()
{
}

void ContextSystem::remove(const Object::Ptr<Context>& context)
{
}

void ContextSystem::remove(uint64_t contextId)
{
}

void ContextSystem::setCurrent(const Object::Ptr<Context>& context)
{
}

void ContextSystem::setCurrent(uint64_t contextId)
{
}

Object::Ptr<Context> ContextSystem::getCurrent() const
{
}

void ContextSystem::addTask(const std::function<void()>& task)
{
	m_tasks.push_back(task);
}

Core* ContextSystem::getCore() const
{
	return m_core;
}

void ContextSystem::invokeTasks()
{
	for (auto taskIt = m_tasks.begin(); taskIt != m_tasks.end(); ++taskIt) {
		(*taskIt)();
	}
}

std::list<Object::Ptr<Context>>::iterator ContextSystem::findContext(uint64_t contextId)
{
	return std::find_if(m_contexts.begin(), m_contexts.end(), [&contextId](const Object::Ptr<Context>& checkContext) {
		return contextId == checkContext->getId();
	});
}
}
