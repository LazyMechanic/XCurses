#include <XCurses/Graphics/Border.h>

#include <algorithm>

#include <XCurses/System/Context.h>
#include <XCurses/Graphics/Container.h>

namespace xcur {
const BorderTraits BorderTraits::Blank = {
    Char(' '),
    Char(' '), 
    Char(' '),
    Char(' '),
    Char(' '), 
    Char(' '),
    Char(' '),
    Char(' ') };
const BorderTraits BorderTraits::Simple = {
    Char('|'),
    Char('|'),
    Char('-'),
    Char('-'),
    Char('+'),
    Char('+'),
    Char('+'),
    Char('+') };
const BorderTraits BorderTraits::Default = {
    Char(0x2502), 
    Char(0x2502), 
    Char(0x2500), 
    Char(0x2500), 
    Char(0x250c), 
    Char(0x2510), 
    Char(0x2514), 
    Char(0x2518) };
const BorderTraits BorderTraits::Wide = {
    Char(0x2551),
    Char(0x2551),
    Char(0x2550),
    Char(0x2550),
    Char(0x2554),
    Char(0x2557),
    Char(0x255a),
    Char(0x255d) };

Object::Ptr<Border> Border::create()
{
    return Border::create(BorderTraits::Blank);
}

Object::Ptr<Border> Border::create(const Char& ch)
{
    BorderTraits bt = {
        ch,
        ch,
        ch,
        ch,
        ch,
        ch,
        ch,
        ch
    };

    return Border::create(bt);
}

Object::Ptr<Border> Border::create(const BorderTraits& borderTraits)
{
    return std::shared_ptr<Border>(new Border(borderTraits));
}

void Border::draw() const
{
    auto context = getContext();
    if (context != nullptr) {
        // Draw verticals
        Vector2i topSidePosition = Vector2i::Zero;
        Vector2i bottomSidePosition = Vector2i(0, std::max<uint32_t>(static_cast<int32_t>(m_area.size.y) - 1, 0));

        for (uint32_t i = 1; i < m_area.size.x; ++i) {
            topSidePosition.x = i;
            bottomSidePosition.x = i;
            context->addToVirtualScreen(shared_from_this(), borderTraits.topSide, topSidePosition);
            context->addToVirtualScreen(shared_from_this(), borderTraits.bottomSide, bottomSidePosition);
        }

        // Draw horizontals
        Vector2i leftSidePosition = Vector2i::Zero;
        Vector2i rightSidePosition = Vector2i(std::max<uint32_t>(static_cast<int32_t>(m_area.size.x) - 1, 0), 0);

        for (uint32_t i = 1; i < m_area.size.y; ++i) {
            leftSidePosition.y = i;
            rightSidePosition.y = i;
            context->addToVirtualScreen(shared_from_this(), borderTraits.leftSide, leftSidePosition);
            context->addToVirtualScreen(shared_from_this(), borderTraits.rightSide, rightSidePosition);
        }

        // Draw corners
        Vector2i topLeftCornerPosition = Vector2i::Zero;
        Vector2i topRightCornerPosition = Vector2i(std::max<uint32_t>(static_cast<int32_t>(m_area.size.x) - 1, 0), 0);
        Vector2i bottomLeftCornerPosition = Vector2i(0, std::max<uint32_t>(static_cast<int32_t>(m_area.size.y) - 1, 0));
        Vector2i bottomRightCornerPosition = Vector2i(std::max<uint32_t>(static_cast<int32_t>(m_area.size.x) - 1, 0), std::max<uint32_t>(static_cast<int32_t>(m_area.size.y) - 1, 0));

        context->addToVirtualScreen(shared_from_this(), borderTraits.topLeftCorner, topLeftCornerPosition);
        context->addToVirtualScreen(shared_from_this(), borderTraits.topRightCorner, topRightCornerPosition);
        context->addToVirtualScreen(shared_from_this(), borderTraits.bottomLeftCorner, bottomLeftCornerPosition);
        context->addToVirtualScreen(shared_from_this(), borderTraits.bottomRightCorner, bottomRightCornerPosition);
    }
}

Border::Border(const BorderTraits& borderTraits) :
    borderTraits(borderTraits)
{
}
}
