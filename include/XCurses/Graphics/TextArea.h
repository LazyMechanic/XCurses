#pragma once

#include <XCurses/Text/String.h>

#include <XCurses/System/Vector2.h>
#include <XCurses/System/Direction.h>

#include <XCurses/Graphics/Widget.h>

namespace xcur {
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
     * \brief Set content cursor position.
     * Position that exceed content size are clamped to end of content.
     * \param position Content cursor position
     */
    void setContentCursorPosition(size_t position);

    /**
     * \brief Move content cursor to deltaPosition to left relative to the current position.
     * Result position that exceed content size are clamped to end of content.
     * \param deltaPosition Delta position
     */
    void moveContentCursorPosition(size_t deltaPosition, direction::Left);

    /**
     * \brief Move content cursor to deltaPosition to right relative to the current position.
     * Result position that less then 0 are clamped to begin of content.
     * \param deltaPosition Delta position
     */
    void moveContentCursorPosition(size_t deltaPosition, direction::Right);

    /**
     * \brief Get content cursor position
     * \return Content cursor position
     */
    size_t getContentCursorPosition() const;

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
    size_t getMaxScrollOffset() const;

    /**
     * \brief Get current scroll offset
     * \return Current scroll offset
     */
    size_t getCurrentScrollOffset() const;

    /**
     * \brief Set scroll mode
     * \param state Scroll mode state. 
     * True equal enableScroll(), false equal disableScroll()
     */
    void setScrollMode(bool state);

    /**
     * \brief Enable scroll mode
     */
    void enableScroll();

    /**
     * \brief Disable scroll mode. Scroll offset change to 0. Content will changing, 
     * but display string do not. This meaning that content always display with 0 scroll offset
     */
    void disableScroll();

    /**
     * \brief Check if scroll enable
     * \return True if scroll enable, false otherwise
     */
    bool isScrollEnable() const;

    /**
     * \brief Scroll text area to up
     * Result scroll offset that less then 0 are clamped to 0 offset
     * \param deltaScrollOffset Delta scroll offset
     */
    void scroll(size_t deltaScrollOffset, direction::Up);

    /**
     * \brief Scroll text area to down
     * Result scroll offset that more then max scroll offset are clamped to max scroll offset
     * \param deltaScrollOffset Delta scroll offset
     */
    void scroll(size_t deltaScrollOffset, direction::Down);

    /**
     * \brief Set scroll offset relatively first row.
     * If \a scrollOffset that more then max scroll offset are clamped to max scroll offset
     * \param scrollOffset Scroll offset
     */
    void setScroll(size_t scrollOffset);

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
     * \brief Position for next character
     */
    size_t m_contentCursorPosition;

    /**
     * \brief Text area data
     */
    String m_content;

    /**
     * \brief Display string
     */
    String m_displayString;

    /**
     * \brief Display current scroll offset
     */
    size_t m_currentScrollOffset;

    /**
     * \brief Max display current scroll offset
     */
    size_t m_maxScrollOffset;

    /**
     * \brief Whether the content has changed or scrolled
     */
    bool m_needUpdateDisplayString;

    /**
     * \brief Whether the text area can scroll
     */
    bool m_isScrollEnable;
};
}