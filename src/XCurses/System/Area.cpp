#include <XCurses/System/Area.h>

namespace xcur {
Area::Area() :
    position(Vector2u::Zero),
    size(Vector2u::Zero)
{
}

Area::Area(const Vector2i& position, const Vector2i& size) :
    position(position),
    size(size)
{
}

bool Area::contain(const Vector2i& point) const
{
    return point.x >= 0 && // 0 is beginning position by x of this area
        point.y >= 0 && // 0 is beginning position by y of this area
        point.x <= size.x &&
        point.y <= size.y;
}

bool Area::intersects(const Area& area) const
{
    return area.position.x >= 0 && // 0 is beginning position by x of this area
        area.position.y >= 0 && // 0 is beginning position by y of this area
        size.x >= (area.position.x + area.size.x) &&
        size.y >= (area.position.y + area.size.y);
}
}
