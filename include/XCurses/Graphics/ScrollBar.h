#pragma once

#include <XCurses/Text/Char.h>

#include <XCurses/Graphics/Widget.h>

namespace xcur {
class ScrollBar : public Widget
{
public:
    /**
     * \brief Create ScrollBar
     * \param area ScrollBar area
     * \return Smart ptr to ScrollBar
     */
    static Object::Ptr<ScrollBar> create(const Area& area);

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

    /**
     * \brief Set background character
     * \param ch New background character
     */
    void setBackgroundChar(const Char& ch);

    /**
     * \brief Get background character
     * \return Background character
     */
    Char getBackgroundChar() const;

    /**
     * \brief Set bar character
     * \param ch New bar character
     */
    void setBarChar(const Char& ch);

    /**
     * \brief Get bar character
     * \return Bar character
     */
    Char getBarChar() const;

protected:
    /**
     * \brief Default ScrollBar constructor
     * \param area ScrollBar area
     */
    ScrollBar(const Area& area);

    /**
     * \brief Max value
     */
    uint32_t m_maxValue;

    /**
     * \brief Current value
     */
    uint32_t m_currentValue;

    /**
     * \brief Bar character
     */
    Char m_barChar;

    /**
     * \brief Background character
     */
    Char m_backgroundChar;
};
}