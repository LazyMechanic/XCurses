#include <XCurses/XCurses.h>

class HelloWorldWindow : public xcur::Window
{
public:
    static Object::Ptr<HelloWorldWindow> create()
    {
        return std::shared_ptr<HelloWorldWindow>(new HelloWorldWindow());
    }

private:
    HelloWorldWindow() : 
        Window(xcur::Vector2u(0, 0), xcur::Curses::getTerminalSize()),
        m_str("Hello, World!"),
        m_pos(getAvailableArea().x / 2 - m_str.size() / 2, getAvailableArea().y / 2)
    {
        m_border = xcur::Border::Wide;
    }

    void draw() const override
    {
        Window::draw();
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
