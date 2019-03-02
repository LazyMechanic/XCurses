#pragma once

#include <XCurses/Graphics/Context.h>

namespace xcur {
class ContextComponent
{
public:
    /**
     * \brief ContextComponent destructor
     */
    virtual ~ContextComponent();

    /**
     * \brief Set new context
     * \param context Context
     */
    void setContext(Object::Ptr<Context> context);

    /**
     * \brief Get ptr to context
     * \return Smart ptr to context
     */
    Object::Ptr<Context> getContext() const;

private:
    /**
     * \brief Ptr to context
     */
    Object::WeakPtr<Context> m_context;
};
}