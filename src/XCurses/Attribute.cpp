#include <XCurses/Attribute.h>

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

Attribute::Attribute(uint8_t attr) :
    value(attr)
{
}

Attribute& Attribute::operator=(uint8_t attr)
{
	value = attr;
	return *this;
}

uint32_t Attribute::toCursesAttr() const
{
	return static_cast<uint32_t>(value) << 16;
}

uint8_t Attribute::fromCursesAttr(uint32_t attr)
{
	return static_cast<uint8_t>(attr >> 16);
}

bool Attribute::has(const Attribute& attr) const
{
	return (value & attr.value) == attr.value;
}

bool operator==(const Attribute& left, const Attribute& right)
{
	return left.value == right.value;
}

bool operator==(const Attribute& left, uint8_t right)
{
	return left.value == right;
}

bool operator!=(const Attribute& left, const Attribute& right)
{
	return !(left == right);
}

bool operator!=(const Attribute& left, uint8_t right)
{
	return !(left == right);
}

Attribute operator|(const Attribute& left, const Attribute& right)
{
	return Attribute(left.value | right.value);
}

Attribute operator|(const Attribute& left, uint8_t right)
{
	return Attribute(left.value | right);
}

Attribute operator&(const Attribute& left, const Attribute& right)
{
	return Attribute(left.value & right.value);
}

Attribute operator&(const Attribute& left, uint8_t right)
{
	return Attribute(left.value & right);
}

Attribute& operator|=(Attribute& left, const Attribute& right)
{
	return left = left | right;
}

Attribute& operator|=(Attribute& left, uint8_t right)
{
	return left = left | right;
}

Attribute& operator&=(Attribute& left, const Attribute& right)
{
	return left = left & right;
}

Attribute& operator&=(Attribute& left, uint8_t right)
{
	return left = left & right;
}
}
