#include <XCurses/Graphics/TextArea.h>

#include <algorithm>

#include <XCurses/System/Input.h>
#include <XCurses/System/Context.h>

namespace xcur {
Object::Ptr<TextArea> TextArea::create(const Area& area)
{
    return std::shared_ptr<TextArea>(new TextArea(area));
}

TextArea::TextArea(const Area& area) :
    Widget(area),
    m_contentCursorPosition(0),
    m_currentScrollOffset(0),
    m_maxScrollOffset(0),
    m_needUpdateDisplayString(true),
    m_isScrollEnable(true)
{
}

void TextArea::update(float dt)
{
    updateDisplayString();
    m_needUpdateDisplayString = false;
}

void TextArea::draw() const
{
    auto context = getContext();
    if (context != nullptr) {
        Vector2i position = Vector2i::Zero;
        size_t i = 0;
        for (; (position.y < m_area.size.y) && (i < m_displayString.size()); ++position.y) {
            for (position.x = 0; (position.x < m_area.size.x) && (i < m_displayString.size()); ++position.x) {
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
    m_needUpdateDisplayString = true;
    computeMaxScrollOffset();
}

String TextArea::getContent() const
{
    return m_content;
}

void TextArea::setSize(const Vector2i& size)
{
    Widget::setSize(size);
    m_needUpdateDisplayString = true;
}

size_t TextArea::getMaxScrollOffset() const
{
    return m_maxScrollOffset;
}

size_t TextArea::getCurrentScrollOffset() const
{
    return m_currentScrollOffset;
}

void TextArea::setScrollMode(bool state)
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
    m_currentScrollOffset = 0;
    m_isScrollEnable = false;
}

bool TextArea::isScrollEnable() const
{
    return m_isScrollEnable;
}

void TextArea::scroll(size_t deltaScrollOffset, direction::Up)
{
    if (m_isScrollEnable) {
        if (m_currentScrollOffset > deltaScrollOffset) {
            m_currentScrollOffset -= deltaScrollOffset;
        }
        else {
            m_currentScrollOffset = 0;
        }
        m_needUpdateDisplayString = true;
    }
}

void TextArea::scroll(size_t deltaScrollOffset, direction::Down)
{
    if (m_isScrollEnable) {
        m_currentScrollOffset = std::min(m_currentScrollOffset + deltaScrollOffset, m_maxScrollOffset);
        m_needUpdateDisplayString = true;
    }
}

void TextArea::setScroll(size_t scrollOffset)
{
    if (m_isScrollEnable) {
        m_currentScrollOffset = std::min(scrollOffset, m_maxScrollOffset);
        m_needUpdateDisplayString = true;
    }
}

void TextArea::updateDisplayString()
{
    auto context = getContext();
    if (context != nullptr) {
        // If Content changed with input or other ways
        if (m_needUpdateDisplayString) {
            computeMaxScrollOffset();

            size_t displayStringCursorBegin = 0;

            for (size_t scrollOffset = 0; scrollOffset <= m_currentScrollOffset; ++scrollOffset) {
                // Scroll only 1 row
                if (scrollOffset > 0) {
                    // Pass through content from display begin position
                    for (size_t i = displayStringCursorBegin + 1; i < m_content.size(); ++i) {
                        Char ch = m_content[i];
                        if (i % m_area.size.x == 0) {
                            displayStringCursorBegin = i;
                            break;
                        }
                        if (ch == Char::Key::LineFeed) {
                            displayStringCursorBegin = i + 1;
                            break;
                        }
                    }
                }
            }

            const size_t maxTextAreaFilling = m_area.size.x * m_area.size.y;
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
                    currentTextAreaFilling += (m_area.size.x - contentIndex % m_area.size.x) - 1;
                }
            }

            const size_t displayStringLength = contentIndex - displayStringCursorBegin;
            m_displayString = m_content.substring(displayStringCursorBegin, displayStringLength);
        }
    }
}

void TextArea::computeMaxScrollOffset()
{
    m_maxScrollOffset = 0;
    size_t chCount = 0;
    for (size_t i = 0; i < m_content.size(); ++i) {
        ++chCount;
        if (m_content[i] == Char::Key::LineFeed ||
            chCount % m_area.size.x == 0 ||
            (i + 1) == m_content.size()) {
            chCount = 0;
            ++m_maxScrollOffset;
        }
    }
    
    if (m_maxScrollOffset > 2) {
        m_maxScrollOffset -= 3;
    }

    m_currentScrollOffset = std::min(m_currentScrollOffset, m_maxScrollOffset);
}
}
