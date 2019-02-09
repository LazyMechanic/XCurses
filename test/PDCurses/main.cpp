#include <PDCurses\curses.h>
#include <PDCurses\panel.h>
#include <cstdint>
#include <string>
#include <iostream>

#include <XCurses/ColorSystem.h>

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
    /*
	initscr();

	// Set size of terminal
	resize_term(50, 100);

	start_color();

	// Don't print symbols during writing
	noecho();

	//nocbreak();

	// Allow input CTRL+Z, CTRL+C etc.
	//raw();

	// Set no new line
	//nonl();

	mousemask(ALL_MOUSE_EVENTS, 0);
	mouseinterval(150);

	Color c1 = getPDCursesColor(125, 209, 181);
	Color c2 = getPDCursesColor(253, 145, 246);
	short colorNum = 15;
	short pairNum = 5;
	init_pair(pairNum, COLOR_BLACK, colorNum);
	init_color(colorNum, c2.red, c2.green, c2.blue);

	mvaddch(30, 2, 'C' | COLOR_PAIR(pairNum));
	wgetch(stdscr);
	init_color(colorNum, c1.red, c1.green, c1.blue);
	mvaddch(30, 3, 'C' | COLOR_PAIR(pairNum));
	flash();

	wgetch(stdscr);


	WINDOW* testWin1 = newwin(15, 15, 0, 0);
	WINDOW* testWin2 = newwin(15, 15, 0, 5);
	WINDOW* testWin3 = newwin(15, 15, 5, 0);
	WINDOW* testWin4 = newwin(15, 15, 20, 20);

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

	nodelay(stdscr, true);
	//halfdelay(255);
	timeout(255);

	bool isRunning = true;
	while (isRunning) {
		inputChar = wgetch(stdscr);
        if (inputChar != ERR) {
			waddch(testWin1, 'k' | COLOR_PAIR(52));
        }


		wrefresh(testWin1);
		wrefresh(testWin4);
		//wrefresh(testWin2);
		//wrefresh(testWin4);
		//wrefresh(testWin3);
	}
	endwin();
    */
    xcur::ColorSystem c;
	getchar();
}
