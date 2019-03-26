#include <XCurses/Graphics/ScrollBar.h>

namespace xcur {
Object::Ptr<ScrollBar> ScrollBar::create()
{
    return std::shared_ptr<ScrollBar>(new ScrollBar());
}

ScrollBar::ScrollBar() :
    m_maxValue(0),
    m_currentValue(0)
{
}

void ScrollBar::update(float dt)
{
}

void ScrollBar::draw() const
{
    for (int32_t column = 0; column < m_area.size.x; ++column) {
        for (uint32_t row = 0; row < m_area.size.y; ++row) {
            
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
}
