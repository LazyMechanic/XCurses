#include <XCurses/Text/Char.h>

#include <cctype>

#include <XCurses/Text/Key.h>

namespace xcur {
Char Char::Err(0x0000ffff);

Char::Char() :
    symbol(0),
    attribute(Attribute::Normal),
    colorPairId(0)
{
}

Char::Char(uint8_t colorPairId, Attribute attr, uint16_t symbol) :
    symbol(symbol),
    attribute(attr),
    colorPairId(colorPairId)
{
}

Char::Char(uint32_t ch) :
    symbol(Char::getSymbol(ch)),
    attribute(Char::getAttribute(ch)),
    colorPairId(Char::getColorPairId(ch))
{
}

Char& Char::operator=(uint32_t right)
{
    symbol = Char::getSymbol(right);
    attribute = Char::getAttribute(right);
    colorPairId = Char::getColorPairId(right);
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

bool Char::isControl(const Char& ch)
{
    return std::iscntrl(ch.symbol) > 0 ||
        ch == Key::Insert ||
        ch == Key::Delete ||
        ch == Key::Down ||
        ch == Key::Up ||
        ch == Key::Left ||
        ch == Key::Right ||
        ch == Key::Home ||
        ch == Key::End ||
        ch == Key::PageUp ||
        ch == Key::PageDown ||
        ch == Key::F1 ||
        ch == Key::F2 ||
        ch == Key::F3 ||
        ch == Key::F4 ||
        ch == Key::F5 ||
        ch == Key::F6 ||
        ch == Key::F7 ||
        ch == Key::F8 ||
        ch == Key::F9 ||
        ch == Key::F10 ||
        ch == Key::F11 ||
        ch == Key::F12;
}

bool Char::isLineFeed(const Char& ch)
{
    return ch.symbol == '\f' ||
        ch.symbol == '\n' ||
        ch.symbol == '\r' ||
        ch.symbol == '\v';
}
}
