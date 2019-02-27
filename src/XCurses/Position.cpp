#include <XCurses/Position.h>

namespace xcur {
Position::Position() :
    x(0),
    y(0)
{
}

Position::Position(uint32_t x, uint32_t y) :
    x(x),
    y(y)
{
}

bool operator==(const Position& left, const Position& right)
{
    return (left.x == right.x) && (left.y == right.y);
}

bool operator!=(const Position& left, const Position& right)
{
    return !(left == right);
}

Position operator+(const Position& left, const Position& right)
{
    return Position(left.x + right.x, left.y + right.y);
}

Position operator-(const Position& left, const Position& right)
{
    return Position(left.x - right.x, left.y - right.y);
}

Position& operator+=(Position& left, const Position& right)
{
    return left = left + right;
}

Position& operator-=(Position& left, const Position& right)
{
    return left = left - right;
}
}
