#include <XCurses/Char.h>

namespace xcur {
Char Char::Err(0xffff);

Char::Char() :
    colorPairId(0),
    attr(Attribute::Normal),
    character(0)
{
}

Char::Char(uint16_t ch) :
    colorPairId(0),
    attr(Attribute::Normal),
    character(ch)
{
}

Char::Char(uint8_t _colorPairId, Attribute _attr, uint16_t ch) :
	colorPairId(_colorPairId),
	attr(_attr),
	character(ch)
{
}

Char& Char::operator=(uint16_t ch)
{
	character = ch;
	return *this;
}

Char::operator uint32_t() const
{
	return toCursesChar();
}

uint32_t Char::toCursesChar() const
{
	return static_cast<uint32_t>(colorPairId) << 24 |
		attr.toCursesAttr() |
		static_cast<uint32_t>(character);
}
}
