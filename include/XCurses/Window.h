#pragma once

#include <memory>
#include <functional>
#include <unordered_map>

#include <XCurses/Border.h>
#include <XCurses/Status.h>
#include <XCurses/Widget.h>

struct _win;

namespace xcur {
class Window : public std::enable_shared_from_this<Window>
{
public:
	friend class XCurses;

    /**
	 * \brief std::shared_ptr<Window> alias
	 */
    template <typename Type = Window>
	using Ptr = std::shared_ptr<Type>;

	/**
	 * \brief Create window and return smart ptr
	 * \tparam Type Window type
	 * \tparam Args Arguments to constructor
	 * \param args Arguments
	 * \return Shared ptr
	 */
    template <typename Type, typename ... Args>
	Window::Ptr<Type> create(Args&& ... args);

    /**
	 * \brief Window destructor
	 */
	virtual ~Window();

    /**
	 * \brief Function calling every tick
	 * \param dt Delta time
	 */
	virtual void update(float dt);

    /**
	 * \brief Add new widget
	 * \param widget Widget
	 * \return Ok if widget added successfully, Err if widget already exists, or
	 * if widget already added in another window
	 */
	Status addWidget(const Widget::Ptr<>& widget);

    /**
	 * \brief Erase the widget
	 * \param widget Widget
	 * \return Ok if widget erased successfully, Err if widget not found
	 */
	Status eraseWidget(const Widget::Ptr<>& widget);

    /**
	 * \brief Get window id
	 * \return Id
	 */
	uint32_t getId() const;

    /**
	 * \brief Get curses window
	 * \return Raw ptr to curses window
	 */
	_win* getCursesWin() const;

protected:
    /**
	 * \brief Container of widgets
	 */
	std::unordered_map<const uint32_t, Widget::Ptr<>, std::function<size_t(const uint32_t&)>> m_widgets;

    /**
	 * \brief Window id
	 */
	const uint32_t m_id;

private:
    /**
	 * \brief Default Window constructor
	 */
	Window();

    /**
	 * \brief Get hash from widget id
	 * \param id Widget id
	 * \return Hash
	 */
	size_t widgetHash(const uint32_t& id);

    /**
	 * \brief Redraw window and all widgets
	 */
	void draw();
    
	/**
	 * \brief PDCurses window pointer
	 */
	_win* m_win;

    /**
	 * \brief Next window id
	 */
	static uint32_t nextWindowId;
};

template <typename Type, typename ... Args>
Window::Ptr<Type> Window::create(Args&&... args)
{
	return std::make_shared<Type>(std::forward<Args>(args)...);
}
}
