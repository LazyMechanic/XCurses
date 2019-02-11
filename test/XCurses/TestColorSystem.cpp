#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>

#include <XCurses/Color.h>
#include <XCurses/ColorSystem.h>
#include <XCurses/ColorPalette.h>

using namespace xcur;

TEST_CASE("Color init, edit and manipulating", "[Color]")
{
    SECTION("Create color with empty constructor")
    {
		const Color color;
		REQUIRE(color.r == 0);
		REQUIRE(color.g == 0);
		REQUIRE(color.b == 0);
    }

    SECTION("Create color with 3 components")
    {
		const Color color(50, 70, 100);
		REQUIRE(color.r == 50);
		REQUIRE(color.g == 70);
		REQUIRE(color.b == 100);
    }

	SECTION("Create color with hex notation")
	{
		const Color color(0xAACCEE);
		REQUIRE(color.r == 0xAA);
		REQUIRE(color.g == 0xCC);
		REQUIRE(color.b == 0xEE);
	}

	SECTION("Color operator ==")
	{
		const Color color1(30, 10, 55);
		const Color color2(30, 10, 55);
		bool result = color1 == color2;

		REQUIRE(result == true);
	}

	SECTION("Colors operator !=")
	{
	    const Color color1(30, 10, 55);
	    const Color color2(31, 10, 55);
		bool result = color1 != color2;

		REQUIRE(result == true);
	}

	SECTION("Color operator +")
	{
	    const Color color1(30, 10, 55);
	    const Color color2(50, 0, 220);
		Color colorResult = color1 + color2;

		uint8_t correctRed = 80;
		uint8_t correctGreen = 10;
		uint8_t correctBlue = 255;

		REQUIRE(colorResult.r == correctRed);
		REQUIRE(colorResult.g == correctGreen);
		REQUIRE(colorResult.b == correctBlue);
	}

    SECTION("Color operator -")
    {
        const Color color1(70, 10, 55);
        const Color color2(50, 0, 100);
		Color colorResult = color1 - color2;

		uint8_t correctRed = 20;
		uint8_t correctGreen = 10;
		uint8_t correctBlue = 0;

		REQUIRE(colorResult.r == correctRed);
		REQUIRE(colorResult.g == correctGreen);
		REQUIRE(colorResult.b == correctBlue);
    }

	SECTION("Color operator *")
	{
	    const Color color1(70, 10, 55);
	    const Color color2(50, 0, 100);
		Color colorResult = color1 * color2;

		uint8_t correctRed = static_cast<uint8_t>(static_cast<int>(color1.r) * color2.r / 255);
		uint8_t correctGreen = static_cast<uint8_t>(static_cast<int>(color1.g) * color2.g / 255);
		uint8_t correctBlue = static_cast<uint8_t>(static_cast<int>(color1.b) * color2.b / 255);

		REQUIRE(colorResult.r == correctRed);
		REQUIRE(colorResult.g == correctGreen);
		REQUIRE(colorResult.b == correctBlue);
	}

	SECTION("Color default RGB value to curses value")
	{
		const Color color(100, 55, 233);
		
		uint16_t correctRed = 392;
		uint16_t correctGreen = 215;
		uint16_t correctBlue = 913;

		REQUIRE(color.cursesRed() == correctRed);
		REQUIRE(color.cursesGreen() == correctGreen);
		REQUIRE(color.cursesBlue() == correctBlue);
	}
}

