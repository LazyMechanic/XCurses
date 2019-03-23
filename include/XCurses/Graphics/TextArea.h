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
     * \brief Set scroll mode
     * \param state Scroll mode state. 
     * True equal enableScroll(), false equal disableScroll()
     */
    void setScroll(bool state);

    /**
     * \brief Enable scroll mode
     */
    void enableScroll();

    /**
     * \brief Disable scroll mode
     */
    void disableScroll();

    /**
     * \brief Check if scroll enable
     * \return True if scroll enable, false otherwise
     */
    bool isScrollEnable() const;

    /**
     * \brief 
     * \param deltaRowOffset 
     */
    void scroll(size_t deltaRowOffset, direction::Up);

    /**
     * \brief 
     * Result row offset that less then 0 are clamped to 0 offset
     * \param deltaRowOffset Delta row offset
     */
    void scroll(size_t deltaRowOffset, direction::Down);

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
     * \brief Compute max row offset 
     */
    void computeMaxRowOffset();

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
     * \brief Display row offset
     */
    size_t m_rowOffset;

    /**
     * \brief Max display row offset
     */
    size_t m_maxRowOffset;

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