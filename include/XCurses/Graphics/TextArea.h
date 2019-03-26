#pragma once

#include <vector>

#include <XCurses/Text/String.h>

#include <XCurses/System/Vector2.h>

#include <XCurses/Graphics/Widget.h>

namespace xcur {
struct DisplayString {
    int32_t beginPosition = { 0 };
    String data = { };
};

class TextArea :
    public Widget
{
public:
    /**
     * \brief Create TextArea with specific position and size
     * \param area TextArea area
     * \return Smart ptr to TextArea
     */
    static Object::Ptr<TextArea> create(const Area& area);

    /**
     * \brief TextArea destructor
     */
    virtual ~TextArea() = default;

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
     * \brief Set content string. Content cursor position set to end 
     * \param str String
     */
    void setContent(const String& str);

    /**
     * \brief Get content string
     * \return Content
     */
    String getContent() const;

    /**
     * \brief Set widget size
     * \param size New size
     */
    void setSize(const Vector2i& size) override;

    /**
     * \brief Get max scroll offset
     * \return Max scroll offset
     */
    int32_t getMaxScrollOffset() const;

    /**
     * \brief Get current scroll offset
     * \return Current scroll offset
     */
    int32_t getCurrentScrollOffset() const;

    /**
     * \brief Scroll text area to up or down.
     * Equal setScroll(getCurrentScrollOffset() + deltaScrollOffset).
     * 
     * Result scroll offset that less then 0 are clamped to 0 offset.
     * Result scroll offset that more then max scroll offset are clamped to max scroll offset
     * \param deltaScrollOffset Delta scroll offset. Negative offset use for scroll up, positive
     * offset use for scroll down
     */
    void scroll(int32_t deltaScrollOffset);

    /**
     * \brief Set scroll offset relatively first row.
     * Result scroll offset that less then 0 are clamped to 0 offset.
     * Result scroll offset that more then max scroll offset are clamped to max scroll offset
     * \param scrollOffset Scroll offset
     */
    void setScroll(int32_t scrollOffset);

protected:
    /**
     * \brief TextArea constructor. Construct TextArea with specific position and size
     * \param area TextArea area
     * \return Smart ptr to TextArea
     */
    TextArea(const Area& area);

    /**
     * \brief Update display string if content has changed
     */
    void updateDisplayString();

    /**
     * \brief Compute max scroll offset 
     */
    void computeMaxScrollOffset();

    /**
     * \brief Get 
     * \param contentIndex 
     * \return Index of display string which contain character from content by index contentIndex,
     * "-1" if none contain character
     */
    int32_t getDisplayStringIndex(size_t contentIndex);

    /**
     * \brief Text area data
     */
    String m_content;

    /**
     * \brief Display current scroll offset
     */
    int32_t m_currentScrollOffset;

    /**
     * \brief Max display current scroll offset
     */
    int32_t m_maxScrollOffset;

    /**
     * \brief Whether the content has changed or scrolled
     */
    bool m_needUpdateDisplayString;

    /**
     * \brief Whether the text area can scroll
     */
    bool m_isScrollEnable;

    /**
     * \brief Array of strings for display
     */
    std::vector<DisplayString> m_displayStrings;
};
}