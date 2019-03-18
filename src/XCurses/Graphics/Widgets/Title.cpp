#include <XCurses/Graphics/Widgets/Title.h>

#include <XCurses/Graphics/Context.h>

namespace xcur {
Object::Ptr<Title> Title::create(const String& str)
{
    return std::shared_ptr<Title>(new Title(str));
}

Title::Title(const String& str) :
    Widget(Vector2u(0, 2)),
    m_string(str)
{
}

void Title::setString(const String& str)
{
    m_string = str;
}

String Title::getString() const
{
    return m_string;
}

void Title::draw() const
{
    auto context = getContext();
    if (context != nullptr) {
        context->addToVirtualScreen(shared_from_this(), ' ', m_position);
    }
}
}
