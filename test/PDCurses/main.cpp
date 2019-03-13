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
    initscr();
    WINDOW* w = newwin(40, 40, 0, 0);

    delwin(w);
    /*
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
    
    bool isRunning = true;
    while (isRunning) {
        chtype inputChar = wgetch(stdscr);
        if (inputChar != ERR) {
            
        }
    }
    endwin();
    */
}
