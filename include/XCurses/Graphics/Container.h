#pragma once

#include <list>

#include <XCurses/System/Status.h>
#include <XCurses/Graphics/Widget.h>

namespace xcur {
/**
 * \brief Base class of widget container. It contains and controls widgets
 */
class Container : 
    public Widget
{
public:
    /**
     * \brief std::list<Object::Ptr<Widget>>::iterator alias
     */
    using Iterator = std::list<Object::Ptr<Widget>>::iterator;

    /**
     * \brief std::list<Object::Ptr<Widget>>::const_iterator alias
     */
    using ConstIterator = std::list<Object::Ptr<Widget>>::const_iterator;

    /**
     * \brief std::list<Object::Ptr<Widget>>::reverse_iterator alias
     */
    using ReverseIterator = std::list<Object::Ptr<Widget>>::reverse_iterator;

    /**
     * \brief std::list<Object::Ptr<Widget>>::const_reverse_iterator alias
     */
    using ConstReverseIterator = std::list<Object::Ptr<Widget>>::const_reverse_iterator;

    /**
     * \brief Create Container with zero position and size
     * \return Smart ptr to Container
     */
    static Object::Ptr<Container> create();

    /**
     * \brief Create Container with default position and size
     * \param position Container position
     * \param size Container size
     */
    static Object::Ptr<Container> create(const Vector2u& position, const Vector2u& size);

    /**
     * \brief Create Container with default position, size and
     * set parent
     * \param position Container position
     * \param size Container size
     * \param parent Smart ptr to parent container
     */
    static Object::Ptr<Container> create(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent);

    /**
     * \brief Create Container with default position, size and
     * set context
     * \param position Container position
     * \param size Container size
     * \param context Smart ptr to context
     */
    static Object::Ptr<Container> create(const Vector2u& position, const Vector2u& size, Object::Ptr<Context> context);

    /**
     * \brief Create Container with default position, size and
     * set parent and context
     * \param position Container position
     * \param size Container size
     * \param parent Smart ptr to parent container
     * \param context Smart ptr to context
     */
    static Object::Ptr<Container> create(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent, Object::Ptr<Context> context);

    /**
     * \brief Container destructor
     */
    virtual ~Container() = default;

    /**
     * \brief Add widget to container
     * \param widget Widget
     * \result Ok if successful, Err if widget has another parent
     */
    Status add(Object::Ptr<Widget> widget);

    /**
     * \brief Remove widget from container
     * \param widget Widget
     * \result Ok if successful, Err if widget has another parent
     */
    Status remove(Object::Ptr<Widget> widget);

    /**
     * \brief Check if container storing the widget
     * \param widget
     * \return True if container contain the widget, false otherwise
     */
    bool has(Object::Ptr<Widget> widget);

    /**
     * \brief Put widget to front
     * \param widget Widget
     */
    void widgetToFront(Object::Ptr<Widget> widget);

    /**
     * \brief Begin const iterator of child widgets
     * \return Begin const iterator
     */
    ConstIterator begin() const;

    /**
     * \brief End const iterator of child widgets
     * \return End const iterator
     */
    ConstIterator end() const;

    /**
     * \brief Begin const reverse iterator of child widgets
     * \return Begin const reverse iterator
     */
    ConstReverseIterator rbegin() const;

    /**
     * \brief End const reverse iterator of child widgets
     * \return End const reverse iterator
     */
    ConstReverseIterator rend() const;

    /**
     * \brief Find widget in child widgets
     * \param widget Widget
     * \return Const iterator
     */
    ConstIterator find(Object::Ptr<Widget> widget) const;

protected:
    /**
     * \brief Default Container constructor. Construct it with zero position and size
     */
    Container() = default;

    /**
     * \brief Container constructor. Construct it with default position and size
     * \param position Container position
     * \param size Container size
     */
    Container(const Vector2u& position, const Vector2u& size);

    /**
     * \brief Container constructor. Construct it with default position, size and
     * set parent
     * \param position Container position
     * \param size Container size
     * \param parent Smart ptr to parent container
     */
    Container(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent);

    /**
     * \brief Container constructor. Construct it with default position, size and
     * set context
     * \param position Container position
     * \param size Container size
     * \param context Smart ptr to context
     */
    Container(const Vector2u& position, const Vector2u& size, Object::Ptr<Context> context);

    /**
     * \brief Container constructor. Construct it with default position, size and
     * set parent and context
     * \param position Container position
     * \param size Container size
     * \param parent Smart ptr to parent container
     * \param context Smart ptr to context
     */
    Container(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent, Object::Ptr<Context> context);

    /**
     * \brief List of child widgets
     */
    std::list<Object::Ptr<Widget>> m_childWidgets;
};
}