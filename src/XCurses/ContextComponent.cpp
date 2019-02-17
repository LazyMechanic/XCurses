#include <XCurses/ContextComponent.h>

namespace xcur {
ContextComponent::~ContextComponent()
{
    // TODO: remove from context
}

Object::Ptr<Context> ContextComponent::getContext()
{
	return m_context.lock();
}
}
