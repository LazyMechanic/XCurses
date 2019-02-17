#include <XCurses/ContextSystem.h>

#include <algorithm>

namespace xcur {
void ContextSystem::handleEvents()
{
}

void ContextSystem::update(float dt)
{
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

std::list<Object::Ptr<Context>>::iterator ContextSystem::findContext(uint64_t contextId)
{
	return std::find_if(m_contexts.begin(), m_contexts.end(), [&contextId](const Object::Ptr<Context>& checkContext) {
		return contextId == checkContext->getId();
	});
}
}
