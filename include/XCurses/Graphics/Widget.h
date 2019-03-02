#pragma once

#include <XCurses/Graphics/Object.h>
#include <XCurses/System/Vector.h>
#include <XCurses/Graphics/Drawable.h>
#include <XCurses/Graphics/Behaviour.h>
#include <XCurses/Graphics/ContextComponent.h>

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
	 * \brief Set position
	 * \param newPos New position
	 */
	virtual void setPosition(const Vector2u& newPos);

    /**
	 * \brief Set position. New position = Old position + deltaPos
	 * \param deltaPos Delta position
	 */
	virtual void move(const Vector2u& deltaPos);

    /**
	 * \brief Get position x component
	 * \return X coordinate
	 */
	virtual uint32_t getPositionX() const;

    /**
	 * \brief Get position y component
	 * \return Y coordinate
	 */
	virtual uint32_t getPositionY() const;

    /**
	 * \brief Get position
	 * \return Position
	 */
	virtual Vector2u getPosition() const;

    /**
     * \brief Put widget to front relatively parent
     */
    void toFront();

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

protected:
    /**
     * \brief Ptr to parent widget
     */
    Object::WeakPtr<Container> m_parent;

    /**
	 * \brief Widget position
	 */
	Vector2u m_position;
};
}
