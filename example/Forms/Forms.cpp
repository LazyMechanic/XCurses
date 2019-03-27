#include <XCurses/XCurses.h>

class MyTextArea : public xcur::TextArea
{
public:
    static Object::Ptr<MyTextArea> create(const xcur::Area& area)
    {
        std::shared_ptr<MyTextArea> result(new MyTextArea(area));
        //result->setContent("Hello buddies.\nThis is text area, which automatically scroll up and down every " + xcur::String::toString(result->m_maxTime) + " seconds");
        return result;
    }

    void update(float dt) override
    {
        m_time += dt;

        if (m_time >= m_maxTime) {
            if (m_currentScrollOffset == m_maxScrollOffset) {
                m_direction = -1;
            }
            else if (m_currentScrollOffset == 0) {
                m_direction = 1;
            }

            scroll(m_direction);

            m_time = 0.0f;
        }
        TextArea::update(dt);
    }

private:
    MyTextArea(const xcur::Area& area) :
        TextArea(area),
        m_time(0.0f),
        m_maxTime(1.0f),
        m_direction(1)
    {
    }

    float m_time;
    float m_maxTime;
    int m_direction;
};

class MyScrollBar : public xcur::ScrollBar
{
public:
    static Object::Ptr<MyScrollBar> create(const xcur::Area& area)
    {
        return std::shared_ptr<MyScrollBar>(new MyScrollBar(area));
    }

    void update(float dt) override
    {
        m_time += dt;

        if (m_time >= m_maxTime) {
            if (m_currentValue == m_maxValue) {
                m_direction = -1;
            }
            else if (m_currentValue == 0) {
                m_direction = 1;
            }

            if (m_direction == 1) {
                m_currentValue++;
            }
            else {
                m_currentValue--;
            }

            m_time = 0.0f;
        }
    }

private:
    MyScrollBar(const xcur::Area& area) :
        ScrollBar(area),
        m_time(0.0f),
        m_maxTime(1.0f),
        m_direction(1)
    {
        m_maxValue = 5;
        m_currentValue = 0;
    }

    float m_time;
    float m_maxTime;
    int m_direction;
};

int main()
{
    // Init curses mode
    xcur::Curses::init();
    // Create context
    xcur::Object::Ptr<xcur::Context> myContext = xcur::Context::create();

    // Create text areas
    xcur::Object::Ptr<MyTextArea> myTextArea_1 = MyTextArea::create(xcur::Area(xcur::Vector2i(5, 5), xcur::Vector2i(10, 3)));
    myTextArea_1->setContent(
        xcur::String("1. abcdefg") +
        xcur::String("2. abcdefg") +
        xcur::String("3. abcdefg") +
        xcur::String("4. abcdefg") +
        xcur::String("5. abcdefg") +
        xcur::String("6. abcdefg"));

    xcur::Object::Ptr<MyTextArea> myTextArea_2 = MyTextArea::create(xcur::Area(xcur::Vector2i(20, 5), xcur::Vector2i(3, 10)));
    myTextArea_2->setContent(
        xcur::String("1. ") +
        xcur::String("2. ") +
        xcur::String("3. ") +
        xcur::String("4. ") +
        xcur::String("5. ") +
        xcur::String("6. ") +
        xcur::String("7. ") +
        xcur::String("8. ") +
        xcur::String("9. ") +
        xcur::String("10.") +
        xcur::String("11.") +
        xcur::String("12."));

    xcur::Object::Ptr<MyTextArea> myTextArea_3 = MyTextArea::create(xcur::Area(xcur::Vector2i(30, 5), xcur::Vector2i(10, 7)));
    myTextArea_3->setContent(
        xcur::String("1. abcdefg") +
        xcur::String("2. abcdefg") +
        xcur::String("3. abcdefg") +
        xcur::String("4. abcdefg") +
        xcur::String("5. abcdefg") +
        xcur::String("6. abcdefg"));

    xcur::Object::Ptr<MyScrollBar> myScrollBar = MyScrollBar::create(xcur::Area(xcur::Vector2i(1, 10), xcur::Vector2i(3, 15)));
    myContext->add(myScrollBar);

    // Create input text area
    xcur::Object::Ptr<xcur::InputTextArea> myInputTextArea = xcur::InputTextArea::create(xcur::Area(xcur::Vector2i(30, 20), xcur::Vector2i(10, 3)));
    myContext->add(myInputTextArea);
    myContext->setActiveInputWidget(myInputTextArea);

    // Add text area into context root container
    myContext->add(myTextArea_1);
    myContext->add(myTextArea_2);
    myContext->add(myTextArea_3);

    // Create Core and run main loop
    xcur::Core::create()->run(myContext);
}
