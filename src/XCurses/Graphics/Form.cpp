#include <XCurses/Graphics/Form.h>

#include <algorithm>

#include <XCurses/System/Input.h>
#include <XCurses/System/Context.h>

namespace xcur {
Form::LeftDirection Form::leftDirection;
Form::RightDirection Form::rightDirection;

Object::Ptr<Form> Form::create(const Vector2u& position, const Vector2u& size)
{
    return std::shared_ptr<Form>(new Form(position, size));
}

Form::Form(const Vector2u& position, const Vector2u& size)
{
    setPosition(position);
    Widget::setSize(size);
}

void Form::update(float dt)
{
    auto context = getContext();
    if (context != nullptr) {
        // If this widget is active
        if (context->isActiveInputWidget(std::dynamic_pointer_cast<Inputtable>(shared_from_this()))) {
            
            // TODO: Input handler in Form::update()
            Char ch = Input::getPressedKey();
            // If no input char
            if (ch == Char::Err) {
                return;
            }
            // If char is not spec key, but common symbol
            else if (ch > Char::Key::Delete) {
                m_content.insert(m_contentCursorPosition, ch);
                moveContentCursorPosition(1, rightDirection);
            }
            else if (ch == Char::Key::Backspace) {
                if (m_contentCursorPosition > 0) {
                    m_content.erase(m_contentCursorPosition - 1);
                    moveContentCursorPosition(1, leftDirection);
                }
            }
            else if (ch == Char::Key::Tab ||
                ch == Char::Key::LineFeed) 
            {
                m_content.insert(m_contentCursorPosition, ch);
                moveContentCursorPosition(1, rightDirection);
            }
            else if (ch == Char::Key::Delete) {
                // If content cursor position points to symbol
                if (m_contentCursorPosition < m_content.size()) {
                    m_content.erase(m_contentCursorPosition + 1);
                }
            }
        }
    }
}

void Form::draw() const
{
    auto context = getContext();
    if (context != nullptr) {

    }
}

void Form::setContentCursorPosition(size_t position)
{
    m_contentCursorPosition = std::min(position, m_content.size());
}

void Form::moveContentCursorPosition(size_t deltaPosition, LeftDirection)
{
    if (m_contentCursorPosition > deltaPosition) {
        m_contentCursorPosition -= deltaPosition;
    }
    else {
        m_contentCursorPosition = 0;
    }
}

void Form::moveContentCursorPosition(size_t deltaPosition, RightDirection)
{
    m_contentCursorPosition = std::min(m_contentCursorPosition + deltaPosition, m_content.size());
}

size_t Form::getContentCursorPosition() const
{
    return m_contentCursorPosition;
}

void Form::setContent(const String& str)
{
    m_content = str;
    m_contentCursorPosition = str.size();
}

String Form::getContent() const
{
    return m_content;
}
}
