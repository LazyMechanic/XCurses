#include <PDCurses/curses.h>

void main() {
	initscr();

	// Set size of terminal
	resize_term(50, 120);

	// Don't print symbols during writing
	noecho();

	// Allow input CTRL+Z, CTRL+C etc.
	raw();

	// Set no new line
	nonl();

	// Refresh stdscr
	//refresh();
    
	WINDOW* testWin1 = newwin(15, 15, 0, 0);
	WINDOW* testWin2 = newwin(15, 15, 0, 5);
	WINDOW* testWin3 = newwin(15, 15, 5, 0);
	WINDOW* testWin4 = newwin(15, 15, 5, 5);

	wborder(testWin1, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(testWin2, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(testWin3, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(testWin4, '|', '|', '-', '-', '+', '+', '+', '+');

	wmove(testWin1, 0, 0);
	waddstr(testWin1, "testWin1");

	wmove(testWin2, 0, 0);
	waddstr(testWin2, "testWin2");

	wmove(testWin3, 0, 0);
	waddstr(testWin3, "testWin3");

	wmove(testWin4, 0, 0);
	waddstr(testWin4, "testWin4");

	bool isRunning = true;
	while (isRunning) {
		wrefresh(testWin1);
		wrefresh(testWin2);
		wrefresh(testWin4);
		wrefresh(testWin3);
	}
	endwin();
}