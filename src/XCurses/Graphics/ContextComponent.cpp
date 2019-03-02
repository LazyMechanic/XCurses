#include <XCurses/Graphics/ContextComponent.h>

#include <XCurses/Graphics/Context.h>

namespace xcur {
ContextComponent::~ContextComponent()
{
    // TODO: remove from context
}

void ContextComponent::setContext(Object::Ptr<Context> context)
{
    m_context = context;
}

Object::Ptr<Context> ContextComponent::getContext() const
{
    return m_context.lock();
}
}
