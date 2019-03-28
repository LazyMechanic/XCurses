#include <XCurses/Graphics/Title.h>

#include <XCurses/System/Context.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
Object::Ptr<Title> Title::create()
{
    return Title::create(Vector2i::Zero, "");
}

Object::Ptr<Title> Title::create(const Vector2i& position, const String& str)
{
    return std::shared_ptr<Title>(new Title(position, str));
}

Title::Title() :
    Title(Vector2i::Zero, "")
{
}

Title::Title(const Vector2i& position, const String& str) :
    Widget(Area(position, Vector2i(static_cast<int32_t>(str.size()) + 2, 1))),
    m_string(str)
{
}

void Title::draw() const
{
    auto context = getContext();
    if (context != nullptr) {
        // TODO: add multi-line drawing and smart drawing of content, due to the width
        String resultString = ' ' + m_string + ' ';
        if (resultString.size() < m_area.size.x) {
            context->addToVirtualScreen(shared_from_this(), resultString, Vector2i::Zero);
        }
    }
}

void Title::onResize()
{
    setSize(Vector2i(static_cast<int32_t>(m_string.size()) + 2, 1));
}

void Title::setString(const String& str)
{
    m_string = str;
    setSize(Vector2i(static_cast<int32_t>(m_string.size()) + 2, 1));
}

String Title::getString() const
{
    return m_string;
}
}