TEST_CASE("ColorPalette init and edit", "[Color][ColorPalette]")
{
	SECTION("Create ColorPalette with empty constructor")
	{
		ColorPalette palette;
		REQUIRE(palette.numberOfColors() == 0);
		REQUIRE(palette.numberOfColorPairs() == 0);

		SECTION("Add in ColorPalette new color")
		{
		    const size_t numberOfColorsBefore = palette.numberOfColors();

			Color addableColor(100, 200, 50);
			palette.addColor(addableColor);
			size_t correctNumberOfColors = numberOfColorsBefore + 1;

			REQUIRE(palette.numberOfColors() == correctNumberOfColors);

            SECTION("Find color function")
            {
                const auto addedColorIt = palette.findColor(addableColor);
				Color addedColor = addedColorIt->first;
				REQUIRE(addedColor == addableColor);
            }
		}
	}

	SECTION("Create ColorPalette with colors, number of colors == maximum")
	{
		std::list<Color> colors;
		const uint16_t numberOfColors = ColorPalette::maxNumberOfColors;
		for (size_t i = 0; i < numberOfColors; i++) {
			colors.emplace_back(i, i, i);
		}
		INFO("Number of colors in palette should be equal " << colors.size());
		ColorPalette palette(colors);

		REQUIRE(palette.numberOfColors() == numberOfColors);

        SECTION("Find the color in ColorPalette")
        {
			REQUIRE(palette.findColor(Color(0, 0, 0)) != palette.colorEnd());
        }

		SECTION("Add in ColorPalette new color")
		{
			size_t numberOfColorsBefore = palette.numberOfColors();
		    
            const Color addableColor(100, 200, 50);
			palette.addColor(addableColor);
			size_t correctNumberOfColorsAfterAdd = ColorPalette::maxNumberOfColors;

			auto addedColorIt = palette.findColor(addableColor);
			Color addedColor = addedColorIt->first;

			REQUIRE(palette.numberOfColors() == correctNumberOfColorsAfterAdd);
			REQUIRE(addedColorIt == palette.colorEnd());
		}
	}

	SECTION("Create ColorPalette with colors, number of colors > maximum")
	{
		std::list<Color> colors;
		const uint16_t numberOfColors = ColorPalette::maxNumberOfColors + 3;
		for (size_t i = 0; i < numberOfColors; i++) {
			colors.emplace_back(i, i, i);
		}
		INFO("Number of colors in palette should be equal " << ColorPalette::maxNumberOfColors);
		ColorPalette palette(colors);

		REQUIRE(palette.numberOfColors() < numberOfColors);
		REQUIRE(palette.numberOfColors() == ColorPalette::maxNumberOfColors);

		SECTION("Add in ColorPalette new color")
		{
			size_t numberOfColorsBefore = palette.numberOfColors();
		    
		    const Color addableColor(100, 200, 50);
			palette.addColor(addableColor);
			size_t correctNumberOfColorsAfterAdd = ColorPalette::maxNumberOfColors;

			auto addedColorIt = palette.findColor(addableColor);
			Color addedColor = addedColorIt->first;

			REQUIRE(palette.numberOfColors() == correctNumberOfColorsAfterAdd);
			REQUIRE(addedColorIt == palette.colorEnd());
		}
	}

	SECTION("Create ColorPalette with colors, number of colors < maximum")
	{
		std::list<Color> colors;
		const uint16_t numberOfColors = ColorPalette::maxNumberOfColors - 3;
		for (size_t i = 0; i < numberOfColors; i++) {
			colors.emplace_back(i, i, i);
		}
		INFO("Number of colors in palette should be equal " << colors.size());
		ColorPalette palette(colors);

		REQUIRE(palette.numberOfColors() == numberOfColors);

		SECTION("Add in ColorPalette new color")
		{
			size_t numberOfColorsBefore = palette.numberOfColors();

			Color addableColor(100, 200, 50);
			palette.addColor(addableColor);
			size_t correctNumberOfColorsAfterAdd = numberOfColorsBefore + 1;
		    
		    const auto addedColorIt = palette.findColor(addableColor);
			Color addedColor = addedColorIt->first;

			REQUIRE(palette.numberOfColors() == correctNumberOfColorsAfterAdd);

			REQUIRE(addedColor.r == addableColor.r);
			REQUIRE(addedColor.g == addableColor.g);
			REQUIRE(addedColor.b == addableColor.b);
		}
	}

    SECTION("Swap color in ColorPalette")
	{
		std::list<Color> colors;
		const uint16_t correctNumberOfColors = ColorPalette::maxNumberOfColors - 3;
		for (size_t i = 0; i < correctNumberOfColors; i++) {
			colors.emplace_back(i, i, i);
		}
		ColorPalette palette(colors);

        SECTION("Existed color")
        {
			Color colorFrom(0, 0, 0);
			Color colorTo(32, 1, 50);
			REQUIRE(palette.swapColor(colorFrom, colorTo) == Status::Ok);
			REQUIRE(palette.findColor(colorTo) != palette.colorEnd());
        }

		SECTION("Nonexistent color")
		{
			Color colorFrom(52, 1, 32);
			Color colorTo(32, 1, 50);
			REQUIRE(palette.swapColor(colorFrom, colorTo) == Status::Err);
		}
	}

    SECTION("Init color pair in ColorPalette")
	{
		std::list<Color> colors;
		const uint16_t correctNumberOfColors = ColorPalette::maxNumberOfColors;
		for (size_t i = 0; i < correctNumberOfColors; i++) {
			colors.emplace_back(i, i, i);
		}
		ColorPalette palette(colors);

        SECTION("Existed colors")
        {
			Color color1(0, 0, 0);
			Color color2(1, 1, 1);
			Status initStatus = palette.initColorPair(color1, color2);
			REQUIRE(initStatus == Status::Ok);

			uint8_t correctColorPairId = 0;
			REQUIRE(palette.getColorPairId(color1, color2) == correctColorPairId);

			auto colorPairIt = palette.findColorPair(color1, color2);
			REQUIRE(colorPairIt != palette.colorPairEnd());
        }

		SECTION("Nonexistent colors")
		{
		    const Color color1(254, 254, 0);
		    const Color color2(100, 50, 1);
			Status initStatus = palette.initColorPair(color1, color2);
			REQUIRE(initStatus == Status::Err);
		}
	}

    SECTION("Get color pair id in ColorPalette without init")
	{
		std::list<Color> colors;
		const uint16_t correctNumberOfColors = ColorPalette::maxNumberOfColors;
		for (size_t i = 0; i < correctNumberOfColors; i++) {
			colors.emplace_back(i, i, i);
		}
		ColorPalette palette(colors);

		SECTION("Existed colors")
		{
			const Color color1(0, 0, 0);
			const Color color2(1, 1, 1);

			uint8_t correctColorPairId = 0;
			REQUIRE(palette.getColorPairId(color1, color2) == correctColorPairId);

			auto colorPairIt = palette.findColorPair(color1, color2);
			REQUIRE(colorPairIt != palette.colorPairEnd());
		}

		SECTION("Nonexistent colors")
		{
			const Color color1(254, 254, 0);
			const Color color2(100, 50, 1);
			
			uint8_t correctColorPairId = palette.getDefaultColorPairId();
			REQUIRE(palette.getColorPairId(color1, color2) == palette.getDefaultColorPairId());

			auto colorPairIt = palette.findColorPair(color1, color2);
			REQUIRE(colorPairIt == palette.colorPairEnd());
		}
	}

    SECTION("Set color pair by default in ColorPalette")
	{
		std::list<Color> colors;
		const uint16_t correctNumberOfColors = ColorPalette::maxNumberOfColors;
		for (size_t i = 0; i < correctNumberOfColors; i++) {
			colors.emplace_back(i, i, i);
		}
		ColorPalette palette(colors);

        SECTION("Existed colors")
        {
			const Color color1(0, 0, 0);
			const Color color2(1, 1, 1);
			Status setDefaultColorPairStatus = palette.setDefaultColorPair(color1, color2);
			REQUIRE(setDefaultColorPairStatus == Status::Ok);
        }

		SECTION("Nonexistent colors")
		{
			const Color color1(254, 254, 0);
			const Color color2(100, 50, 1);

			Status setDefaultColorPairStatus = palette.setDefaultColorPair(color1, color2);
			REQUIRE(setDefaultColorPairStatus == Status::Err);

			REQUIRE(palette.findColorPair(color1, color2) == palette.colorPairEnd());
		}
	}
}

