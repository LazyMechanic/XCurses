#pragma once

#include <XCurses/Text/String.h>
#include <XCurses/Graphics/Widget.h>
#include <XCurses/Graphics/HasWindow.h>

namespace xcur {
class Title : public Widget, public HasWindow
{
public:
    /**
     * \brief Create Title. Construct title with specific string
     * \param str String
     */
    static Object::Ptr<Title> create(const String& str = "");

    /**
     * \brief Title destructor
     */
    ~Title() = default;

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

    /**
     * \brief Draw title. Add character into window and add in front and back space characters
     */
    void draw() override;

private:
    /**
     * \brief Default Title constructor. Construct title with "-" string
     */
    Title();

    /**
     * \brief Title construct. Construct title with specific string
     * \param str String
     */
    Title(const String& str);

    /**
     * \brief Title string
     */
    String m_string;
};
}