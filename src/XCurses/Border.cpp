#include <XCurses/Border.h>

namespace xcur {
const Border Border::Blank(Char(' '), Char(' '), Char(' '), Char(' '), Char(' '), Char(' '), Char(' '), Char(' '));
const Border Border::Simple(Char('|'), Char('|'), Char('-'), Char('-'), Char('+'), Char('+'), Char('+'), Char('+'));
const Border Border::Default(Char(0x2502), Char(0x2502), Char(0x2500), Char(0x2500), Char(0x250c), Char(0x2510), Char(0x2514), Char(0x2518));
const Border Border::Wide(Char(0x2551), Char(0x2551), Char(0x2550), Char(0x2550), Char(0x2554), Char(0x2557), Char(0x255a), Char(0x255d));

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
