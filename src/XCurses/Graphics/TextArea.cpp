#include <XCurses/Graphics/TextArea.h>

#include <algorithm>

#include <XCurses/System/Input.h>
#include <XCurses/System/Context.h>

namespace xcur {
Object::Ptr<TextArea> TextArea::create()
{
    return TextArea::create(Area(Vector2i::Zero, Vector2i::Zero));
}

Object::Ptr<TextArea> TextArea::create(const Area& area)
{
    return std::shared_ptr<TextArea>(new TextArea(area));
}

TextArea::TextArea() :
    TextArea(Area(Vector2i::Zero, Vector2i::Zero))
{
}

TextArea::TextArea(const Area& area) :
    Widget(area),
    m_content(' '),
    m_currentScrollOffset(0),
    m_maxScrollOffset(0),
    m_needUpdateDisplayString(true),
    m_isScrollEnable(true),
    m_displayStrings(area.size.y)
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
        Vector2i positionToDraw = Vector2i::Zero;

        for (auto& str : m_displayStrings) {
            positionToDraw.x = 0;
            for (auto& ch : str.data) {
                if (Char::isLineFeed(ch)) {
                    break;
                }

                context->addToVirtualScreen(shared_from_this(), ch, positionToDraw);
                ++positionToDraw.x;
            }
            ++positionToDraw.y;
        }
    }
}

void TextArea::setContent(const String& str)
{
    m_content = str;
    if (m_content.size() > 0 &&
        *m_content.rbegin() != ' ')
    {
        m_content += ' ';
    }

    m_needUpdateDisplayString = true;
    computeMaxScrollOffset();
}

String TextArea::getContent() const
{
    return m_content;
}

void TextArea::onResize()
{
    m_displayStrings.resize(m_area.size.y);
    m_needUpdateDisplayString = true;
}

int32_t TextArea::getMaxScrollOffset() const
{
    return m_maxScrollOffset;
}

int32_t TextArea::getCurrentScrollOffset() const
{
    return m_currentScrollOffset;
}

void TextArea::scroll(int32_t deltaScrollOffset)
{
    setScroll(m_currentScrollOffset + deltaScrollOffset);
}

void TextArea::setScroll(int32_t scrollOffset)
{
    // If new scroll offset equal current scroll offset then do nothing
    if (m_currentScrollOffset == scrollOffset) {
        return;
    }

    m_currentScrollOffset = std::max(0, std::min(scrollOffset, m_maxScrollOffset));
    m_needUpdateDisplayString = true;
}

void TextArea::updateDisplayString()
{
    auto context = getContext();
    if (context != nullptr) {
        // If Content changed with input or other ways
        if (m_needUpdateDisplayString) {
            computeMaxScrollOffset();

            // Begin index in content for display string
            int32_t contentStringIndexBegin = 0;

            // Scroll through the text area to the desired offset
            for (int32_t scrollOffset = 0;
                scrollOffset <= m_currentScrollOffset;
                ++scrollOffset)
            {
                // Increase contentStringIndexBegin to 1 row
                if (scrollOffset > 0 && m_displayStrings.size() > 1) {
                    contentStringIndexBegin = m_displayStrings[1].beginPosition;
                }

                // Pass through display strings
                for (size_t displayStringIndex = 0; 
                    displayStringIndex < m_displayStrings.size(); 
                    ++displayStringIndex)
                {
                    // If display string is not first in vector
                    if (displayStringIndex > 0) {
                        m_displayStrings[displayStringIndex].beginPosition = 
                            m_displayStrings[displayStringIndex - 1].beginPosition +
                            static_cast<int32_t>(m_displayStrings[displayStringIndex - 1].data.size());
                    }
                    else {
                        m_displayStrings[displayStringIndex].beginPosition = contentStringIndexBegin;
                    }

                    // Pass through content string
                    size_t contentStringIndex = contentStringIndexBegin;
                    for (; 
                        contentStringIndex < m_content.size() &&
                        ((contentStringIndex - contentStringIndexBegin + 1) % m_area.size.x != 0) &&
                        !Char::isLineFeed(m_content[contentStringIndex]);
                        ++contentStringIndex)
                    {
                    }

                    // Copy content substring to one of display strings
                    m_displayStrings[displayStringIndex].data =
                        m_content.substring(contentStringIndexBegin, contentStringIndex - contentStringIndexBegin + 1);

                    // Increase begin index
                    contentStringIndexBegin += static_cast<int32_t>(m_displayStrings[displayStringIndex].data.size());
                }
            }
        }
    }
}

void TextArea::computeMaxScrollOffset()
{
    if (m_area.size.x > 0 && m_area.size.y > 0) {
        m_maxScrollOffset = 0;
        size_t chCount = 0;
        for (size_t i = 0; i < m_content.size(); ++i) {
            ++chCount;
            if (m_content[i] == Key::LineFeed ||
                chCount % m_area.size.x == 0 ||
                (i + 1) == m_content.size())
            {
                chCount = 0;
                ++m_maxScrollOffset;
            }
        }

        // Set count of display strings less or equal than height of text area
        m_displayStrings.resize(std::min(m_maxScrollOffset, m_area.size.y));

        m_maxScrollOffset = std::max(m_maxScrollOffset - m_area.size.y, 0);

        m_currentScrollOffset = std::min(m_currentScrollOffset, m_maxScrollOffset);
    }
}

int32_t TextArea::getDisplayStringIndex(size_t contentIndex)
{
    for (int32_t index = 0; index < m_displayStrings.size(); ++index) {
        if (contentIndex >= m_displayStrings[index].beginPosition &&
            contentIndex < m_displayStrings[index].beginPosition + m_displayStrings[index].data.size())
        {
            return index;
        }
    }

    return -1;
}
}
