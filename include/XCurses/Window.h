#pragma once

#include <memory>
#include <unordered_map>

#include <XCurses/Border.h>
#include <XCurses/Status.h>
#include <XCurses/Widget.h>
#include <unordered_map>
struct _win;

namespace xcur {
class Window
{
public:
	friend class XCurses;

	using Ptr = std::shared_ptr<Window>;
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


	Window();

	Window(const Window&);

	Window(Window&&);

	virtual ~Window();

	virtual void update(float dt);

	virtual Widget::Ptr addWidget(const Widget& widget) final;

	virtual Widget::Ptr findWidgetById(uint32_t widgetId) final;

	virtual _win* getCursesWin() final;

private:
	virtual void draw();

	std::unordered_map<uint32_t, Widget::Ptr> m_widgets;
    
	/**
	 * \brief PDCurses window pointer
	 */
	_win* m_win;
};
}