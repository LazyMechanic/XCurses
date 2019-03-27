#include <XCurses/Graphics/ScrollBar.h>

#include <cmath>
#include <algorithm>

#include <XCurses/System/Context.h>

namespace xcur {
Object::Ptr<ScrollBar> ScrollBar::create(const Area& area)
{
    return std::shared_ptr<ScrollBar>(new ScrollBar(area));
}

ScrollBar::ScrollBar(const Area& area) :
    Widget(area),
    m_maxValue(0),
    m_currentValue(0),
    m_barChar('X'),
    m_backgroundChar('.')
{
}

void ScrollBar::update(float dt)
{
}

void ScrollBar::draw() const
{
    auto context = getContext();
    if (context != nullptr) {
        // Draw scroll bar background
        for (Vector2i position = Vector2i::Zero; position.y < m_area.size.y; ++position.y) {
            for (position.x = 0; position.x < m_area.size.x; ++position.x) {
                context->addToVirtualScreen(shared_from_this(), m_backgroundChar, position);
            }
        }

        int32_t barSize = 0;
        int32_t barOffset = 0;
        if (m_maxValue != 0) {
            barSize = static_cast<int32_t>(std::floor(static_cast<float>(m_area.size.y) / (m_maxValue)));
            barOffset = static_cast<int32_t>(std::floor((static_cast<float>(m_currentValue) / (m_maxValue)) * (m_area.size.y - barSize)));
        }
        
        // Draw scroll bar
        for (Vector2i position = Vector2i(0, barOffset); position.y < (barOffset + barSize); ++position.y) {
            for (position.x = 0; position.x < m_area.size.x; ++position.x) {
                context->addToVirtualScreen(shared_from_this(), m_barChar, position);
            }
        }
    }
}

void ScrollBar::setMaxValue(uint32_t value)
{
    m_maxValue = value;
}

void ScrollBar::setCurrentValue(uint32_t value)
{
    m_currentValue = value;
}

void ScrollBar::setBackgroundChar(const Char& ch)
{
    m_backgroundChar = ch;
}

Char ScrollBar::getBackgroundChar() const
{
    return m_backgroundChar;
}

void ScrollBar::setBarChar(const Char& ch)
{
    m_barChar = ch;
}

Char ScrollBar::getBarChar() const
{
    return m_barChar;
}
}
