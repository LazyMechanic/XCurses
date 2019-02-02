#include <PDCurses\curses.h>
#include <PDCurses\panel.h>
#include <cstdint>
#include <string>

struct Color
{
	short red;
	short green;
	short blue;
};

Color getPDCursesColor(short red, short green, short blue)
{
	return Color{
		static_cast<short>(((red - 0) / (255.0f)) * 1000.0f),
		static_cast<short>(((green - 0) / (255.0f)) * 1000.0f),
		static_cast<short>(((blue - 0) / (255.0f)) * 1000.0f)
	};
}

void main() {
	initscr();

	// Set size of terminal
	resize_term(50, 120);

	start_color();

	nodelay(stdscr, true);

	// Don't print symbols during writing
	noecho();

	keypad(stdscr, true);

	flushinp();

	timeout(0);

	//nocbreak();

	// Allow input CTRL+Z, CTRL+C etc.
	//raw();

	// Set no new line
	//nonl();

	mousemask(ALL_MOUSE_EVENTS, 0);
	mouseinterval(150);

	init_pair(0, COLOR_RED, COLOR_BLUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_CYAN);
	init_pair(3, COLOR_RED, COLOR_GREEN);
	init_pair(4, COLOR_RED, COLOR_MAGENTA);
	init_pair(5, COLOR_RED, COLOR_WHITE);
	init_pair(6, COLOR_YELLOW, COLOR_BLACK);
	init_pair(7, 8, 9);

	Color c1 = getPDCursesColor(235, 7, 87);
	Color c2 = getPDCursesColor(112, 186, 22);
	init_color(8, c1.red, c1.green, c1.blue);
	init_color(9, c2.red, c2.green, c2.blue);
    
	WINDOW* testWin1 = newwin(15, 15, 0, 0);
	WINDOW* testWin2 = newwin(15, 15, 0, 5);
	WINDOW* testWin3 = newwin(15, 15, 5, 0);
	WINDOW* testWin4 = newwin(15, 15, 5, 5);

	cchar_t backgroundChar = COLOR_PAIR(6) | 0x2591;
	wbkgrndset(testWin1, &backgroundChar);
	wclear(testWin1);

	wborder(testWin1, 0, 0, 0, 0, 0, 0, 0, 0);
	wborder(testWin2, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(testWin3, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(testWin4, '|', '|', '-', '-', '+', '+', '+', '+');

	wmove(testWin1, 0, 0);
	waddstr(testWin1, "testWin1");
	wrefresh(testWin1);

	wmove(testWin2, 0, 0);
	waddstr(testWin2, "testWin2");

	wmove(testWin3, 0, 0);
	waddstr(testWin3, "testWin3");

	wmove(testWin4, 0, 0);
	waddstr(testWin4, "testWin4");
	wrefresh(testWin4);

	attr_t attrs = 0;
	short colors = 0;

	mvwaddstr(testWin1, 5, 1, "ABCDEFG");
	mvwaddstr(testWin1, 6, 1, "HIGKLMN");
	mvwaddstr(testWin1, 10, 1, "OPQRSTU");

	mvwaddstr(testWin4, 5, 1, "ABCDEFG");
	mvwaddstr(testWin4, 6, 1, "HIGKLMN");
	mvwaddstr(testWin4, 10, 1, "OPQRSTU");

	cchar_t inputChar;

	//bottom_panel(testPanel1);
	//top_panel(testPanel4);

	bool isRunning = true;
	while (isRunning) {
		inputChar = wgetch(stdscr);
        if (inputChar != ERR) {
			switch (inputChar & 0xffff) {
			case '1': {
				resize_window(testWin1, 5, 5);
				break;
			}
			case '[': {
				touchwin(testWin1);
				break;
			}
			case ']': {
				touchwin(testWin4);
				break;
			}
			case ';': {
				wrefresh(testWin1);
				break;
			}
			case '\'': {
				wrefresh(testWin4);
				break;
			}
			default: {
				waddch(testWin1, inputChar);
				waddch(testWin4, inputChar);
			}
			}

			//waddch(testWin1, 'k');
        }


		wrefresh(testWin1);
		wrefresh(testWin4);
		//wrefresh(testWin2);
		//wrefresh(testWin4);
		//wrefresh(testWin3);
	}
	endwin();
}
