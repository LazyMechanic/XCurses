#include <XCurses/Text/Attribute.h>

#include <PDCurses/curses.h>

namespace xcur {
const Attribute Attribute::Normal(A_NORMAL);      // Normal predefined attribute
const Attribute Attribute::AltCharset(A_ALTCHARSET);  // AltCharset predefined attribute
const Attribute Attribute::Right(A_RIGHT);       // Right predefined attribute
const Attribute Attribute::Left(A_LEFT);        // Left predefined attribute
const Attribute Attribute::Italic(A_ITALIC);      // Italic predefined attribute
const Attribute Attribute::Underline(A_UNDERLINE);   // Underline predefined attribute
const Attribute Attribute::Reverse(A_REVERSE);     // Reverse predefined attribute
const Attribute Attribute::Blink(A_BLINK);       // Blink predefined attribute
const Attribute Attribute::Bold(A_BOLD);        // Bold predefined attribute

Attribute::Attribute() :
    value(0)
{
}

Attribute::Attribute(uint32_t attr) :
    value(static_cast<uint8_t>(attr >> 16))
{
}

Attribute& Attribute::operator=(uint32_t attr)
{
    value = static_cast<uint8_t>(attr >> 16);
    return *this;
}

bool Attribute::operator==(const Attribute& right) const
{
    return this->value == right.value;
}

bool Attribute::operator==(uint32_t right) const
{
    return this->value == static_cast<uint8_t>(right >> 16);
}

bool Attribute::operator!=(const Attribute& right) const
{
    return !(*this == right);
}

bool Attribute::operator!=(uint32_t right) const
{
    return !(*this == right);
}

Attribute Attribute::operator|(const Attribute& right) const
{
    return Attribute(this->toCursesAttr() | right.toCursesAttr());
}

Attribute Attribute::operator|(uint32_t right) const
{
    return Attribute(this->toCursesAttr() | right);
}

Attribute Attribute::operator&(const Attribute& right) const
{
    return Attribute(this->toCursesAttr() & right.toCursesAttr());
}

Attribute Attribute::operator&(uint32_t right) const
{
    return Attribute(this->toCursesAttr() & right);
}

Attribute& Attribute::operator|=(const Attribute& right)
{
    return *this = *this | right;
}

Attribute& Attribute::operator|=(uint32_t right)
{
    return *this = *this | right;
}

Attribute& Attribute::operator&=(const Attribute& right)
{
    return *this = *this & right;
}

Attribute& Attribute::operator&=(uint32_t right)
{
    return *this = *this & right;
}

uint32_t Attribute::toCursesAttr() const
{
    return static_cast<uint32_t>(value) << 16;
}

bool Attribute::has(const Attribute& attr) const
{
    return (value & attr.value) == attr.value;
}
}
