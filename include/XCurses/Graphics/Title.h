#pragma once

#include <XCurses/Text/String.h>
#include <XCurses/Graphics/Widget.h>

namespace xcur {
class Window;

class Title : public Widget
{
public:
    /**
     * \brief Create Title. Construct title with specific string
     * \param position Title position
     * Do not change parent size
     * \param str String
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
     * \brief Title construct. Construct title with specific string
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