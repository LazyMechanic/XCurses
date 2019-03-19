#include <XCurses/XCurses.h>
#include <iostream>

class HelloWorldWindow : public xcur::Window
{
public:
    static Object::Ptr<HelloWorldWindow> create()
    {
        std::shared_ptr<HelloWorldWindow> result(new HelloWorldWindow());
        result->setBorder(xcur::Border::create(xcur::BorderTraits::Simple));
        result->setTitle(xcur::Title::create(xcur::Vector2u(2, 0),"Hello_World"));
        return result;
    }

private:
    HelloWorldWindow() : 
        Window(xcur::Vector2u(0, 0), xcur::Curses::getTerminalSize()),
        m_str("Hello, World!"),
        m_pos(getAvailableArea().x / 2 - m_str.size() / 2, getAvailableArea().y / 2)
    {
    }

    void draw() const override
    {
        addString(m_str, m_pos);
    }

    xcur::String m_str;
    xcur::Vector2u m_pos;
};

int main()
{
    // Init curses mode
    xcur::Curses::init();
    // Create context
    xcur::Object::Ptr<xcur::Context> myContext = xcur::Context::create();
    // Create window
    xcur::Object::Ptr<HelloWorldWindow> helloWorldWindow = HelloWorldWindow::create();
    // Add window into context root container
    myContext->add(helloWorldWindow);

    // Create Core and run main loop
    xcur::Core::create()->run(myContext);
}
