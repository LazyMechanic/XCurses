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
     * \param position InputTextArea position
     * \param size InputTextArea size
     * \return Smart ptr to InputTextArea
     */
    static Object::Ptr<InputTextArea> create(const Vector2u& position, const Vector2u& size);

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
     * \param position InputTextArea position
     * \param size InputTextArea size
     */
    InputTextArea(const Vector2u& position, const Vector2u& size);

    /**
     * \brief Update content string
     */
    void updateContent();
};
}