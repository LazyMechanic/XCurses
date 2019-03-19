#pragma once

#include <XCurses/Text/String.h>

#include <XCurses/System/Vector2.h>

#include <XCurses/Graphics/Inputtable.h>

namespace xcur {
class Form : public Inputtable
{
public:
    /**
     * \brief Tag for move to right direction
     */
    static struct LeftDirection {} leftDirection;

    /**
     * \brief Tag for move to  left direction
     */
    static struct RightDirection {} rightDirection;

    /**
     * \brief Create Form with specific position and size
     * \param position Form position
     * \param size Form size
     * \return Smart ptr to Form
     */
    static Object::Ptr<Form> create(const Vector2u& position, const Vector2u& size);

    /**
     * \brief Form destructor
     */
    virtual ~Form() = default;

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
    void moveContentCursorPosition(size_t deltaPosition, LeftDirection);

    /**
     * \brief Move content cursor to deltaPosition to right relative to the current position.
     * Result position that less then 0 are clamped to begin of content.
     * \param deltaPosition Delta position
     */
    void moveContentCursorPosition(size_t deltaPosition, RightDirection);

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

protected:
    /**
     * \brief Form constructor. Construct Form with specific position and size
     * \param position Form position
     * \param size Form size
     * \return Smart ptr to Form
     */
    Form(const Vector2u& position, const Vector2u& size);

    /**
     * \brief Position for next character
     */
    size_t m_contentCursorPosition;

    /**
     * \brief Form data
     */
    String m_content;
};
}