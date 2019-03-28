#pragma once

#include <XCurses/System/Area.h>

#include <XCurses/Graphics/Border.h>
#include <XCurses/Graphics/TextArea.h>
#include <XCurses/Graphics/ScrollBar.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
class TextBox : public Container
{
public:
    /**
     * \brief Create TextBox with zero position and size
     * \return Smart ptr to TextBox
     */
    static Object::Ptr<TextBox> create();

    /**
     * \brief Create TextBox with specific position and size
     * \param area TextBox area
     * \return Smart ptr to TextBox
     */
    static Object::Ptr<TextBox> create(const Area& area);

    /**
     * \brief Call for update object state
     * \param dt Delta time
     */
    void update(float dt) override;

    /**
     * \brief Automatically call this function after setSize()
     */
    void onResize() override;

    /**
     * \brief Set text area. Size of it will resize to text box size policy
     * \param textArea Smart ptr to new text area
     */
    void setTextArea(Object::Ptr<TextArea> textArea);

    /**
     * \brief Get text area
     * \return Smart ptr to text area
     */
    Object::Ptr<TextArea> getTextArea() const;

    /**
     * \brief Set scroll bar. Size of it will resize to text box size policy
     * \param scrollBar Smart ptr to new scroll bar
     */
    void setScrollBar(Object::Ptr<ScrollBar> scrollBar);

    /**
     * \brief Get scroll bar
     * \return Smart ptr to scroll bar
     */
    Object::Ptr<ScrollBar> getScrollBar() const;

    /**
     * \brief Set border. Size of it will resize to text box size policy
     * \param border Smart ptr to new border
     */
    void setBorder(Object::Ptr<Border> border);

    /**
     * \brief Get border
     * \return Smart ptr to border
     */
    Object::Ptr<Border> getBorder() const;

protected:
    /**
     * \brief TextBox constructor. Construct it with zero position and size
     */
    TextBox();

    /**
     * \brief TextBox constructor. Construct it with specific position and size
     * \param area TextBox area
     */
    explicit TextBox(const Area& area);

    /**
     * \brief Reset area text area to text box area
     */
    void updateAreaOfTextArea();

    /**
     * \brief Reset area scroll bar to text box area
     */
    void updateAreaOfScrollBar();

    /**
     * \brief Reset area border to text box area
     */
    void updateAreaOfBorder();

    /**
     * \brief Text area
     */
    Object::Ptr<TextArea> m_textArea;

    /**
     * \brief Scroll bar
     */
    Object::Ptr<ScrollBar> m_scrollBar;

    /**
     * \brief Border
     */
    Object::Ptr<Border> m_border;
};
}