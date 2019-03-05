#include <PDCurses\curses.h>
#include <PDCurses\panel.h>
#include <cstdint>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>

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
	using namespace std::chrono_literals;

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

	mvwinch(testWin1, 10, 10);

	//bottom_panel(testPanel1);
	//top_panel(testPanel4);

	WINDOW* baseWin = newwin(getmaxy(stdscr), getmaxx(stdscr), 0, 0);
	wmove(baseWin, 35, 35);

	bool isRunning = true;
	int i = 0;
	std::chrono::time_point<std::chrono::system_clock> lastTime = std::chrono::system_clock::now();
	while (isRunning) {
		std::chrono::time_point<std::chrono::system_clock> currentTime = std::chrono::system_clock::now();

		curs_set(0);
		inputChar = wgetch(stdscr);
		curs_set(1);
        if (inputChar != ERR) {
			if (inputChar == '1') {
				mvaddch(30, 30, '+');
			}
            if (inputChar == '2') {
				wnoutrefresh(testWin1);
            }
            if (inputChar == '3') {
				waddch(baseWin, 'K');
            }
			if (inputChar == '4') {
				mvwaddch(testWin2, 3, 3, inputChar);
			}
			if (inputChar == '5') {
				mvwaddch(testWin3, 3, 3, inputChar);
			}
			if (inputChar == '6') {
				mvwin(testWin1, i, i);
				i += 3;
			}
			if (inputChar == '7') {

			}
            if (inputChar == '8') {
				resize_term(70, 150);
            }
            if (inputChar == '9') {
				resize_term(60, 150);
            }
        }

        if (is_termresized()) {
			waddch(baseWin, 'K');
        }

		touchwin(baseWin);
		touchwin(testWin1);
		touchwin(testWin2);
		touchwin(testWin3);
		touchwin(testWin4);

		wnoutrefresh(baseWin);
		wnoutrefresh(testWin1);
		wnoutrefresh(testWin2);
		wnoutrefresh(testWin3);
		wnoutrefresh(testWin4);

		doupdate();

		//std::this_thread::sleep_until(currentTime + 80ms);
	}
	endwin();
}