TEST_CASE("ColorSystem init and edit", "[Color][ColorPalette][ColorSystem]")
{
	ColorSystem colorSystem;

    SECTION("Create ColorSystem")
    {
		REQUIRE(colorSystem.findColorPalette("default") != colorSystem.colorPaletteEnd());
    }

	SECTION("Add the color palette")
	{
		std::list<Color> colors;
		const uint16_t correctNumberOfColors = ColorPalette::maxNumberOfColors;
		for (size_t i = 0; i < correctNumberOfColors; i++) {
			colors.emplace_back(i, i, i);
		}
	    const ColorPalette palette(colors);

		SECTION("Color palette name in lower case")
		{
			colorSystem.addColorPalette("custom_palette", palette);
			REQUIRE(colorSystem.findColorPalette("CUSTOM_PALETTE") != colorSystem.colorPaletteEnd());
		}

		SECTION("Color palette name in upper case")
		{
			colorSystem.addColorPalette("CUSTOM_PALETTE", palette);
			REQUIRE(colorSystem.findColorPalette("custom_palette") != colorSystem.colorPaletteEnd());
		}

		SECTION("Color palette name in mix case")
		{
			colorSystem.addColorPalette("CuStOm_pAlEtTe", palette);
			REQUIRE(colorSystem.findColorPalette("cUsToM_PaLeTtE") != colorSystem.colorPaletteEnd());
		}

        SECTION("Use the color palette")
		{
			colorSystem.addColorPalette("custom_palette", palette);
			colorSystem.useColorPalette("custom_palette");
			REQUIRE(colorSystem.getCurrentPalette() == colorSystem.findColorPalette("custom_palette")->second.get());
		}
	}
}