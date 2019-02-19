#pragma once

#include <list>

#include <XCurses/Widget.h>
#include <XCurses/Drawable.h>
#include <XCurses/Behaviour.h>
#include <XCurses/Container.h>
#include <XCurses/ContextComponent.h>

namespace xcur {
namespace detail {
class TreeNode :
    public Drawable,
    public Behaviour,
    std::enable_shared_from_this<TreeNode>
{
public:
	/**
	 * \brief Goes through all nodes and call his \a update() function
	 * \param dt Delta time
	 */
	void update(float dt) override;

	/**
	 * \brief Goes through all nodes and call his \a draw() function
	 */
    void draw() override;

    /**
	 * \brief Find node with specific component
	 * \param component 
	 * \return Ptr to node if component found, nullptr otherwise
	 */
	Object::Ptr<TreeNode> findNode(const Object::Ptr<ContextComponent>& component);

private:
    /**
     * \brief TreeNode constructor. Construct node with specific component as widget
     * \param widget Widget
     */
    explicit TreeNode(const Object::Ptr<Widget>& widget);

	/**
	 * \brief TreeNode constructor. Construct node with specific component as container
	 * \param container Container
	 */
	explicit TreeNode(const Object::Ptr<Container>& container);

    /**
	 * \brief Branches of this node
	 */
	std::list<Object::Ptr<TreeNode>> m_nodes;

    /**
	 * \brief Component which this node storing
	 */
	Object::WeakPtr<ContextComponent> m_component;
};
}
}