#include <XCurses/Text/Key.h>

#include <PDCurses/curses.h>

namespace xcur {
const uint16_t Key::Backspace = 0x08;
const uint16_t Key::Tab = 0x09;
const uint16_t Key::LineFeed = 0x0A;
const uint16_t Key::Insert = KEY_IC;
const uint16_t Key::Delete = KEY_DC;
const uint16_t Key::Down = KEY_DOWN;
const uint16_t Key::Up = KEY_UP;
const uint16_t Key::Left = KEY_LEFT;
const uint16_t Key::Right = KEY_RIGHT;
const uint16_t Key::Home = KEY_HOME;
const uint16_t Key::End = KEY_END;
const uint16_t Key::Enter = 0x0D;
const uint16_t Key::Esc = 0x1B;
const uint16_t Key::PageUp = KEY_PPAGE;
const uint16_t Key::PageDown = KEY_NPAGE;
const uint16_t Key::F1 = KEY_F(1);
const uint16_t Key::F2 = KEY_F(2);
const uint16_t Key::F3 = KEY_F(3);
const uint16_t Key::F4 = KEY_F(4);
const uint16_t Key::F5 = KEY_F(5);
const uint16_t Key::F6 = KEY_F(6);
const uint16_t Key::F7 = KEY_F(7);
const uint16_t Key::F8 = KEY_F(8);
const uint16_t Key::F9 = KEY_F(9);
const uint16_t Key::F10 = KEY_F(10);
const uint16_t Key::F11 = KEY_F(11);
const uint16_t Key::F12 = KEY_F(12);
}