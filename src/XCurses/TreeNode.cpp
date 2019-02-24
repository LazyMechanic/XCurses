#include <XCurses/TreeNode.h>

#include <algorithm>

namespace xcur {
namespace detail {
TreeNode::TreeNode(Object::Ptr<Widget> widget) :
	m_widget(widget)
{
}

void TreeNode::update(float dt)
{
	m_widget.lock()->update(dt);

    for (auto& node : m_childNodes) {
		node->update(dt);
    }
}

void TreeNode::draw()
{
	m_widget.lock()->draw();

	for (auto& node : m_childNodes) {
		node->draw();
	}
}

void TreeNode::add(Object::Ptr<Widget> widget)
{
	m_childNodes.push_back(Object::create<TreeNode>(widget));
}

void TreeNode::remove(Object::Ptr<Widget> widget)
{
	auto foundNodeIt = std::find_if(
		m_childNodes.begin(), 
		m_childNodes.end(), 
		[&widget](const Object::Ptr<TreeNode>& checkNode) {
		return widget == checkNode->getWidget();
	});
    // If node found
    if (foundNodeIt != m_childNodes.end()) {
		m_childNodes.erase(foundNodeIt);
    }
}

Object::Ptr<TreeNode> TreeNode::findByWidget(Object::Ptr<Widget> widget)
{
    // If this node is the desired one
    if (m_widget.lock() == widget) {
		return shared_from_this();
    }

    for (auto& node : m_childNodes) {
		auto foundNode = node->findByWidget(widget);
        // If node was found
        if (foundNode != nullptr) {
			return foundNode;
        }
    }

	return nullptr;
}

bool TreeNode::has(Object::Ptr<Widget> widget)
{
	return findByWidget(widget) != nullptr;
}

Object::Ptr<Widget> TreeNode::getWidget() const
{
	return m_widget.lock();
}

Object::Ptr<TreeNode> TreeNode::getParent() const
{
    return m_parent.lock();
}
}
}