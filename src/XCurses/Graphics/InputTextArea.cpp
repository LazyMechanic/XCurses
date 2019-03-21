#include <XCurses/Graphics/InputTextArea.h>

#include <XCurses/System/Context.h>

namespace xcur {
Object::Ptr<InputTextArea> InputTextArea::create(const Vector2u& position, const Vector2u& size)
{
    return std::shared_ptr<InputTextArea>(new InputTextArea(position, size));
}

InputTextArea::InputTextArea(const Vector2u& position, const Vector2u& size) :
    TextArea(position, size),
    Inputtable(m_size)
{
}

void InputTextArea::update(float dt)
{
    updateContent();
    TextArea::update(dt);
}

void InputTextArea::updateContent()
{
    auto context = getContext();
    if (context != nullptr) {
        // If this widget is active
        if (context->isActiveInputWidget(shared_from_this())) {
            // Get input key
            Char ch = Input::getPressedKey();
            // If no input char
            if (ch == Char::Err) {
                return;
            }
            // If char is not control key, but common symbol
            else if (ch == Char::Key::Tab ||
                ch == Char::Key::LineFeed ||
                ch > Char::Key::Delete)
            {
                // Insert string into content and move cursor to right
                m_content.insert(m_contentCursorPosition, ch);
                moveContentCursorPosition(1, direction::right);

                // Mark content as changed
                m_needUpdateDisplayString = true;
            }
            else if (ch == Char::Key::Backspace) {
                // If on the left of cursor position has character
                if (m_contentCursorPosition > 0) {
                    // Erase character on the left of cursor and move cursor to left
                    m_content.erase(m_contentCursorPosition - 1);
                    moveContentCursorPosition(1, direction::left);

                    // Mark content as changed
                    m_needUpdateDisplayString = true;
                }
            }
            else if (ch == Char::Key::Delete) {
                // If under of cursor has symbol
                if (m_contentCursorPosition < m_content.size()) {
                    m_content.erase(m_contentCursorPosition + 1);

                    // Mark content as changed
                    m_needUpdateDisplayString = true;
                }
            }
        }
    }
}
}
