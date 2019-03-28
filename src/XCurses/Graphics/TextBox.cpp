#include <XCurses/Graphics/TextBox.h>

#include <algorithm>

namespace xcur {
Object::Ptr<TextBox> TextBox::create()
{
    return TextBox::create(Area(Vector2i::Zero, Vector2i::Zero));
}

Object::Ptr<TextBox> TextBox::create(const Area& area)
{
    std::shared_ptr<TextBox> result(new TextBox(area));
    result->setTextArea(result->m_textArea);
    result->setBorder(result->m_border);
    result->setScrollBar(result->m_scrollBar);
    return result;
}

void TextBox::update(float dt)
{
    if (m_textArea != nullptr &&
        m_scrollBar != nullptr)
    {
        m_scrollBar->setMaxValue(m_textArea->getMaxScrollOffset());
        m_scrollBar->setCurrentValue(m_textArea->getCurrentScrollOffset());
    }
}

TextBox::TextBox() :
    TextBox(Area(Vector2i::Zero, Vector2i::Zero))
{
}

TextBox::TextBox(const Area& area) :
    Container(area),
    m_textArea(TextArea::create()),
    m_scrollBar(ScrollBar::create()),
    m_border(Border::create(BorderTraits::Default))
{
}

void TextBox::onResize()
{
    updateAreaOfTextArea();
    updateAreaOfScrollBar();
    updateAreaOfBorder();
}

void TextBox::setTextArea(Object::Ptr<TextArea> textArea)
{
    remove(m_textArea);
    add(textArea);
    m_textArea = textArea;

    updateAreaOfTextArea();
}

Object::Ptr<TextArea> TextBox::getTextArea() const
{
    return m_textArea;
}

void TextBox::setScrollBar(Object::Ptr<ScrollBar> scrollBar)
{
    remove(m_scrollBar);
    add(scrollBar);
    m_scrollBar = scrollBar;

    m_scrollBar->toFront();

    updateAreaOfScrollBar();
}

Object::Ptr<ScrollBar> TextBox::getScrollBar() const
{
    return m_scrollBar;
}

void TextBox::setBorder(Object::Ptr<Border> border)
{
    remove(m_border);
    add(border);
    m_border = border;

    updateAreaOfBorder();
}

Object::Ptr<Border> TextBox::getBorder() const
{
    return m_border;
}

void TextBox::updateAreaOfTextArea()
{
    Area textArea(1,
        1,
        std::max(m_area.size.x - 2, 0),
        std::max(m_area.size.y - 2, 0));

    if (m_textArea != nullptr) {
        m_textArea->setArea(textArea);
    }
}

void TextBox::updateAreaOfScrollBar()
{
    Area scrollBar(m_area.size.x - 1,
        1,
        1,
        std::max(m_area.size.y - 2, 0));

    if (m_scrollBar != nullptr) {
        m_scrollBar->setArea(scrollBar);
    }
}

void TextBox::updateAreaOfBorder()
{
    Area border(Vector2i::Zero, m_area.size);

    if (m_border != nullptr) {
        m_border->setArea(border);
    }
}
}
