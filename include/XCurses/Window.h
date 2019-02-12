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
	friend class Core;

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
	static Window::Ptr<Type> create(Args&& ... args);

    /**
	 * \brief Window destructor
	 */
	virtual ~Window();

    /**
	 * \brief Function calling every tick. Virtual function
	 * \param dt Delta time
	 */
	virtual void update(float dt);

    /**
	 * \brief Add new widget
	 * \param widget Widget
	 * \return Ok if widget added successfully, Err if widget already exists, or
	 * if widget already added in another window
	 */
	virtual Status addWidget(const Widget::Ptr<>& widget) final;

    /**
	 * \brief Erase the widget
	 * \param widget Widget
	 * \return Ok if widget erased successfully, Err if widget not found
	 */
	virtual Status eraseWidget(const Widget::Ptr<>& widget) final;

    /**
	 * \brief Set new border
	 * \param border Border
	 */
	virtual void setBorder(const Border& border) final;

    /**
	 * \brief Get current border
	 * \return Border
	 */
	virtual Border getBorder() const final;

    /**
	 * \brief Get window id
	 * \return Id
	 */
	virtual uint32_t getId() const final;

    /**
	 * \brief Get curses window
	 * \return Raw ptr to curses window
	 */
	_win* getCursesWin() const;

protected:
    /**
	 * \brief Get core 
	 * \return Const ptr to core
	 */
	Core* const getCore() const;

    /**
	 * \brief Container of widgets
	 */
	std::unordered_map<const uint32_t, Widget::Ptr<>, std::function<size_t(const uint32_t&)>> m_widgets;

    /**
	 * \brief Border container
	 */
	Border m_border;

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
	 * \brief Call curses function for redraw border
	 */
	void updateCursesBorder() const;

    /**
	 * \brief Raw ptr to core
     */
	Core* m_core;
    
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
