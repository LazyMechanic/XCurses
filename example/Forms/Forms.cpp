#include <XCurses/XCurses.h>
#include <iostream>

int main()
{
    // Init curses mode
    xcur::Curses::init();
    // Create context
    xcur::Object::Ptr<xcur::Context> myContext = xcur::Context::create();

    // Create form
    xcur::Object::Ptr<xcur::TextArea> myForm = xcur::TextArea::create(xcur::Vector2u(5, 5), xcur::Vector2u(10, 3));
    myForm->setContent("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;\'\"({[]})_-=+*&^%$#@! 1234567890");

    // Add window into context root container
    myContext->add(myForm);

    // Create Core and run main loop
    xcur::Core::create()->run(myContext);
}
