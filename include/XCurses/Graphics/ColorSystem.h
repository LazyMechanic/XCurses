#pragma once

#include <string>
#include <memory>
#include <functional>
#include <unordered_map>

#include <XCurses/System/Object.h>
#include <XCurses/System/Status.h>
#include <XCurses/Graphics/Color.h>
#include <XCurses/Graphics/ColorPalette.h>

namespace xcur {
/**
 * \brief Class controls and contains color palettes.
 */
class ColorSystem :
    public Object
{
public:
    /**
     * \brief Const iterator alias
     */
    using ColorPaletteIterator = std::unordered_map<std::string, std::unique_ptr<ColorPalette>>::iterator;

	/**
	 * \brief Create ColorSystem
	 * \return Smart ptr to ColorSystem
	 */
	static Object::Ptr<ColorSystem> create();

    /**
     * \brief ColorSystem destructor
     */
    ~ColorSystem() = default;

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
     * \brief Apply current palette
     * \return Ok if the palette exists, Err if otherwise
     */
    Status applyCurrentColorPalette() const;

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
     * \brief Find color palette
     * \param paletteName Palette key
     * \return Const iterator to the pair of palette name and the palette
     */
    ColorPaletteIterator findColorPalette(const std::string& paletteName);

    /**
     * \brief Wrapper over color palette begin() const iterator
     * \return Const begin iterator
     */
    ColorPaletteIterator colorPaletteBegin();

    /**
     * \brief Wrapper over color palette end() const iterator
     * \return Const begin iterator
     */
    ColorPaletteIterator colorPaletteEnd();

    /**
     * \brief Get iterator to current color palette
     * \return The iterator to the current palette.
     */
    ColorPalette* getCurrentPalette() const;

private:
	/**
	 * \brief Default color system constructor. Construct with default palette with name is "default".
	 * Colors use like windows cmd
	 */
	ColorSystem();

    /**
     * \brief Raw pointer to current palette
     */
    ColorPalette* m_curColorPalette;

    /**
     * \brief Color palettes container
     */
    std::unordered_map<std::string, std::unique_ptr<ColorPalette>> m_palettes;
};
}
