#pragma once

#include <XCurses/Graphics/Window.h>

namespace xcur {
namespace detail {
class RootWindow : public Window
{
public:
	/**
	 * \brief Default RootWindow constructor. Construct window with size is terminal
	 */
	RootWindow();

	/**
	 * \brief RootWindow destructor
	 */
	~RootWindow() = default;

	/**
	 * \brief Call for update object state
	 * \param dt Delta time
	 */
	void update(float dt) override final;
};
}
}
