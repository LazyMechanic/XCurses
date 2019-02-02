#include <XCurses/Border.h>

namespace xcur {
const Border Border::Blank(' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
const Border Border::Simple('|', '|', '-', '-', '+', '+', '+', '+');
const Border Border::Default(0x2502, 0x2502, 0x2500, 0x2500, 0x250c, 0x2510, 0x2514, 0x2518);
const Border Border::Double(0x2551, 0x2551, 0x2550, 0x2550, 0x2554, 0x2557, 0x255a, 0x255d);

Border::Border() :
	leftSide(0x2502),
	rightSide(0x2502),
	topSide(0x2500),
	bottomSide(0x2500),
	topLeftCorner(0x250c),
	topRightCorner(0x2510),
	bottomLeftCorner(0x2514),
	bottomRightCorner(0x2518)
{
}

Border::Border(uint32_t ch) :
	leftSide(ch),
	rightSide(ch),
	topSide(ch),
	bottomSide(ch),
	topLeftCorner(ch),
	topRightCorner(ch),
	bottomLeftCorner(ch),
	bottomRightCorner(ch)
{
}

Border::Border(uint32_t _leftSide,
    uint32_t _rightSide,
    uint32_t _topSide,
    uint32_t _bottomSide,
    uint32_t _topLeftCorner,
    uint32_t _topRightCorner,
    uint32_t _bottomLeftCorner,
    uint32_t _bottomRightCorner
) :
	leftSide(_leftSide),
	rightSide(_rightSide),
	topSide(_topSide),
	bottomSide(_bottomSide),
	topLeftCorner(_topLeftCorner),
	topRightCorner(_topRightCorner),
	bottomLeftCorner(_bottomLeftCorner),
	bottomRightCorner(_bottomRightCorner)
{
}
}
