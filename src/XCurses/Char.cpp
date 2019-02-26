#include <XCurses/Char.h>

namespace xcur {
Char Char::Err(0xffff);

Char::Char() :
	m_data(0x00000000)
{
}

Char::Char(uint16_t ch) :
	m_data(0x00000000)
{
	setColoPairId(0);
	setAttr(Attribute::Normal);
	setChar(ch);
}

Char::Char(uint8_t colorPairId, Attribute attr, uint16_t ch) :
    m_data(0x00000000)
{
	setColoPairId(colorPairId);
	setAttr(attr);
	setChar(ch);
}

Char& Char::operator=(uint16_t ch)
{
	setChar(ch);
	return *this;
}

void Char::setChar(uint16_t ch)
{
	m_data |= static_cast<uint32_t>(ch);
}

void Char::setAttr(const Attribute& attr)
{
	m_data |= attr.toCursesAttr();
}

void Char::setColoPairId(uint8_t id)
{
	m_data |= static_cast<uint32_t>(id) << 24;
}

uint16_t Char::getChar() const
{
	return static_cast<uint16_t>(m_data & 0x0000ffff);
}

Attribute Char::getAttr() const
{
	return Attribute(m_data & 0x00ff0000);
}

uint8_t Char::getColoPairId() const
{
	return static_cast<uint8_t>((m_data & 0xff000000) >> 24);
}

Char::operator uint32_t&()
{
	return toCursesChar();
}

uint32_t& Char::toCursesChar()
{
	return m_data;
}
}
