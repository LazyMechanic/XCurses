#pragma once

#include <string>
#include <functional>
#include <unordered_map>

#include <XCurses/Char.h>
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

    /**
	 * \brief 
	 * \param name Palette key
	 * \return Ok if the palette exists, Err if the palette not found
	 */
	Status useColorPalette(const std::string& name);

    /**
	 * \brief Set new color pair in Char
	 * \param ch Character 
	 * \param background Background color
	 * \param foreground Foreground (text) color
	 * \return Char with updating color. If colors is wrong then return unchanged char
	 */
	Char setCharColors(const Char& ch, const Color& foreground, const Color& background) const;
    
private:
	ColorPalette* m_curPalette;

	std::unordered_map<std::string, ColorPalette> m_palettes;
};
}
