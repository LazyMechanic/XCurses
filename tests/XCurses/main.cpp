#include <XCurses/Curses.h>
#include "TestColorSystem.h"

using namespace xcur;

void main() {
	Curses curs;
	curs.init();

	test_ColorSystem();
}