#pragma once

#include <XCurses/System/Object.h>
#include <XCurses/System/Vector.h>
#include <XCurses/Graphics/Drawable.h>
#include <XCurses/Graphics/Behaviour.h>

namespace xcur {
class Context;
class Container;

/**
 * \brief Base class for make application logic
 */
class Widget :
    public Object,
    public Drawable,
    public Behaviour,
    public std::enable_shared_from_this<Widget>
{
public:
    /**
     * \brief Widget destructor
     */
    virtual ~Widget();

    /**
     * \brief Set position
     * \param newPos New position
     */
    void setPosition(const Vector2u& newPos);

    /**
     * \brief Set position. New position = Old position + deltaPos
     * \param deltaPos Delta position
     */
    void move(const Vector2u& deltaPos);

    /**
     * \brief Get position x component
     * \return X coordinate
     */
    uint32_t getPositionX() const;

    /**
     * \brief Get position y component
     * \return Y coordinate
     */
    uint32_t getPositionY() const;

    /**
     * \brief Get position
     * \return Position
     */
    Vector2u getPosition() const;

    /**
     * \brief Put widget to front relatively parent
     */
    void toFront();

    /**
     * \brief Set parent widget container.
     * Do not need use manually
     * \param parent Parent widget container
     */
    void setParent(Object::Ptr<Container> parent);

    /**
     * \brief Get parent widget container
     * \return Smart ptr to widget container
     */
    Object::Ptr<Container> getParent() const;

    /**
     * \brief Set context.
     * Do not need use manually
     * \param context Context
     */
    void setContext(Object::Ptr<Context> context);

    /**
     * \brief Get context
     * \return Smart ptr to context
     */
    Object::Ptr<Context> getContext() const;

protected:
    /**
     * \brief Default Widget constructor
     */
    Widget();

    /**
     * \brief Widget constructor. Construct it with default position
     */
    explicit Widget(const Vector2u& position);

    /**
     * \brief Widget constructor. Construct it with default position and
     * set parent
     * \param position Position
     * \param parent Smart ptr to parent container
     */
    Widget(const Vector2u& position, Object::Ptr<Container> parent);

    /**
     * \brief Widget constructor. Construct it with default position and
     * set context
     * \param position Position
     * \param context Smart ptr to context
     */
    Widget(const Vector2u& position, Object::Ptr<Context> context);

    /**
     * \brief Widget constructor. Construct it with default position and
     * set parent and context
     * \param position Position
     * \param parent Smart ptr to parent container
     * \param context Smart ptr to context
     */
    Widget(const Vector2u& position, Object::Ptr<Container> parent, Object::Ptr<Context> context);

    /**
     * \brief Widget position
     */
    Vector2u m_position;

    /**
     * \brief Smart ptr to parent widget
     */
    Object::WeakPtr<Container> m_parent;

    /**
     * \brief Smart ptr to context
     */
    Object::WeakPtr<Context> m_context;
};
}
