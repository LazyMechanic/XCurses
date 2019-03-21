#include <XCurses/Graphics/TextArea.h>

#include <algorithm>

#include <XCurses/System/Input.h>
#include <XCurses/System/Context.h>

namespace xcur {
Object::Ptr<TextArea> TextArea::create(const Vector2u& position, const Vector2u& size)
{
    return std::shared_ptr<TextArea>(new TextArea(position, size));
}

TextArea::TextArea(const Vector2u& position, const Vector2u& size) :
    Widget(position, size),
    m_contentCursorPosition(0),
    m_rowOffset(0),
    m_isContentChanged(true),
    m_isScrollEnable(true)
{
}

void TextArea::update(float dt)
{
    updateDisplayString();
    m_isContentChanged = false;
}

void TextArea::draw() const
{
    auto context = getContext();
    if (context != nullptr) {
        Vector2u position = Vector2u::Zero;
        size_t i = 0;
        for (; (position.y < m_size.y) && (i < m_displayString.size()); ++position.y) {
            for (position.x = 0; (position.x < m_size.x) && (i < m_displayString.size()); ++position.x) {
                // If character is line feed then go to next row
                if (m_displayString[i] == Char::Key::LineFeed) {
                    ++i;
                    break;
                }

                context->addToVirtualScreen(shared_from_this(), m_displayString[i], position);
                ++i;
            }
        }
    }
}

void TextArea::setContentCursorPosition(size_t position)
{
    m_contentCursorPosition = std::min(position, m_content.size());
}

void TextArea::moveContentCursorPosition(size_t deltaPosition, direction::Left)
{
    if (m_contentCursorPosition > deltaPosition) {
        m_contentCursorPosition -= deltaPosition;
    }
    else {
        m_contentCursorPosition = 0;
    }
}

void TextArea::moveContentCursorPosition(size_t deltaPosition, direction::Right)
{
    m_contentCursorPosition = std::min(m_contentCursorPosition + deltaPosition, m_content.size());
}

size_t TextArea::getContentCursorPosition() const
{
    return m_contentCursorPosition;
}

void TextArea::setContent(const String& str)
{
    m_content = str;
    m_contentCursorPosition = str.size();
    m_isContentChanged = true;
}

String TextArea::getContent() const
{
    return m_content;
}

void TextArea::setSize(const Vector2u& size)
{
    Widget::setSize(size);
    m_isContentChanged = true;
}

void TextArea::setScroll(bool state)
{
    if (state) {
        enableScroll();
    }
    else {
        disableScroll();
    }
}

void TextArea::enableScroll()
{
    m_isScrollEnable = true;
}

void TextArea::disableScroll()
{
    m_isScrollEnable = false;
}

bool TextArea::isScrollEnable() const
{
    return m_isScrollEnable;
}

void TextArea::updateDisplayString()
{
    auto context = getContext();
    if (context != nullptr) {
        // If Content changed with input or other ways
        if (m_isContentChanged) {

            size_t displayStringCursorBegin = 0;
            size_t displayStringLength = 0;
            size_t currentRowOffset = 0;

            const size_t maxTextAreaFilling = m_size.x * m_size.y;

            do {
                displayStringCursorBegin += displayStringLength;

                size_t currentTextAreaFilling = 0;
                size_t contentIndex = displayStringCursorBegin;
                for (;
                    (contentIndex < m_content.size()) &&
                    (currentTextAreaFilling < maxTextAreaFilling);
                    ++contentIndex, ++currentTextAreaFilling)
                {
                    // If meet line feed character then add to currentTextAreaFilling
                    // the difference between used row size and max row size.
                    // It is the unused row size including line feed character
                    if (m_content[contentIndex] == Char::Key::LineFeed) {
                        // Add "-1" because after "continue" currentFromFilling will increase again
                        currentTextAreaFilling += (m_size.x - contentIndex % m_size.x) - 1;
                        continue;
                    }
                }

                displayStringLength = contentIndex - displayStringCursorBegin;
                ++currentRowOffset;
            } while (currentRowOffset < m_rowOffset);

            m_displayString = m_content.substring(displayStringCursorBegin, displayStringLength);
        }
    }
}
}
