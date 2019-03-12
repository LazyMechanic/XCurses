#include <XCurses/XCurses.h>

class SomeWindow : public xcur::Window
{
public:
    SomeWindow() : Window(xcur::Vector2u(0, 0), getContext()->getContextSystem()->getCore()->getTerminalSize())
    {
        
    }

    void update(float dt) override
    {
        
    }
};

int main()
{
	xcur::Object::Ptr<xcur::Core> core = xcur::Object::create<xcur::Core>();
	xcur::CoreConfig setupCore = xcur::CoreConfig::Default;

	core->init(setupCore);

	bool isRunning = true;
    while (isRunning) {
		core->handleEvents();
		core->update(0.0f);
		core->draw();
    }
}
