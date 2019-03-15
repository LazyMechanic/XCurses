#pragma once

#include <list>
#include <memory>

#include <XCurses/System/Vector2.h>
#include <XCurses/Graphics/Border.h>
#include <XCurses/System/Inputtable.h>
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
    void draw() const override final;

    /**
     * \brief Resize window
     * \param size New size
     */
    void resize(const Vector2u& size);

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
