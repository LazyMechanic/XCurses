#include <XCurses/Graphics/RootWindow.h>

#include <PDCurses/curses.h>

#include <XCurses/System/Core.h>
#include <XCurses/Graphics/Context.h>
#include <XCurses/Graphics/ContextSystem.h>

namespace xcur {
RootWindow::RootWindow() :
    Window({ 0, 0 },{ getmaxx(stdscr), getmaxy(stdscr) })
{
}

void RootWindow::update(float dt)
{
	auto context = getContext();
    if (context != nullptr &&
		context->getContextSystem() != nullptr)
	{
		auto core = context->getContextSystem()->getCore();
		if (core->isTerminalResized()) {
            resize(core->getTerminalSize());
		}
    }
}
}
