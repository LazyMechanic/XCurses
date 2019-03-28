#include <XCurses/XCurses.h>

class MyTextArea : public xcur::TextArea
{
public:
    static Object::Ptr<MyTextArea> create(const xcur::Area& area)
    {
        std::shared_ptr<MyTextArea> result(new MyTextArea(area));
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
    xcur::Object::Ptr<MyTextArea> myTextArea_1 = MyTextArea::create(xcur::Area(5, 5, 10, 3));
    myTextArea_1->setContent(
        xcur::String("1. abcdefg") +
        xcur::String("2. abcdefg") +
        xcur::String("3. abcdefg") +
        xcur::String("4. abcdefg") +
        xcur::String("5. abcdefg") +
        xcur::String("6. abcdefg"));

    xcur::Object::Ptr<MyTextArea> myTextArea_2 = MyTextArea::create(xcur::Area(20, 5, 3, 10));
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

    xcur::Object::Ptr<MyTextArea> myTextArea_3 = MyTextArea::create(xcur::Area(30, 5, 10, 7));
    myTextArea_3->setContent(
        xcur::String("1. abcdefg") +
        xcur::String("2. abcdefg") +
        xcur::String("3. abcdefg") +
        xcur::String("4. abcdefg") +
        xcur::String("5. abcdefg") +
        xcur::String("6. abcdefg"));

    // Create scroll bar
    xcur::Object::Ptr<MyScrollBar> myScrollBar = MyScrollBar::create(xcur::Area(1, 10, 3, 15));

    // Create input text area
    xcur::Object::Ptr<xcur::InputTextArea> myInputTextArea_1 = xcur::InputTextArea::create(xcur::Area(30, 20,10, 3));
    myContext->setActiveInputWidget(myInputTextArea_1);

    // Create text box
    xcur::Object::Ptr<xcur::TextBox> myTextBox_1 = xcur::TextBox::create(xcur::Area(25, 25, 15, 10));
    myTextBox_1->setTextArea(MyTextArea::create(xcur::Area(0, 0, 0, 0)));
    myTextBox_1->getTextArea()->setContent(
        xcur::String("1. abcdefghij") +
        xcur::String("2. abcdefghij") +
        xcur::String("3. abcdefghij") +
        xcur::String("4. abcdefghij") +
        xcur::String("5. abcdefghij") +
        xcur::String("6. abcdefghij") +
        xcur::String("7. abcdefghij") +
        xcur::String("8. abcdefghij") +
        xcur::String("9. abcdefghij") +
        xcur::String("10.abcdefghij") +
        xcur::String("11.abcdefghij") +
        xcur::String("12.abcdefghij"));

    // Add text areas into context
    myContext->add(myTextArea_1);
    myContext->add(myTextArea_2);
    myContext->add(myTextArea_3);

    // Add scroll bars into context
    myContext->add(myScrollBar);

    // Add input text areas into context
    myContext->add(myInputTextArea_1);

    // Add text boxes into context
    myContext->add(myTextBox_1);

    // Create Core and run main loop
    xcur::Core::create()->run(myContext);
}
