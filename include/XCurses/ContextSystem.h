#pragma once

#include <list>

#include <XCurses/Status.h>
#include <XCurses/Context.h>

namespace xcur {
class Core;

class ContextSystem
{
public:
    /**
     * \brief Default ContextSystem constructor
     */
    ContextSystem() = default;

    /**
     * \brief Copy ContextSystem constructor
     */
    ContextSystem(const ContextSystem&) = default;

    /**
     * \brief Move ContextSystem constructor. It is delete
     */
    ContextSystem(ContextSystem&&) = delete;

    /**
     * \brief Default copy assignment operator
     * \return Reference to \a this
     */
    ContextSystem& operator =(const ContextSystem&) = default;

    /**
     * \brief Default move assignment operator. It is delete
     * \return Reference to \a this
     */
    ContextSystem& operator =(ContextSystem&&) = delete;

    /**
     * \brief ContextSystem destructor
     */
    ~ContextSystem() = default;

    /**
     * \brief Handle input events from current context
     */
    void handleEvents();

    /**
     * \brief Update current context state
     * \param dt Delta time
     */
    void update(float dt);

    /**
     * \brief Draw current context state
     */
    void draw();
    
    /**
     * \brief Add new context and set it as current
     * \param context Context
     * \return Ok if push successful, Err if context already exists
     */
    Status push(Object::Ptr<Context> context);

    /**
     * \brief Add new context
     * \param context Context
     * \return Ok if add successful, Err if context already exists
     */
    Status add(Object::Ptr<Context> context);

    /**
     * \brief Remove current context and set next as current
     * \return Ok if pop successful, Err if no contexts left
     */
    Status pop();

    /**
     * \brief Remove context and set next as current. If \a context is current
     * then function is similar with \a pop()
     * \param context Context
     * \return Ok if remove successful, Err if no contexts left
     */
    Status remove(Object::Ptr<Context> context);

    /**
     * \brief Set existed context as current
     * \param context Context
     */
    Status setCurrent(Object::Ptr<Context> context);

    /**
     * \brief Get current context
     * \return Smart ptr to context
     */
    Object::Ptr<Context> getCurrent() const;

    /**
     * \brief Get ptr to core
     * \return Ptr to core
     */
    Core* getCore() const;

    /**
     * \brief Set ptr to core
     * \param core Ptr to core
     */
    void setCore(Core* core);

private:
    /**
     * \brief Find the context in m_contexts
     * \param context Context
     * \return Iterator to the context
     */
    std::list<Object::Ptr<Context>>::iterator findContext(Object::Ptr<Context> context);

    /**
     * \brief Current context
     */
    Object::WeakPtr<Context> m_currentContext;

    /**
     * \brief Container of all contexts
     */
    std::list<Object::Ptr<Context>> m_contexts;

    /**
     * \brief Ptr to core
     */
    Core* m_core;
};
}