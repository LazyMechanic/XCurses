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
	 * \brief Set current color palette
	 * \param name Palette key
	 * \return Ok if the palette exists, Err if the palette not found
	 */
	Status useColorPalette(const std::string& name);

    /**
	 * \brief Get the color pair from the palette.
	 * \param paletteName 
	 * \param foreground 
	 * \param background 
	 * \return The color pair id if successful, 0 or the default palette color pair id if 
	 * palette not found or foreground or background not found
	 */
	uint8_t getColorPairId(const std::string& paletteName, const Color& foreground, const Color& background);

private:
	ColorPalette* m_curPalette;

	std::unordered_map<std::string, ColorPalette> m_palettes;
};
}
