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

void myClear(WINDOW* win)
{
    for (size_t column = 0; column < win->_maxx; ++column) {
        for (size_t row = 0; row < win->_maxy; ++row) {
            win->_y[row][column] = ' ';
        }
    }
}

void main() {
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

    WINDOW* win1 = newwin(30, 30, 5, 5);
    wborder(win1, '-', '-', '-', '-', '-', '-', '-', '-');
    wrefresh(win1);

    nodelay(win1, true);

    mousemask(ALL_MOUSE_EVENTS, 0);
    mouseinterval(150);

    size_t column = 3;
    size_t row = 3;
    wmove(win1, row, column);


    bool isRunning = true;
    while (isRunning) {
        chtype inputChar = wgetch(win1);
        if (inputChar != ERR) {
            if (inputChar == '1') {
                mvaddch(30, 30, 'A');
            }
            if (inputChar == 'r') {
                wrefresh(win1); 
                touchwin(win1);
            }
            if (inputChar == 'c') {
                myClear(win1);
            }
            if (inputChar == 'o') {
                clearok(win1, true);
            }
            if (inputChar == 'e') {
                win1->_y[20][20] = 'L';
            }
            if (inputChar == 't') {
                myClear(win1);
                win1->_y[20][20] = 'L';
                win1->_y[20][21] = 'K';
                wrefresh(win1);
                touchwin(win1);
            }
            if (inputChar == 'm') {
                wmove(win1, 10, 10);
            }
        }
        //myClear(win1);
    }
    endwin();
}
