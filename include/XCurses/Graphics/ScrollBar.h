#pragma once

#include <XCurses/Graphics/Widget.h>

namespace xcur {
class ScrollBar : public Widget
{
public:
    /**
     * \brief Create ScrollBar
     * \return Smart ptr to ScrollBar
     */
    static Object::Ptr<ScrollBar> create();

    /**
     * \brief ScrollBar destructor
     */
    ~ScrollBar() = default;

    /**
     * \brief Call for update object state
     * \param dt Delta time
     */
    void update(float dt) override;

    /**
     * \brief Call function for draw the object
     */
    void draw() const override;

    /**
     * \brief Set max value
     * \param value New max value
     */
    void setMaxValue(uint32_t value);

    /**
     * \brief Set current value
     * \param value New current value
     */
    void setCurrentValue(uint32_t value);

protected:
    /**
     * \brief Default ScrollBar constructor
     */
    ScrollBar();

    /**
     * \brief Max value
     */
    uint32_t m_maxValue;

    /**
     * \brief Current value
     */
    uint32_t m_currentValue;
};
}