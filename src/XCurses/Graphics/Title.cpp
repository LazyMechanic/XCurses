#include <XCurses/Graphics/Title.h>

#include <XCurses/System/Context.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
Object::Ptr<Title> Title::create(const Vector2i& position, const String& str)
{
    return std::shared_ptr<Title>(new Title(position, str));
}

Title::Title(const Vector2i& position, const String& str) :
    Widget(Area(position, Vector2i(str.size(), 1))),
    m_string(str)
{
}
void Title::draw() const
{
    auto context = getContext();
    if (context != nullptr) {
        auto parent = getParent();
        if (parent != nullptr) {
            String resultString = ' ' + m_string + ' ';
            if (resultString.size() < (parent->getSize().x - m_area.position.x)) {
                context->addToVirtualScreen(shared_from_this(), resultString, m_area.position);
            }
        }
    }
}

void Title::setString(const String& str)
{
    m_string = str;
}

String Title::getString() const
{
    return m_string;
}
}
