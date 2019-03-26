#include <XCurses/Graphics/InputTextArea.h>

#include <algorithm>

#include <XCurses/System/Input.h>
#include <XCurses/Graphics/Inputtable.h>
#include <XCurses/System/Context.h>

namespace xcur {
Object::Ptr<InputTextArea> InputTextArea::create(const Area& area)
{
    return std::shared_ptr<InputTextArea>(new InputTextArea(area));
}

InputTextArea::InputTextArea(const Area& area) :
    TextArea(area),
    Inputtable(m_area.size),
    m_contentCursorPosition(0)
{
}

void InputTextArea::update(float dt)
{
    updateContent();
    updateDisplayString();
    scrollToContentCursor();
    updateCursor();
    m_needUpdateDisplayString = false;
    m_needScrollToContentCursor = false;
}

void InputTextArea::setContentCursor(int32_t position)
{
    m_contentCursorPosition = std::max(0, std::min(position, static_cast<int32_t>(m_content.size()) - 1));
}

void InputTextArea::moveContentCursor(int32_t deltaPosition)
{
    setContentCursor(m_contentCursorPosition + deltaPosition);
}

size_t InputTextArea::getContentCursor() const
{
    return m_contentCursorPosition;
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

            // If input char is common symbol
            if (!Char::isControl(ch) ||
                ch == Key::Tab ||
                ch == Key::LineFeed) 
            {
                // Insert string into content and move cursor to right
                m_content.insert(m_contentCursorPosition, ch);
                moveContentCursor(1);

                // Mark text area for scroll to content cursor
                m_needScrollToContentCursor = true;
            }
            else {
                if (ch == Key::Backspace) {
                    // If on the left of cursor position has character
                    if (m_contentCursorPosition > 0) {
                        // Erase character on the left of cursor and move cursor to left
                        m_content.erase(m_contentCursorPosition - 1);
                        moveContentCursor(-1);

                        // Mark text area for scroll to content cursor
                        m_needScrollToContentCursor = true;
                    }
                }
                else if (ch == Key::Delete) {
                    // If under of cursor has symbol
                    if (m_contentCursorPosition < static_cast<int32_t>(m_content.size()) - 1) {
                        m_content.erase(m_contentCursorPosition);

                        // Mark text area for scroll to content cursor
                        m_needScrollToContentCursor = true;
                    }
                }
                else if (ch == Key::Left) {
                    moveContentCursor(-1);

                    // Mark text area for scroll to content cursor
                    m_needScrollToContentCursor = true;
                }
                else if (ch == Key::Right) {
                    moveContentCursor(1);

                    // Mark text area for scroll to content cursor
                    m_needScrollToContentCursor = true;
                }
                else if (ch == Key::Up) {
                    scroll(-1);
                }
                else if (ch == Key::Down) {
                    scroll(1);
                }
            }

            // Mark content as changed
            m_needUpdateDisplayString = true;
        }
    }
}

int32_t InputTextArea::getScrollDirectionByContentCursor()
{
    if (m_displayStrings.size() == m_area.size.y) {
        if (m_contentCursorPosition < m_displayStrings.begin()->beginPosition) {
            return -1;
        }
        
        if (m_contentCursorPosition >=
            (m_displayStrings.rbegin()->beginPosition + static_cast<int32_t>(m_displayStrings.rbegin()->data.size())))
        {
            return 1;
        }
    }

    return 0;
}

void InputTextArea::scrollToContentCursor()
{
    if (m_needScrollToContentCursor) {
        int32_t direction = 0;

        do {
            direction = getScrollDirectionByContentCursor();
            scroll(direction);
            updateDisplayString();
        } while (direction != 0);
    }
}

void InputTextArea::updateCursor()
{
    auto context = getContext();
    if (context != nullptr) {
        // If this widget is active
        if (context->isActiveInputWidget(shared_from_this())) {
            if (getScrollDirectionByContentCursor() != 0) {
                setScreenCursorState(CursorState::Hidden);
            }
            else {
                for (int32_t i = 0; i < m_displayStrings.size(); ++i) {
                    if (m_contentCursorPosition >= m_displayStrings[i].beginPosition &&
                        m_contentCursorPosition < m_displayStrings[i].beginPosition + m_displayStrings[i].data.size())
                    {
                        setScreenCursorState(CursorState::Normal);
                        setScreenCursorPosition(Vector2i(m_contentCursorPosition - m_displayStrings[i].beginPosition, i));
                        break;
                    }
                }
            }
        }
    }
}
}
