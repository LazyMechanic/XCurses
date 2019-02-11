#pragma once

#include <memory>
#include <cstdint>

#include <XCurses/Border.h>
#include <XCurses/Status.h>

namespace xcur {
class Window
{
public:
	/*
	 *template <typename Type>
	 * void addWidget(Type widget);
	 * 
	 * TYPE findWidgetById();
	 * 
	 * In update func iterate through all widgets and call them update
	 * Save parent window in widget
	 * 
	 * When draw - clear window and redraw all widgets
	 */

	friend class XCurses;

	using Ptr = std::unique_ptr<Window>;

	Window();

	Window(const Window&);

	Window(Window&&);

	virtual ~Window();

	virtual void update(float dt);

private:
	virtual void draw();
	/**
	 * \brief PDCurses window pointer
	 */
	WINDOW* m_win;
};
}