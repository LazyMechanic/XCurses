#pragma once
#include <memory>
#include <cstdint>

#include <XCurses/Status.h>

namespace xcur {
class Widget
{
public:
	friend class Window;

    /**
	 * \brief std::shared_ptr<Type> alias
	 * \tparam Type Widget type
	 */
	template <typename Type = Widget>
	using Ptr = std::shared_ptr<Type>;

    /**
	 * \brief Create widget and return smart ptr
	 * \tparam Type Widget type
	 * \tparam Args Arguments to constructor
	 * \param args Arguments
	 * \return Shared ptr
	 */
	template <typename Type, typename ... Args>
	static Widget::Ptr<Type> create(Args&& ... args);

    /**
	 * \brief Widget destructor
	 */
	virtual ~Widget() = default;

    /**
	 * \brief Get widget id
	 * \return Id
	 */
	virtual uint32_t getId() const final;

protected:
    /**
	 * \brief Redraw widget
	 */
	virtual void draw();

    /**
	 * \brief Ptr to parent window
	 */
	std::weak_ptr<Window> m_parentWindow;

    /**
	 * \brief Widget id
	 */
	const uint32_t m_id;

private:
    /**
	 * \brief Default Widget constructor.
	 */
	Widget();

    /**
	 * \brief Set new parent window
	 * \param window Window
	 */
	void setParentWindow(const std::shared_ptr<Window>& window);

    /**
	 * \brief Get parent window
	 * \return Shared ptr to parent window
	 */
	std::shared_ptr<Window> getParentWindow() const;

    /**
	 * \brief Next widget id
	 */
	static uint32_t nextWidgetId;
};

template <typename Type, typename ... Args>
Widget::Ptr<Type> Widget::create(Args&&... args)
{
	return std::make_shared<Type>(std::forward<Args>(args)...);
}
}
