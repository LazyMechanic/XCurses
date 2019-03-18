#pragma once

#include <memory>

#include <XCurses/Text/String.h>

#include <XCurses/System/Vector2.h>

#include <XCurses/Graphics/Border.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
/**
 * \brief The class controls the curses window and provides an interface to 
 * handle the curses window.
 */
class Window :
    public Container
{
public:
    /**
     * \brief Create Window with zero position and size
     */
    static Object::Ptr<Window> create();

    /**
     * \brief Create Window with default position and size
     */
    static Object::Ptr<Window> create(const Vector2u& position, const Vector2u& size);

    /**
     * \brief Create Window with default position and size and
     * set parent
     * \param position Position
     * \param parent Smart ptr to parent container
     */
    static Object::Ptr<Window> create(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent);

    /**
     * \brief Create Window with default position and size and
     * set context
     * \param position Position
     * \param context Smart ptr to context
     */
    static Object::Ptr<Window> create(const Vector2u& position, const Vector2u& size, Object::Ptr<Context> context);

    /**
     * \brief Create Window with default position and size and
     * set parent and context
     * \param position Position
     * \param parent Smart ptr to parent container
     * \param context Smart ptr to context
     */
    static Object::Ptr<Window> create(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent, Object::Ptr<Context> context);
    
    /**
     * \brief Window destructor
     */
    virtual ~Window() = default;

    /**
     * \brief Call function for draw the object
     */
    void draw() const override;

    /**
     * \brief Resize window
     * \param size New size
     */
    void resize(const Vector2u& size);

    /**
     * \brief Add char into window. If position more than window size then do nothing. 
     * Window size not include border
     * \param ch Character
     * \param position Position
     */
    void addChar(const Char& ch, const Vector2u& position) const;

    /**
     * \brief Add string into window. If position more than window size then do nothing.
     * Add string without line break.
     * For example: if you have string "abcdefghij" with availableArea = { 10 }, add this string 
     * into window with size = { 10, 10 } at position = { 5, 5 } then on row[5] will added only
     * "abcd" before end available area of the window. Window size not include border
     * \param str String
     * \param position Position
     */
    void addString(const String& str, const Vector2u& position) const;

    /**
     * \brief Get window width
     * \return Width
     */
    uint32_t getWidth() const;

    /**
     * \brief Get window height
     * \return Height
     */
    uint32_t getHeight() const;

    /**
     * \brief Get window size
     * \return Window size
     */
    Vector2u getSize() const;

    /**
     * \brief Get available area. It is not include border
     * \return Available rectangle
     */
    Vector2u getAvailableArea() const;

    /**
     * \brief Set background character
     * \param ch Character
     */
    void setBackground(const Char& ch);

    /**
     * \brief Get background char
     * \return Char
     */
    Char getBackground() const;

    /**
     * \brief Set new border
     * \param border Border
     */
    void setBorder(const Border& border);

    /**
     * \brief Get current border
     * \return Border
     */
    Border getBorder() const;

protected:
    /**
     * \brief Default Window constructor
     */
    Window();

    /**
     * \brief Window constructor. Construct it with default position and size
     */
    Window(const Vector2u& position, const Vector2u& size);

    /**
     * \brief Window constructor. Construct it with default position and size and
     * set parent
     * \param position Position
     * \param parent Smart ptr to parent container
     */
    Window(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent);

    /**
     * \brief Window constructor. Construct it with default position and size and
     * set context
     * \param position Position
     * \param context Smart ptr to context
     */
    Window(const Vector2u& position, const Vector2u& size, Object::Ptr<Context> context);

    /**
     * \brief Window constructor. Construct it with default position and size and
     * set parent and context
     * \param position Position
     * \param parent Smart ptr to parent container
     * \param context Smart ptr to context
     */
    Window(const Vector2u& position, const Vector2u& size, Object::Ptr<Container> parent, Object::Ptr<Context> context);

    /**
     * \brief Draw borders
     */
    void drawBorders() const;

    /**
     * \brief Window size
     */
    Vector2u m_size;

    /**
     * \brief Background char
     */
    Char m_backgroundChar;

    /**
     * \brief Border container
     */
    Border m_border;
};
}
