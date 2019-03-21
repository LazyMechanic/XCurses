#pragma once

#include <XCurses/Text/Char.h>
#include <XCurses/Text/String.h>
#include <XCurses/System/Object.h>
#include <XCurses/System/Vector2.h>
#include <XCurses/Graphics/Widget.h>
#include <XCurses/System/Drawable.h>
#include <XCurses/System/Behaviour.h>
#include <XCurses/Graphics/Inputtable.h>

struct _win;

namespace xcur { 
class VirtualScreen :
    public Object,
    public Drawable,
    public Behaviour
{
public:
    /**
     * \brief Create VirtualScreen
     * \return Smart ptr to VirtualScreen
     */
    static Object::Ptr<VirtualScreen> create();

    /**
     * \brief VirtualScreen destructor
     */
    ~VirtualScreen() = default;

    /**
     * \brief Call for update object state
     * \param dt Delta time
     */
    void update(float dt) override;

    /**
     * \brief Call for draw object
     */
    void draw() const override;

    /**
     * \brief Add character in virtual screen. If position more than screen size then
     * do nothing
     * \param ch Character
     * \param position Position
     */
    void addChar(const Char& ch, const Vector2u& position);

    /**
     * \brief Add string in virtual screen. If position more than screen size then
     * do nothing, also add only string partial that can fit in the row at position
     * \param str String
     * \param position Position
     */
    void addString(const String& str, const Vector2u& position);

    /**
     * \brief Set active inputtable widget
     * \tparam Type Widget type
     * \param inputWidget Widget which need set active. If it is nullptr)
     * then off cursor
     */
    template <
        class Type,
        class = typename std::enable_if<
            std::is_base_of<Inputtable, Type>::value&&
            std::is_base_of<Widget, Type>::value>::type>
    void setActiveInputWidget(Object::Ptr<Type> inputWidget);

    /**
     * \brief Get active inputtable widget
     * \return Smart ptr to active input widget
     */
    Object::Ptr<Widget> getActiveInputWidget() const;

    /**
     * \brief Check if inputWidget is active
     * \return True if inputWidget is active, false otherwise
     */
    bool isActiveInputWidget(Object::Ptr<Widget> inputWidget) const;

    /**
     * \brief Clear screen
     */
    void clear() const;

private:
    /**
     * \brief Default VirtualScreen constructor
     */
    VirtualScreen() = default;

    /**
     * \brief Active input widget
     */
    Object::WeakPtr<Widget> m_activeInputWidget;
};

template <class Type, class>
void VirtualScreen::setActiveInputWidget(Object::Ptr<Type> inputWidget)
{
    m_activeInputWidget = inputWidget;
}
}
