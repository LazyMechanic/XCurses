#pragma once

#include <cstdint>
#include <memory>

#include <PDCurses/curses.h>

#include <XCurses/Border.h>
#include <XCurses/Status.h>

namespace xcur {
class Window
{
public:
	friend class XCurses;

	using Ptr = std::unique_ptr<Window>;

	Window();

	Window(const Window&);

	Window(Window&&);

	virtual ~Window();

	/**
	 * \brief Add character in UTF-8 encoding in { x, y } point
	 * \param ch Character
	 * \param x Coordinate
	 * \param y Coordinate
	 * \return Window status code
	 */
	Status addChar(uint32_t ch, int x, int y);

	/**
	 * \brief Set border to window
	 * \param border Border to set
	 * \return Window status code
	 */
	Status setBorder(const Border& border);

	/**
	 * \brief Set border to window
	 * \param leftSide Character for left side of border
	 * \param rightSide Character for right side of border
	 * \param topSide Character for top side of border
	 * \param bottomSide Character for bottom side of border
	 * \param topLeftCorner Character for top left corner of border
	 * \param topRightCorner Character for top right corner of border
	 * \param bottomLeftCorner Character for bottom left corner of border
	 * \param bottomRightCorner Character for bottom right corner of border
	 * \return Window status code
	 */
	Status setBorder(
		uint32_t leftSide,
		uint32_t rightSide,
		uint32_t topSide,
		uint32_t bottomSide,
		uint32_t topLeftCorner,
		uint32_t topRightCorner,
		uint32_t bottomLeftCorner,
		uint32_t bottomRightCorner);

	/**
	 * \brief Refresh PDCurses window
	 * \return Window status code
	 */
	Status refresh() const;

private:
	/**
	 * \brief PDCurses window pointer
	 */
	WINDOW* m_win;

	/**
	 * \brief True if nodelay mode is ON, false if it is OFF
	 */
	bool m_nodelayMode;

	/**
	 * \brief True if keypad mode is ON, false if it is OFF
	 */
	bool m_keypadMode;

	/**
	 * \brief True if scrollok mode is ON, false if it is OFF
	 */
	bool m_scrollMode;

	/**
	 * \brief PDCurses window border container
	 */
	Border m_border;
};
}