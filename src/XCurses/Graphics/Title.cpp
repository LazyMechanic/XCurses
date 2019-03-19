#include <XCurses/Graphics/Title.h>

#include <XCurses/System/Context.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
Object::Ptr<Title> Title::create(const Vector2u& position, const String& str)
{
    return std::shared_ptr<Title>(new Title(position, str));
}

Title::Title(const Vector2u& position, const String& str) :
    Widget(position, Vector2u::Zero),
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
            if (resultString.size() < (parent->getSize().x - m_position.x)) {
                context->addToVirtualScreen(shared_from_this(), resultString, m_position);
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
