#pragma once

#include <map>
#include <cstdint>

#include <XCurses/Color.h>
#include <XCurses/Status.h>

namespace xcur {
class ColorSystem
{
public:
	ColorSystem();

	Status changeColor(const Color& from, const Color& to);
    
private:
	std::map<std::pair<Color, Color>, uint16_t> m_colorPairs;

	std::map<Color, uint16_t> m_colors;
};
}
