#pragma once

#include <list>

#include <XCurses/Status.h>
#include <XCurses/Widget.h>

namespace xcur {
class Container : 
    public Widget
{
public:
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
    virtual Status add(Object::Ptr<Widget> widget) final;

    /**
     * \brief Remove widget from container
     * \param widget Widget
     * \result Ok if successful, Err if widget has another parent
     */
    virtual Status remove(Object::Ptr<Widget> widget) final;

    /**
     * \brief Check if container storing the widget
     * \param widget
     * \return True if container contain the widget, false otherwise
     */
    virtual bool has(Object::Ptr<Widget> widget) final;

    /**
     * \brief Put widget to front
     * \param widget Widget
     */
    virtual void widgetToFront(Object::Ptr<Widget> widget) final;

    /**
     * \brief Begin const iterator of child widgets
     * \return Begin const iterator
     */
    virtual std::list<Object::Ptr<Widget>>::const_iterator begin() const final;

    /**
     * \brief End const iterator of child widgets
     * \return End const iterator
     */
    virtual std::list<Object::Ptr<Widget>>::const_iterator end() const final;

    /**
     * \brief Find widget in child widgets
     * \param widget Widget
     * \return Const iterator
     */
    virtual std::list<Object::Ptr<Widget>>::const_iterator find(Object::Ptr<Widget> widget) const final;

protected:
    /**
     * \brief List of child widgets
     */
    std::list<Object::Ptr<Widget>> m_childWidgets;
};
}