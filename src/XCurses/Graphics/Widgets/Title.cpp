#include <XCurses/Graphics/Widgets/Title.h>

namespace xcur {
Title::Title() :
    m_string("-")
{
}

Title::Title(const String& str) :
    m_string(str)
{
}

Title& Title::operator=(const String& str)
{
	m_string = str;
	return *this;
}

Title& Title::operator=(String&& str)
{
	m_string = str;
	return *this;
}

void Title::setString(const String& str)
{
	m_string = str;
}

String Title::getString() const
{
	return m_string;
}

void Title::draw()
{
    const auto window = getWindow();
    if (window != nullptr) {
		Vector2u position(1, 0);
		window->addChar(' ', position);
		position.x++;
        for (const auto& ch : m_string) {
			window->addChar(ch, position);
			position.x++;
        }
		window->addChar(' ', position);
    }
}
}
