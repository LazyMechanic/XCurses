#pragma once

#include <memory>

#include <XCurses/Status.h>
#include <XCurses/Object.h>
#include <XCurses/Drawable.h>
#include <XCurses/Behaviour.h>

namespace xcur {
namespace detail {
class TreeNode;
}
class Core;
class Widget;
class Container;
class ContextSystem;

class Context :
    public Object,
    public Drawable,
    public Behaviour,
    public std::enable_shared_from_this<Context>
{
public:
    /**
	 * \brief Default Context constructor
	 */
	Context();

    /**
	 * \brief Handle input events
	 */
	void handleEvents();

    /**
	 * \brief Goes through all components and call his \a update() function
	 * \param dt Delta time
	 */
	void update(float dt) override final;

    /**
	 * \brief Goes through all components and call his \a draw() function
	 */
	void draw() override final;

	/**
	 * \brief Add widget. Set context ptr and add to \a update() and \a draw() queues.
	 * Widget doesn't stored in context. If widget is container then add all child widgets
	 * \param widget Widget
	 */
	virtual Status add(Object::Ptr<Widget> widget) final;

	/**
	 * \brief Remove widget. Remove only weak ptr from queues. 
	 * Widget doesn't stored in context. If widget is container then remove all child widgets
	 * \param widget Widget
	 * \return Ok if remove successful, Err otherwise
	 */
	virtual Status remove(Object::Ptr<Widget> widget) final;

    /**
	 * \brief Find widget in widget tree
	 * \param widget Widget
	 * \return True if context has widget, false otherwise
	 */
	virtual bool has(Object::Ptr<Widget> widget) const final;

    /**
	 * \brief Put widget to front
	 * \param widget Widget
	 */
	void toFront(Object::Ptr<Widget> widget);

    /**
	 * \brief Get ptr to core
	 * \return Ptr to core
	 */
	Core* getCore() const;

    /**
	 * \brief Set ptr to context system
	 * \param contextSystem Context system
	 */
	void setContextSystem(ContextSystem* contextSystem);

    /**
	 * \brief Get ptr to context system
	 * \return Ptr to context system
	 */
	ContextSystem* getContextSystem() const;

protected:
    /**
	 * \brief Root widget
	 */
	Object::Ptr<Container> m_rootWidget;

    /**
	 * \brief Widget tree root node. Need for call \a update() and \a draw() functions in the correct sequence
	 */
	Object::Ptr<detail::TreeNode> m_widgetTreeRoot;

private:
    /**
	 * \brief Add container widget
	 * \param container Container
	 * \return Ok if remove successful, Err otherwise
	 */
	Status addContainerWidget(Object::Ptr<Container> container);

    /**
	 * \brief Add single widget
	 * \param widget Widget
	 * \return Ok if remove successful, Err otherwise
	 */
	Status addSingleWidget(Object::Ptr<Widget> widget);

    /**
	 * \brief Ptr to context system
	 */
	ContextSystem* m_contextSystem;
};
}
