#pragma once

#include <XCurses/System/Vector2.h>
#include <XCurses/Graphics/Window.h>

namespace xcur {
namespace detail {
class RootWindow : public Window
{
public:
	/**
	 * \brief Create RootWindow
	 * \return Smart ptr to RootWindow
	 */
	static Object::Ptr<RootWindow> create();

	/**
	 * \brief RootWindow destructor
	 */
	~RootWindow() = default;

	/**
	 * \brief Call for update object state
	 * \param dt Delta time
	 */
	void update(float dt) override final;

private:
	/**
	 * \brief Default RootWindow constructor. Construct window with size is terminal
	 */
	RootWindow();

    /**
	 * \brief Current terminal size
	 */
	Vector2u m_curTermSize;

    /**
	 * \brief Previous terminal size
	 */
	Vector2u m_prevTermSize;
};
}
}
