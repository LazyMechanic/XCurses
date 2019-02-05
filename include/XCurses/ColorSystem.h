#pragma once

#include <string>
#include <functional>
#include <unordered_map>

#include <XCurses/Color.h>
#include <XCurses/Status.h>
#include <XCurses/ColorPalette.h>

namespace xcur {
class ColorSystem
{
public:
    /**
	 * \brief 
	 */
	ColorSystem();

    /**
	 * \brief Add palette
	 * \param name Palette key
	 * \param palette Addable palette
	 * \return Ok if palette insert is successful, Err if the palette already exists
	 */
	Status addColorPalette(const std::string& name, const ColorPalette& palette);

	Status useColorPalette(const std::string& name);

    /**
	 * \brief 
	 * \param background 
	 * \param foreground 
	 * \return 
	 */
	Status setCharColors(const Color& background, const Color& foreground);
    
private:
	ColorPalette* m_curPalette;

	std::unordered_map<std::string, ColorPalette> m_palettes;
};
}
