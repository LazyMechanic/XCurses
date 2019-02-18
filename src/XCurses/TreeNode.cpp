#include <XCurses/TreeNode.h>

namespace xcur {
namespace detail {
TreeNode::TreeNode(const Object::Ptr<Widget>& widget) :
    m_component(widget)
{
}

TreeNode::TreeNode(const Object::Ptr<Container>& container) :
    m_component(container)
{
	for (auto& widget : container->m_widgets) {
		m_nodes.push_back(Object::create<TreeNode>(widget));
	}
}

void TreeNode::update(float dt)
{
	auto sharedComponent = m_component.lock();
	// If component exists
	if (sharedComponent != nullptr) {
		sharedComponent->update(dt);
	}

	for (auto& node : m_nodes) {
		node->update(dt);
	}
}

void TreeNode::draw()
{
	auto sharedComponent = m_component.lock();
    // If component exists
    if (sharedComponent != nullptr) {
		sharedComponent->draw();
    }

    for (auto& node : m_nodes) {
		node->draw();
    }
}

std::list<Object::Ptr<TreeNode>>::iterator TreeNode::findComponent(const Object::Ptr<ContextComponent>& component)
{
    // TODO: fill find component function
}
}
}