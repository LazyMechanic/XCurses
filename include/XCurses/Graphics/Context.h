#pragma once

#include <list>
#include <memory>

#include <XCurses/System/Status.h>
#include <XCurses/System/Object.h>
#include <XCurses/Graphics/Drawable.h>
#include <XCurses/Graphics/Behaviour.h>

namespace xcur {
namespace detail {
class TreeNode;
class RootWindow;
}
class Widget;
class Window;
class Container;
class ContextSystem;

/**
 * \brief Class contains and controls widgets
 */
class Context :
    public Object,
    public Drawable,
    public Behaviour,
    public std::enable_shared_from_this<Context>
{
public:
	/**
	 * \brief Create Context
	 * \return Smart ptr to Context
	 */
	static Object::Ptr<Context> create();

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
     * \result Ok if successful, Err otherwise
     */
    Status add(Object::Ptr<Widget> widget);

    /**
     * \brief Remove widget. Remove only weak ptr from queues. 
     * Widget doesn't stored in context. If widget is container then remove all child widgets
     * \param widget Widget
     * \return Ok if remove successful, Err otherwise
     */
    Status remove(Object::Ptr<Widget> widget);

    /**
     * \brief Find widget in widget tree
     * \param widget Widget
     * \return True if context has widget, false otherwise
     */
    bool has(Object::Ptr<Widget> widget) const;

    /**
     * \brief Put widget to front
     * \param widget Widget
     */
    void widgetToFront(Object::Ptr<Widget> widget) const;

    /**
	 * \brief Add window to refresh queue. After call all draw functions will call
	 * wnoutrefresh() for all windows
	 * \param window 
	 */
	void addWindowToRefresh(Object::Ptr<Window> window);

    /**
	 * \brief Set context system
	 * \param contextSystem Context system
	 */
	void setContextSystem(Object::Ptr<ContextSystem> contextSystem);

    /**
	 * \brief Get context system
	 * \return Smart ptr to context system
	 */
	Object::Ptr<ContextSystem> getContextSystem() const;

protected:
	/**
	 * \brief Default Context constructor
	 */
	Context();

    /**
     * \brief Root window
     */
    Object::Ptr<detail::RootWindow> m_rootWindow;

    /**
     * \brief Widget tree root node. Need for call \a update() and \a draw() functions 
     * in the correct sequence
     */
    Object::Ptr<detail::TreeNode> m_widgetTreeRoot;

    /**
	 * \brief Windows to refresh
	 */
	std::list<Object::WeakPtr<Window>> m_windowsToRefresh;

    /**
	 * \brief Ptr to context system
	 */
	Object::WeakPtr<ContextSystem> m_contextSystem;

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
	 * \brief Refresh all windows
	 */
	void refreshWindows();
};
}
