#include <XCurses/Text/Char.h>

namespace xcur {
Char Char::Err(0x0000ffff);

Char::Char() :
    colorPairId(0),
    attribute(Attribute::Normal),
	symbol(0)
{
}

Char::Char(uint8_t colorPairId, Attribute attr, uint16_t symbol) :
    colorPairId(colorPairId),
    attribute(attr),
	symbol(symbol)
{
}

Char::Char(uint32_t ch) :
	colorPairId(Char::getColorPairId(ch)),
	attribute(Char::getAttribute(ch)),
	symbol(Char::getSymbol(ch))
{
}

Char& Char::operator=(uint32_t right)
{
	colorPairId = Char::getColorPairId(right);
	attribute = Char::getAttribute(right);
	symbol = Char::getSymbol(right);
    return *this;
}

bool Char::operator==(const Char& right) const
{
	return symbol == right.symbol;
}

bool Char::operator==(uint32_t right) const
{
	return symbol == Char::getSymbol(right);
}

bool Char::operator!=(const Char& right) const
{
	return !(*this == right);
}

bool Char::operator!=(uint32_t right) const
{
	return !(*this == right);
}

bool Char::operator>(const Char& right) const
{
	return symbol > right.symbol;
}

bool Char::operator>(uint32_t right) const
{
	return symbol > Char::getSymbol(right);
}

bool Char::operator<(const Char& right) const
{
	return symbol < right.symbol;
}

bool Char::operator<(uint32_t right) const
{
	return symbol < Char::getSymbol(right);
}

bool Char::operator>=(const Char& right) const
{
	return symbol >= right.symbol;
}

bool Char::operator>=(uint32_t right) const
{
	return symbol >= Char::getSymbol(right);
}

bool Char::operator<=(const Char& right) const
{
	return symbol <= right.symbol;
}

bool Char::operator<=(uint32_t right) const
{
	return symbol <= Char::getSymbol(right);
}

uint32_t Char::toCursesChar() const
{
    return static_cast<uint32_t>(
		(static_cast<uint32_t>(colorPairId) << 24) |
		(static_cast<uint32_t>(attribute.value << 16)) |
		(static_cast<uint32_t>(symbol << 0)));
}

char Char::toAnsiChar() const
{
	return static_cast<char>(symbol);
}

wchar_t Char::toWideChar() const
{
	return static_cast<wchar_t>(symbol);
}

uint8_t Char::getColorPairId(uint32_t ch)
{
	return static_cast<uint8_t>(ch >> 24);
}

Attribute Char::getAttribute(uint32_t ch)
{
	return Attribute(ch);
}

uint16_t Char::getSymbol(uint32_t ch)
{
	return static_cast<uint16_t>(ch >> 0);
}

bool Char::isFullEqual(const Char& left, const Char& right)
{
	return (left.colorPairId == right.colorPairId) &&
		(left.attribute == right.attribute) &&
		(left.symbol == right.symbol);
}
}
