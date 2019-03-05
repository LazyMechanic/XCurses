#pragma once

#include <list>

#include <XCurses/Graphics/Widget.h>
#include <XCurses/System/Object.h>
#include <XCurses/Graphics/Drawable.h>
#include <XCurses/Graphics/Behaviour.h>

namespace xcur {
namespace detail {
class TreeNode :
    public Object,
    public Drawable,
    public Behaviour,
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
    Object::Ptr<TreeNode> findInSubtreeByWidget(Object::Ptr<Widget> widget);

    /**
     * \brief Find widget in widget tree
     * \param widget Widget
     * \return True if context has widget, false otherwise
     */
    bool has(Object::Ptr<Widget> widget);

    /**
     * \brief Put node to front. Node find by widget
     * \param widget Widget
     */
    void widgetToFront(Object::Ptr<Widget> widget);

    /**
     * \brief Get widget from node
     * \return Smart ptr to widget
     */
    Object::Ptr<Widget> getWidget() const;

    /**
     * \brief Set parent node
     * \param parent Parent node
     */
    void setParent(Object::Ptr<TreeNode> parent);

    /**
     * \brief Get parent node
     * \return Smart ptr to node
     */
    Object::Ptr<TreeNode> getParent() const;

private:
    std::list<Object::Ptr<TreeNode>>::const_iterator findChild(Object::Ptr<Widget> widget) const;

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