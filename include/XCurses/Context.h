#pragma once

#include <list>
#include <memory>
#include <functional>

#include <XCurses/Widget.h>
#include <XCurses/Drawable.h>
#include <XCurses/Behaviour.h>
#include <XCurses/RootObject.h>

namespace xcur {
class Core;

class Context : 
    public Drawable, 
    public Behaviour, 
    public std::enable_shared_from_this<Context>
{
public:
    /**
	 * \brief Friend class for setup m_contextSystem
	 */
	friend class ContextSystem;

    /**
	 * \brief Handle input events
	 */
	void handleEvents();

    /**
	 * \brief Goes through all components and call his update() function
	 * \param dt Delta time
	 */
	void update(float dt) override final;

    /**
	 * \brief Goes through all components and call his draw() function
	 */
	void draw() override final;

    /**
	 * \brief Add window or any inherit of RootObject
	 * \param object Object
	 */
	virtual void add(const Object::Ptr<RootObject>& object) final;

	/**
	 * \brief Add widget. It will add with weak ptr for call update() func. 
	 * Widget doesn't stored in context
	 * \param widget Widget
	 */
	virtual void add(const Object::Ptr<Widget>& widget) final;

    /**
	 * \brief Remove window or any inherit of RootObject
	 * \param object Object
	 */
	virtual void remove(const Object::Ptr<RootObject>& object) final;

	/**
	 * \brief Remove widget. Remove only weak ptr. 
	 * Widget doesn't stored in context
	 * \param widget Widget
	 */
	virtual void remove(const Object::Ptr<Widget>& widget) final;

    /**
	 * \brief Add new add or remove tasks
	 * \param task Task
	 */
	virtual void addTask(const std::function<void()>& task) final;

    /**
	 * \brief Get ptr to core
	 * \return Ptr to core
	 */
	virtual Core* getCore() const final;

    /**
	 * \brief Get ptr to context system
	 * \return Ptr to context system
	 */
	virtual ContextSystem* getContextSystem() const final;

protected:
    /**
	 * \brief Default Context constructor
	 */
	Context();

    /**
	 * \brief Goes through all components and call its update() function
	 * \param dt Delta time
	 */
	virtual void updateComponents(float dt) final;

	/**
	 * \brief Find the component in m_allComponents
	 * \param component Component
	 * \return Iterator to component if it found, end iterator if the component
	 * not found
	 */
	virtual std::list<Object::WeakPtr<ContextComponent>>::iterator findComponent(const Object::Ptr<ContextComponent>& component) final;

	/**
	 * \brief Stored all root objects e.g. Window or Nondrawable
	 */
	std::list<Object::Ptr<RootObject>> m_rootObjects;

    /**
	 * \brief Everything components which have update() and draw() functions 
	 */
	std::list<Object::WeakPtr<ContextComponent>> m_allComponents;

private:
    /**
	 * \brief Function try add component in m_allComponents
	 * \param component Component
	 * \result Ok if add successful, Err otherwise
	 */
	Status tryAdd(const Object::Ptr<ContextComponent>& component);

	/**
	 * \brief Function try remove component from m_allComponents
	 * \param component Component
	 * \result Ok if remove successful, Err otherwise
	 */
	Status tryRemove(const Object::Ptr<ContextComponent>& component);

    /**
	 * \brief Ptr to context system
	 */
	ContextSystem* m_contextSystem;
};
}
