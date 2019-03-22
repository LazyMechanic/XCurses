#pragma once

#include <XCurses/Graphics/TextArea.h>
#include <XCurses/Graphics/Inputtable.h>

namespace xcur {
class InputTextArea :
    public TextArea,
    public Inputtable
{
public:
    /**
     * \brief Create InputTextArea with specific position and size
     * \param area InputTextArea area
     * \return Smart ptr to InputTextArea
     */
    static Object::Ptr<InputTextArea> create(const Area& area);

    /**
     * \brief InputTextArea destructor
     */
    virtual ~InputTextArea() = default;

    /**
     * \brief Call for update object state
     * \param dt Delta time
     */
    void update(float dt) override;

protected:
    /**
     * \brief InputTextArea constructor. Construct it with specific position and size
     * \param area InputTextArea area
     */
    InputTextArea(const Area& area);

    /**
     * \brief Update content string
     */
    void updateContent();
};
}