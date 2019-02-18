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
    public Behaviour
{
public:
	void update(float dt) override;

    void draw() override;

	std::list<Object::Ptr<TreeNode>>::iterator findComponent(const Object::Ptr<ContextComponent>& component);
private:
    explicit TreeNode(const Object::Ptr<Widget>& widget);

	explicit TreeNode(const Object::Ptr<Container>& container);

	std::list<Object::Ptr<TreeNode>> m_nodes;

	Object::WeakPtr<ContextComponent> m_component;
};
}
}