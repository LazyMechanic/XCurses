#pragma once

#include <XCurses/Graphics/TextArea.h>
#include <XCurses/Graphics/Inputtable.h>

namespace xcur {
class InputTextArea :
    public TextArea,
    public Inputtable
{
public:
    /**
     * \brief Create InputTextArea with specific position and size
     * \param area InputTextArea area
     * \return Smart ptr to InputTextArea
     */
    static Object::Ptr<InputTextArea> create(const Area& area);

    /**
     * \brief InputTextArea destructor
     */
    virtual ~InputTextArea() = default;

    /**
     * \brief Call for update object state
     * \param dt Delta time
     */
    void update(float dt) override;

    /**
     * \brief Set content cursor position.
     * Position that exceed content size are clamped to end of content.
     * \param position Content cursor position
     */
    void setContentCursor(int32_t position);

    /**
     * \brief Move content cursor to deltaPosition to left or right relative to the current position.
     * Equal setContentCursor(getContentCursor() + deltaPosition).
     * 
     * Result position that exceed content size are clamped to end of content.
     * Result position that less then 0 are clamped to begin of content.
     * \param deltaPosition Delta position. Negative value use for move cursor to left, positive
     * value use for move cursor to right
     */
    void moveContentCursor(int32_t deltaPosition);

    /**
     * \brief Get content cursor position
     * \return Content cursor position
     */
    size_t getContentCursor() const;

protected:
    /**
     * \brief InputTextArea constructor. Construct it with specific position and size
     * \param area InputTextArea area
     */
    InputTextArea(const Area& area);

    /**
     * \brief Update content string
     */
    void updateContent();

    /**
     * \brief Checks whether to scroll the text area to the  content cursor
     * and in which direction
     * \return 1 if need to scroll to down, -1 if need to scroll to up, 0 if
     * display strings contain character by content cursor position
     */
    int32_t getScrollDirectionByContentCursor();

    /**
     * \brief Scroll text area to content cursor
     */
    void scrollToContentCursor();

    /**
     * \brief 
     */
    void updateCursor();

    /**
     * \brief Position for next character
     */
    int32_t m_contentCursorPosition;

    /**
     * \brief Whether the input text area need scroll to content cursor
     */
    bool m_needScrollToContentCursor;
};
}