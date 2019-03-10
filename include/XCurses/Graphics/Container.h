#pragma once

#include <list>

#include <XCurses/System/Status.h>
#include <XCurses/Graphics/Widget.h>

namespace xcur {
class Container : 
    public Widget
{
public:
	/**
	 * \brief Create Container
	 * \return Smart ptr to Container
	 */
	static Object::Ptr<Container> create();

    /**
     * \brief Container destructor
     */
    virtual ~Container() = default;

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
	 * \brief Set position. Update positions all child widgets
	 * \param newPos New position
	 */
	void setPosition(const Vector2u& newPos) override;

	/**
	 * \brief Set position. New position = Old position + deltaPos. Update positions all child widgets
	 * \param deltaPos Delta position
	 */
	void move(const Vector2u& deltaPos) override;

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
    std::list<Object::Ptr<Widget>>::const_iterator begin() const;

    /**
     * \brief End const iterator of child widgets
     * \return End const iterator
     */
    std::list<Object::Ptr<Widget>>::const_iterator end() const;

    /**
     * \brief Find widget in child widgets
     * \param widget Widget
     * \return Const iterator
     */
    std::list<Object::Ptr<Widget>>::const_iterator find(Object::Ptr<Widget> widget) const;

protected:
    /**
	 * \brief Default Container constructor
	 */
	Container() = default;

    /**
     * \brief List of child widgets
     */
    std::list<Object::Ptr<Widget>> m_childWidgets;
};
}