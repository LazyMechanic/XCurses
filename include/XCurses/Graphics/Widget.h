#pragma once

#include <XCurses/System/Area.h>
#include <XCurses/System/Object.h>
#include <XCurses/System/Vector.h>
#include <XCurses/System/Drawable.h>
#include <XCurses/System/Behaviour.h>

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
     * \brief Put widget to front relatively parent
     */
    void toFront();

    /**
     * \brief Set area. It is widget size and position relatively parent. 
     * Equal setPosition(...) and setSize(...) together
     * \param area Widget area
     */
    void setArea(const Area& area);

    /**
     * \brief Get area. It is widget size and position relatively parent
     * \return Widget area
     */
    Area getArea() const;

    /**
     * \brief Set position relatively parent. After set position calling onReposition()
     * \param position New position
     */
    void setPosition(const Vector2i& position);

    /**
     * \brief Set position. New position = Old position + deltaPos
     * \param deltaPos Delta position
     */
    void move(const Vector2i& deltaPos);

    /**
     * \brief Get position
     * \return Position
     */
    Vector2i getPosition() const;

    /**
     * \brief Automatically call this function after setPosition()
     */
    virtual void onReposition();

    /**
     * \brief Set widget size. 
     * If size components less zero then will undefined behaviour.
     * After set size calling onResize()
     * \param size New size
     */
    void setSize(const Vector2i& size);

    /**
     * \brief Get widget size
     * \return Widget size
     */
    Vector2i getSize() const;

    /**
     * \brief Automatically call this function after setSize()
     */
    virtual void onResize();

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

    /**
     * \brief Recursive check if parent area contain \a point
     * \param point Point in widget relatively his own
     * \return True if parent area contain point, false if widget has no parent or
     * if parent area doesn't contain point
     */
    bool isIntoVisibleArea(const Vector2i& point) const;

protected:
    /**
     * \brief Default Widget constructor
     */
    Widget();

    /**
     * \brief Widget constructor. Construct it with default area
     * \param area Widget area
     */
    Widget(const Area& area);

    /**
     * \brief Widget constructor. Construct it with default area and
     * set parent
     * \param area Widget area
     * \param parent Smart ptr to parent container
     */
    Widget(const Area& area, Object::Ptr<Container> parent);

    /**
     * \brief Widget constructor. Construct it with default area and
     * set context
     * \param area Widget area
     * \param context Smart ptr to context
     */
    Widget(const Area& area, Object::Ptr<Context> context);

    /**
     * \brief Widget constructor. Construct it with default area and
     * set parent and context
     * \param area Widget area
     * \param parent Smart ptr to parent container
     * \param context Smart ptr to context
     */
    Widget(const Area& area, Object::Ptr<Container> parent, Object::Ptr<Context> context);

    /**
     * \brief Storage widget size and local position relatively parent. 
     * If size components less zero then will undefined behaviour.
     */
    Area m_area;

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
