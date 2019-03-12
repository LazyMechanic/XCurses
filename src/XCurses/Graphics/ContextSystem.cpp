#include <XCurses/Graphics/ContextSystem.h>

#include <algorithm>

#include <XCurses/System/Core.h>
#include <XCurses/Graphics/Context.h>

namespace xcur {
Object::Ptr<ContextSystem> ContextSystem::create()
{
    return std::shared_ptr<ContextSystem>(new ContextSystem());
}

void ContextSystem::handleEvents() const
{
    auto currentContext = m_currentContext.lock();
    // If the current context is set
    if (currentContext != nullptr) {
        currentContext->handleEvents();
    }
}

void ContextSystem::update(float dt) const
{
    auto currentContext = m_currentContext.lock();
    // If the current context is set
    if (currentContext != nullptr) {
        currentContext->update(dt);
    }
}

void ContextSystem::draw() const
{
    auto currentContext = m_currentContext.lock();
    // If the current context is set
    if (currentContext != nullptr) {
        currentContext->draw();
    }
}

Status ContextSystem::push(Object::Ptr<Context> context)
{
    // If context not created
    if (context == nullptr) {
        return Status::Err;
    }

    // If add operation fails
    if (add(context) == Status::Err) {
        return Status::Err;
    }

    return setCurrent(context);
}

Status ContextSystem::add(Object::Ptr<Context> context)
{
    auto foundContext = findContext(context);
    // If context already exists
    if (foundContext != m_contexts.end()) {
        return Status::Err;
    }

    context->setContextSystem(shared_from_this());
    m_contexts.push_back(context);
    return Status::Ok;
}

Status ContextSystem::pop()
{
    Status removeStatus = remove(m_currentContext.lock());
    if (removeStatus == Status::Err) {
        return Status::Err;
    }

    return setCurrent(m_contexts.back());
}

Status ContextSystem::remove(Object::Ptr<Context> context)
{
    auto foundContext = findContext(context);
    // If context not found
    if (foundContext == m_contexts.end()) {
        return Status::Err;
    }

    context->setContextSystem(nullptr);
    m_contexts.erase(foundContext);
    return Status::Ok;
}

Status ContextSystem::setCurrent(Object::Ptr<Context> context)
{
    auto foundContext = findContext(context);
    // If context not found
    if (foundContext == m_contexts.end()) {
        return Status::Err;
    }

    m_currentContext = *foundContext;
    return Status::Ok;
}

Object::Ptr<Context> ContextSystem::getCurrent() const
{
    return m_currentContext.lock();
}

void ContextSystem::setCore(Object::Ptr<Core> core)
{
    m_core = core;
}

Object::Ptr<Core> ContextSystem::getCore() const
{
    return m_core.lock();
}

std::list<Object::Ptr<Context>>::iterator ContextSystem::findContext(Object::Ptr<Context> context)
{
    return std::find_if(m_contexts.begin(), m_contexts.end(), [&context](const Object::Ptr<Context>& checkContext) {
        return context == checkContext;
    });
}
}
