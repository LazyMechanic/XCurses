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
	 * \brief Default color system constructor. Construct with default palette with name is "default".
	 * Colors use like windows cmd
	 */
	ColorSystem();

    /**
	 * \brief Add palette
	 * \param paletteName Palette key
	 * \param palette Addable palette
	 * \return Ok if palette insert is successful, Err if the palette already exists
	 */
	Status addColorPalette(const std::string& paletteName, const ColorPalette& palette);

    /**
	 * \brief Set current color palette
	 * \param paletteName Palette key
	 * \return Ok if the palette exists, Err if the palette not found
	 */
	Status useColorPalette(const std::string& paletteName);

    /**
	 * \brief Get the color pair from the palette.
	 * \param paletteName Palette name
	 * \param foreground Foreground (text) color
	 * \param background Background color
	 * \return The color pair id if successful, 0 or the default palette color pair id if 
	 * palette not found or foreground or background not found
	 */
	uint8_t getColorPairId(const std::string& paletteName, const Color& foreground, const Color& background);

    /**
	 * \brief Get raw pointer to the palette
	 * \param paletteName Palette name
	 * \return The pointer to the palette if it exist, nullptr if the palette not found
	 */
	ColorPalette* const getColorPalette(const std::string& paletteName);

    /**
	 * \brief Get raw pointer to the current palette
	 * \return The pointer to the current palette.
	 */
	ColorPalette* const getCurrentPalette() const;

private:
	ColorPalette* m_curPalette;

	std::unordered_map<std::string, ColorPalette> m_palettes;
};
}
