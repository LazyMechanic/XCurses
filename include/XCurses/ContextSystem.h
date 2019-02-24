#pragma once

#include <list>

#include <XCurses/Object.h>

namespace xcur {
class Context;

class ContextSystem
{
public:
	friend class Core;

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
	 */
	void push(const Object::Ptr<Context>& context);

    /**
	 * \brief Add new context
	 * \param context Context
	 */
	void add(const Object::Ptr<Context>& context);

    /**
	 * \brief Remove current context and set next as current
	 */
	void pop();

    /**
	 * \brief Remove context and set next as current. If \a context is current
	 * then function is similar with \a pop()
	 * \param context Context
	 */
	void remove(const Object::Ptr<Context>& context);

    /**
	 * \brief Remove context by id and set next as current. If \a context is 
	 * current then function is similar with \a pop()
	 * \param contextId Context id 
	 */
	void remove(uint64_t contextId);

    /**
	 * \brief Set existed context as current
	 * \param context Context
	 */
	void setCurrent(const Object::Ptr<Context>& context);

    /**
	 * \brief Set existed context as current by id
	 * \param contextId Context id
	 */
	void setCurrent(uint64_t contextId);

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

private:
    /**
	 * \brief 
	 * \param contextId Context id
	 * \return Iterator to the context
	 */
	std::list<Object::Ptr<Context>>::iterator findContext(uint64_t contextId);

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