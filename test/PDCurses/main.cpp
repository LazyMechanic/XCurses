#include <PDCurses\curses.h>
#include <PDCurses\panel.h>
#include <cstdint>
#include <string>
#include <iostream>

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
	resize_term(50, 100);

	start_color();

	// Don't print symbols during writing
	noecho();

	nodelay(stdscr, true);

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

	//mvaddch(0, 2, 'C' | COLOR_PAIR(pairNum));
	wgetch(stdscr);
	init_color(colorNum, c1.red, c1.green, c1.blue);
	//mvaddch(0, 3, 'C' | COLOR_PAIR(pairNum));
	flash();

	wgetch(stdscr);


	WINDOW* testWin1 = newwin(30, 30, 0, 0);
	WINDOW* testWin2 = newwin(15, 15, 0, 5);
	WINDOW* testWin3 = newwin(15, 15, 5, 0);
	WINDOW* testWin4 = newwin(15, 15, 20, 20);
	//curs_set(1);

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
	//wrefresh(testWin2);

	wmove(testWin3, 0, 0);
	waddstr(testWin3, "testWin3");
	//wrefresh(testWin3);

	wmove(testWin4, 0, 0);
	waddstr(testWin4, "testWin4");
	wrefresh(testWin4);

	attr_t attrs = 0;
	short colors = 0;

	chtype inputChar = ERR;

	//bottom_panel(testPanel1);
	//top_panel(testPanel4);

	bool isRunning = true;
	int i = 0;
	while (isRunning) {
		curs_set(0);
		inputChar = wgetch(stdscr);
		curs_set(1);
        if (inputChar != ERR) {
			if (inputChar == '1') {
				clearok(testWin1, true);
			}
            if (inputChar == '2') {
				wnoutrefresh(testWin1);
            }
            if (inputChar == '3') {
				touchwin(testWin1);
				wnoutrefresh(testWin1);
			    mvwaddch(testWin1, 5, 5, inputChar);
            }
			if (inputChar == '4') {
				clear();
			}
			if (inputChar == '5') {
				refresh();
			}
			if (inputChar == '6') {
				//testWin1 = resize_window(testWin1, 30, 30);
				wclear(testWin1);
			}
			if (inputChar == '7') {
				mvwin(testWin1, i, i);
				i += 3;
				clear();
				refresh();
				wclear(testWin1);
				wrefresh(testWin1);
			}
            if (inputChar == '8') {
				resize_term(70, 150);
            }
        }

		//wnoutrefresh(testWin1);
		//wnoutrefresh(testWin2);
		//wnoutrefresh(testWin3);
		//wnoutrefresh(testWin4);

		doupdate();
	}
	endwin();
}
