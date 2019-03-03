#pragma once

#include <XCurses/Text/String.h>
#include <XCurses/Graphics/Widget.h>
#include <XCurses/Graphics/HasWindow.h>

namespace xcur {
class Title : public Widget, public HasWindow
{
public:
    /**
	 * \brief Default Title constructor. Construct title with "-" string
	 */
	Title();

    /**
     * \brief Title construct. Construct title with specific string
     * \param str String
     */
    Title(const String& str);

    /**
	 * \brief Copy Title constructor
	 */
	Title(const Title&) = default;

    /**
	 * \brief Move Title constructor
	 */
	Title(Title&&) = default;

    /**
	 * \brief Copy assignment operator for String
	 * \param str String
	 * \return Reference to \a this
	 */
	Title& operator =(const String& str);

	/**
	 * \brief Move assignment operator for String
	 * \param str String
	 * \return Reference to \a this
	 */
	Title& operator =(String&& str);

	/**
	 * \brief Default copy assignment operator
	 * \return Reference to \a this
	 */
	Title& operator =(const Title&) = default;

	/**
	 * \brief Default move assignment operator
	 * \return Reference to \a this
	 */
	Title& operator =(Title&&) = default;

    /**
	 * \brief Title destructor
	 */
	~Title() = default;

    /**
	 * \brief Set title string
	 * \param str String
	 */
	void setString(const String& str);

    /**
	 * \brief Get title string
	 * \return String
	 */
	String getString() const;

    /**
     * \brief Draw title. Add character into window and add in front and back space characters
     */
    void draw() override;

private:
    /**
	 * \brief Title string
	 */
	String m_string;
};
}