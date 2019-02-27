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
    auto treeNode = Object::create<TreeNode>(widget);
    treeNode->setParent(shared_from_this());
    m_childNodes.push_back(treeNode);
}

void TreeNode::remove(Object::Ptr<Widget> widget)
{
    auto foundNodeIt = findChild(widget);
    // If node found
    if (foundNodeIt != m_childNodes.end()) {
        (*foundNodeIt)->setParent(nullptr);
        m_childNodes.erase(foundNodeIt);
    }
}

Object::Ptr<TreeNode> TreeNode::findInSubtreeByWidget(Object::Ptr<Widget> widget)
{
    // If this node is the desired one
    if (getWidget() == widget) {
        return shared_from_this();
    }

    for (auto& node : m_childNodes) {
        auto foundNode = node->findInSubtreeByWidget(widget);
        // If node was found
        if (foundNode != nullptr) {
            return foundNode;
        }
    }

    return nullptr;
}

bool TreeNode::has(Object::Ptr<Widget> widget)
{
    return findInSubtreeByWidget(widget) != nullptr;
}

void TreeNode::widgetToFront(Object::Ptr<Widget> widget)
{
    auto foundNode = findChild(widget);
    // If node found
    if (foundNode != m_childNodes.end()) {
        m_childNodes.splice(m_childNodes.end(), m_childNodes, foundNode);
    }
}

Object::Ptr<Widget> TreeNode::getWidget() const
{
    return m_widget.lock();
}

void TreeNode::setParent(Object::Ptr<TreeNode> parent)
{
    m_parent = parent;
}

Object::Ptr<TreeNode> TreeNode::getParent() const
{
    return m_parent.lock();
}

std::list<Object::Ptr<TreeNode>>::const_iterator TreeNode::findChild(Object::Ptr<Widget> widget) const
{
    return std::find_if(
        m_childNodes.begin(),
        m_childNodes.end(),
        [&widget](const Object::Ptr<TreeNode>& checkNode) {
        return widget == checkNode->getWidget();
    });
}
}
}