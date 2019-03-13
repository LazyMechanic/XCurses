#include <XCurses/Graphics/Color.h>

#include <algorithm>

namespace xcur {
const Color Color::Black        (0,      0,      0);
const Color Color::Red          (255,    0,      0);
const Color Color::Green        (0,      255,    0);
const Color Color::Blue         (0,      0,      255);
const Color Color::Yellow       (255,    255,    0);
const Color Color::Magenta      (255,    0,      255);
const Color Color::Cyan         (0,      255,    255);
const Color Color::White        (255,    255,    255);

const Color Color::DarkGray     (128,   128,    128);
const Color Color::DarkRed      (128,   0,      0);
const Color Color::DarkGreen    (0,     128,    0);
const Color Color::DarkBlue     (0,     0,      128);
const Color Color::DarkYellow   (128,   128,    0);
const Color Color::DarkMagenta  (128,   0,      128);
const Color Color::DarkCyan     (0,     128,    128);
const Color Color::Gray         (192,   192,    192);

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

bool Color::operator==(const Color& right) const
{
    return (this->r == right.r) &&
        (this->g == right.g) &&
        (this->b == right.b);
}

bool Color::operator!=(const Color& right) const
{
    return !(*this == right);
}

Color Color::operator+(const Color& right) const
{
    return Color(
        static_cast<uint8_t>(std::min(static_cast<int>(this->r) + right.r, 255)),
        static_cast<uint8_t>(std::min(static_cast<int>(this->g) + right.g, 255)),
        static_cast<uint8_t>(std::min(static_cast<int>(this->b) + right.b, 255))
    );
}

Color Color::operator-(const Color& right) const
{
    return Color(
        static_cast<uint8_t>(std::max(static_cast<int>(this->r) - right.r, 0)),
        static_cast<uint8_t>(std::max(static_cast<int>(this->g) - right.g, 0)),
        static_cast<uint8_t>(std::max(static_cast<int>(this->b) - right.b, 0))
    );
}

Color Color::operator*(const Color& right) const
{
    return Color(
        static_cast<uint8_t>(static_cast<int>(this->r) * right.r / 255),
        static_cast<uint8_t>(static_cast<int>(this->g) * right.g / 255),
        static_cast<uint8_t>(static_cast<int>(this->b) * right.b / 255)
    );
}

Color& Color::operator+=(const Color& right)
{
    return *this = *this + right;
}

Color& Color::operator-=(const Color& right)
{
    return *this = *this - right;
}

Color& Color::operator*=(const Color& right)
{
    return *this = *this * right;
}

uint16_t Color::cursesRed() const
{
    return static_cast<uint16_t>((r / 255.0f) * 1000.0f);
}

uint16_t Color::cursesGreen() const
{
    return static_cast<uint16_t>((g / 255.0f) * 1000.0f);
}

uint16_t Color::cursesBlue() const
{
    return static_cast<uint16_t>((b / 255.0f) * 1000.0f);
}
}
