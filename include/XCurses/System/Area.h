#pragma once

#include <XCurses/System/Vector2.h>

namespace xcur {
class Area
{
public:
    /**
     * \brief Default Area constructor
     */
    Area();

    /**
     * \brief Area constructor. Construct it with specific position and size
     * \param position Area position
     * \param size Area size
     */
    Area(const Vector2i& position, const Vector2i& size);

    /**
     * \brief Area constructor. Construct it with specific position and size
     * \param positionX X component of position
     * \param positionY Y component of position
     * \param sizeX X component of size
     * \param sizeY Y component of size
     */
    Area(int32_t positionX, int32_t positionY, int32_t sizeX, int32_t sizeY);

    /**
     * \brief Default Area copy constructor
     */
    Area(const Area&) = default;

    /**
     * \brief Default Area move constructor
     */
    Area(Area&&) = default;

    /**
     * \brief Default Area copy assign operator
     */
    Area& operator =(const Area&) = default;

    /**
     * \brief Default Area move assign operator
     */
    Area& operator =(Area&&) = default;

    /**
     * \brief Area destructor
     */
    ~Area() = default;

    /**
     * \brief Check if Area contain this point
     * \param point Point relatively \a this area
     * \return True if Area contain point, false otherwise
     */
    bool contain(const Vector2i& point) const;

    /** \brief Check the intersection between two areas
    * \param area Area to test. His position is considered relatively
    * \a this area
    * \return True if areas overlap, false otherwise
     */
    bool intersects(const Area& area) const;

    /**
     * \brief Area position. Position is top-left corner of area
     */
    Vector2i position;

    /**
     * \brief Area size.
     * size.x - is length of upper and lower edges from left to right
     * size.y - is length of left and right edges from up to down
     */
    Vector2i size;
};
}