#pragma once

#include <list>
#include <memory>

#include <XCurses/Text/Char.h>
#include <XCurses/System/Status.h>
#include <XCurses/System/Object.h>
#include <XCurses/System/Vector2.h>
#include <XCurses/System/Inputtable.h>
#include <XCurses/Graphics/Drawable.h>
#include <XCurses/Graphics/Behaviour.h>
#include <XCurses/Graphics/VirtualScreen.h>

namespace xcur {
namespace detail {
class TreeNode;
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
    void handleEvents() const;

    /**
     * \brief Goes through all components and call his \a update() function
     * \param dt Delta time
     */
    void update(float dt) override final;

    /**
     * \brief Goes through all components and call his \a draw() function
     */
    void draw() const override final;

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
     * \brief Add character to virtual screen for draw
     * \param widget Widget for which need draw character
     * \param ch Character
     * \param position Position relative to widget
     */
    void addToVirtualScreen(Object::Ptr<Widget> widget, const Char& ch, const Vector2u& position);

    /**
     * \brief Set active inputtable widget
     * \param inputWidget Widget which need set active. If it is Inputtable::None (nullptr) 
     * then off cursor
     */
    void setActiveInputWidget(Object::Ptr<Inputtable> inputWidget);

    /**
     * \brief Get active inputtable widget
     * \return Smart ptr to active inputtable widget
     */
    Object::Ptr<Inputtable> getActiveInputWidget() const;

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
     * \brief Set context system.
     * Do not need use manually
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
     * \brief Root container
     */
    Object::Ptr<Container> m_rootContainer;

    /**
     * \brief Buffer for all chars for drawing
     */
    Object::Ptr<VirtualScreen> m_virtualScreen;

    /**
     * \brief Widget tree root node. Need for call \a update() and \a draw() functions 
     * in the correct sequence
     */
    Object::Ptr<detail::TreeNode> m_widgetTreeRoot;

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
};
}
