#include <XCurses/Border.h>

namespace xcur {
const Border Border::Blank(' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
const Border Border::Simple('|', '|', '-', '-', '+', '+', '+', '+');
const Border Border::Default(0x2502, 0x2502, 0x2500, 0x2500, 0x250c, 0x2510, 0x2514, 0x2518);
const Border Border::Wide(0x2551, 0x2551, 0x2550, 0x2550, 0x2554, 0x2557, 0x255a, 0x255d);

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

Border::Border(const Char& ch) :
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

Border::Border(Char _leftSide,
    Char _rightSide,
    Char _topSide,
    Char _bottomSide,
    Char _topLeftCorner,
    Char _topRightCorner,
    Char _bottomLeftCorner,
    Char _bottomRightCorner) :
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
