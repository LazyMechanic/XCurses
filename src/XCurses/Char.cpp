#include <XCurses/Char.h>

namespace xcur {
Char::Char() :
    colorPairId(0),
    attr(Attribute::Normal),
    character(0)
{
}

Char::Char(uint16_t ch) :
    colorPairId(0),
    attr(0),
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

inline uint32_t Char::toCursesChar() const
{
	return static_cast<uint32_t>(colorPairId) << 24 |
		attr.toCursesAttr() |
		static_cast<uint32_t>(character);
}

Status Char::setForeground(const Color& foreground)
{
    
}
}
