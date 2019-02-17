#pragma once

#include <XCurses/Drawable.h>
#include <XCurses/Behaviour.h>

namespace xcur {
class ContextComponent : public Drawable, public Behaviour
{
public:
	friend class Context;

    /**
	 * \brief ContextComponent destructor
	 */
	virtual ~ContextComponent();

	/**
	 * \brief Get ptr to context
	 * \return
	 */
	virtual Object::Ptr<Context> getContext() final;

protected:
    /**
	 * \brief Default ContextComponent constructor 
	 */
	ContextComponent() = default;

private:
	/**
	 * \brief Ptr to context
	 */
	Object::WeakPtr<Context> m_context;
};
}