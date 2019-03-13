#include <XCurses/Graphics/Context.h>

#include <algorithm>

#include <PDCurses/curses.h>

#include <XCurses/System/Input.h>
#include <XCurses/Graphics/Widget.h>
#include <XCurses/Graphics/Window.h>
#include <XCurses/Graphics/TreeNode.h>
#include <XCurses/Graphics/Container.h>
#include <XCurses/Graphics/RootWindow.h>
#include <XCurses/Graphics/ContextSystem.h>

namespace xcur {
Object::Ptr<Context> Context::create()
{
    return std::shared_ptr<Context>(new Context());
}

Context::Context() :
    m_rootWindow(detail::RootWindow::create()),
    m_widgetTreeRoot(detail::TreeNode::create(m_rootWindow))
{
}

void Context::handleEvents()
{
    // TODO: fill handleEvents() function
}

void Context::update(float dt)
{
    m_widgetTreeRoot->update(dt);
}

void Context::draw()
{
    wclear(stdscr);
    m_widgetTreeRoot->draw();
    refreshWindows();
    doupdate();
}

Status Context::add(Object::Ptr<Widget> widget)
{
    // If widget already exists
    if (has(widget)) {
        return Status::Err;
    }

    auto container = std::dynamic_pointer_cast<Container>(widget);
    // If widget is container
    if (container != nullptr) {
        return addContainerWidget(container);
    }
    else {
        return addSingleWidget(widget);
    }
}

Status Context::remove(Object::Ptr<Widget> widget)
{
    auto foundNode = m_widgetTreeRoot->findInSubtreeByWidget(widget);
    // If node not found
    if (foundNode == nullptr) {
        return Status::Err;
    }

    // If widget parent is root widget of context
    if (widget->getParent() == m_rootWindow) {
        m_rootWindow->remove(widget);
    }

    foundNode->getParent()->remove(widget);
    widget->setContext(nullptr);
    return Status::Ok;
}

bool Context::has(Object::Ptr<Widget> widget) const
{
    return m_widgetTreeRoot->has(widget);
}

void Context::widgetToFront(Object::Ptr<Widget> widget) const
{
    auto foundNode = m_widgetTreeRoot->findInSubtreeByWidget(widget);
    // if node found
    if (foundNode != nullptr) {
        foundNode->getParent()->widgetToFront(widget);
    }
}

void Context::addWindowToRefresh(Object::Ptr<Window> window)
{
    m_windowsToRefresh.emplace_back(window);
}

void Context::setContextSystem(Object::Ptr<ContextSystem> contextSystem)
{
    m_contextSystem = contextSystem;
}

Object::Ptr<ContextSystem> Context::getContextSystem() const
{
    return m_contextSystem.lock();
}

Status Context::addContainerWidget(Object::Ptr<Container> container)
{
    Status addStatus = addSingleWidget(container);
    // If add container end with error
    if (addStatus == Status::Err) {
        return Status::Err;
    }
    for (auto childIt = container->begin(); childIt != container->end(); ++childIt) {
        add(*childIt);
    }
    return Status::Ok;
}

Status Context::addSingleWidget(Object::Ptr<Widget> widget)
{
    // If widget has parent
    if (widget->getParent() != nullptr) {
        auto parent = m_widgetTreeRoot->findInSubtreeByWidget(std::dynamic_pointer_cast<Widget>(widget->getParent()));
        // If parent is wrong
        if (parent == nullptr) {
            return Status::Err;
        }
        parent->add(widget);
    }
    else {
        m_rootWindow->add(widget);
        m_widgetTreeRoot->add(widget);
    }
    widget->setContext(shared_from_this());

    return Status::Ok;
}

void Context::refreshWindows()
{
    for (const auto& window : m_windowsToRefresh) {
        auto sharedWindow = window.lock();
        // If window still exists
        if (sharedWindow != nullptr) {
            touchwin(sharedWindow->getCursesWin());
            wnoutrefresh(sharedWindow->getCursesWin());
        }
    }
    m_windowsToRefresh.clear();
}
}
