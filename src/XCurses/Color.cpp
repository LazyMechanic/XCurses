#include <XCurses/Color.h>

namespace xcur {
const Color Color::Black(0, 0, 0);
const Color Color::White(255, 255, 255);
const Color Color::Red(255, 0, 0);
const Color Color::Green(0, 255, 0);
const Color Color::Blue(0, 0, 255);
const Color Color::Yellow(255, 255, 0);
const Color Color::Magenta(255, 0, 255);
const Color Color::Cyan(0, 255, 255);

Color::Color() :
    r(0),
    g(0),
    b(0)
{
}

Color::Color(uint8_t red, uint8_t green, uint8_t blue) :
	r(red),
	g(green),
	b(blue)
{
}

Color::Color(uint32_t color) :
	r((color & 0x00ff0000) >> 16),
	g((color & 0x0000ff00) >> 8),
	b((color & 0x000000ff) >> 0)
{
}

uint16_t Color::cursesRed()
{
	return static_cast<uint16_t>((r / 255.0f) * 1000.0f);
}

uint16_t Color::cursesGreen()
{
	return static_cast<uint16_t>((g / 255.0f) * 1000.0f);
}

uint16_t Color::cursesBlue()
{
	return static_cast<uint16_t>((b / 255.0f) * 1000.0f);
}
}
