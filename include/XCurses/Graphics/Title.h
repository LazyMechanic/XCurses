#pragma once

#include <XCurses/Text/String.h>
#include <XCurses/Graphics/Widget.h>

namespace xcur {
class Window;

class Title : public Widget
{
public:
    /**
     * \brief Create Title. Construct title with empty string and
     * zero position
     * \return Smart ptr to Title
     */
    static Object::Ptr<Title> create();

    /**
     * \brief Create Title. Construct title with specific string and position
     * \param position Title position
     * \param str String
     * \return Smart ptr to Title
     */
    static Object::Ptr<Title> create(const Vector2i& position, const String& str = "");

    /**
     * \brief Title destructor
     */
    ~Title() = default;

    /**
     * \brief Draw title. Add character into window and add in front and back space characters
     */
    void draw() const override;

    /**
     * \brief Automatically call this function after setSize()
     */
    void onResize() override;

    /**
     * \brief Set title string
     * \param str String
     */
    void setString(const String& str);

    /**
     * \brief Get title string
     * \return String
     */
    String getString() const;

private:
    /**
     * \brief Default Title constructor. Construct title with empty string and
     * zero position
     */
    Title();

    /**
     * \brief Title constructor. Construct title with specific string and position
     * \param position Title position
     * \param str String
     */
    Title(const Vector2i& position, const String& str);

    /**
     * \brief Title string
     */
    String m_string;
};
}