#pragma once

#include <XCurses/Status.h>
#include <XCurses/Object.h>
#include <XCurses/Drawable.h>
#include <XCurses/Behaviour.h>
#include <XCurses/ContextComponent.h>

namespace xcur {
class Window;
class Container;

class Widget :
    public Object,
    public Drawable,
    public Behaviour,
    public ContextComponent,
    public std::enable_shared_from_this<Widget>
{
public:
    /**
     * \brief Widget destructor
     */
    virtual ~Widget();

    /**
     * \brief Call for update object state
     * \param dt Delta time
     */
    virtual void update(float dt) override;

    /**
     * \brief Call function for draw the object
     */
    virtual void draw() override;

    /**
     * \brief Put widget to front relatively parent
     */
    virtual void toFront() final;

    /**
     * \brief Set parent widget container
     * \param parent Parent widget container
     */
    void setParent(Object::Ptr<Container> parent);

    /**
     * \brief Get parent widget container
     * \return Smart ptr to widget
     */
    Object::Ptr<Container> getParent() const;

private:
    /**
     * \brief Ptr to parent widget
     */
    Object::WeakPtr<Container> m_parent;
};
}
