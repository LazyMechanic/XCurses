#include <XCurses/Attribute.h>

namespace xcur {
Attribute::Attribute() :
    value(0)
{
}

Attribute::Attribute(uint8_t attr) :
    value(attr)
{
}

Attribute::Attribute(uint32_t ch) :
    value(static_cast<uint8_t>(ch >> 16))
{
}

Attribute::operator uint32_t() const
{
	return static_cast<uint32_t>(value) << 16;
}

inline bool Attribute::has(const Attribute& attr) const
{
	return (value & attr.value) == attr.value;
}
}
