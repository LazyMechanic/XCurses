#pragma once

#include <list>

#include <XCurses/Status.h>
#include <XCurses/Widget.h>
#include <XCurses/Object.h>
#include <XCurses/Drawable.h>
#include <XCurses/Behaviour.h>
#include <XCurses/ContextComponent.h>

namespace xcur {
namespace detail {
class TreeNode :
    public Object,
    public Drawable,
    public Behaviour,
    public ContextComponent,
	public std::enable_shared_from_this<TreeNode>
{
public:
	/**
	 * \brief TreeNode constructor with specific widget
	 * \param widget Widget
	 */
	explicit TreeNode(Object::Ptr<Widget> widget);

	/**
	 * \brief Call for update object state
	 * \param dt Delta time
	 */
    void update(float dt) override;

	/**
	 * \brief Call function for draw the object
	 */
    void draw() override;

    /**
	 * \brief Add child tree node with the widget
	 * \param widget Widget
	 */
	void add(Object::Ptr<Widget> widget);

    /**
	 * \brief Remove child tree node with the widget
	 * \param widget Widget
	 */
	void remove(Object::Ptr<Widget> widget);

    /**
	 * \brief Find tree node by widget in subtree
	 * \param widget Widget
	 * \return Smart ptr to tree node if found, nullptr otherwise
	 */
	Object::Ptr<TreeNode> findByWidget(Object::Ptr<Widget> widget);

	/**
	 * \brief Find widget in widget tree
	 * \param widget Widget
	 * \return True if context has widget, false otherwise
	 */
	bool has(Object::Ptr<Widget> widget);

    /**
	 * \brief Get widget from node
	 * \return Smart ptr to widget
	 */
	Object::Ptr<Widget> getWidget() const;

    /**
	 * \brief Get parent node
	 * \return Smart ptr to node
	 */
	Object::Ptr<TreeNode> getParent() const;

private:
    /**
	 * \brief List of child nodes (branches)
	 */
	std::list<Object::Ptr<TreeNode>> m_childNodes;

    /**
	 * \brief Parent node
	 */
	Object::WeakPtr<TreeNode> m_parent;

    /**
	 * \brief Widget
	 */
	Object::WeakPtr<Widget> m_widget;
};
}
}