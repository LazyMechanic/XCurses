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
		Color color;
		REQUIRE(color.r == 0);
		REQUIRE(color.g == 0);
		REQUIRE(color.b == 0);
    }

    SECTION("Create color with 3 components")
    {
		Color color(50, 70, 100);
		REQUIRE(color.r == 50);
		REQUIRE(color.g == 70);
		REQUIRE(color.b == 100);
    }

	SECTION("Create color with hex notation")
	{
		Color color(0xAACCEE);
		REQUIRE(color.r == 0xAA);
		REQUIRE(color.g == 0xCC);
		REQUIRE(color.b == 0xEE);
	}

	SECTION("Color operator ==")
	{
		Color color1(30, 10, 55);
		Color color2(30, 10, 55);
		bool result = color1 == color2;

		REQUIRE(result == true);
	}

	SECTION("Colors operator !=")
	{
		Color color1(30, 10, 55);
		Color color2(31, 10, 55);
		bool result = color1 != color2;

		REQUIRE(result == true);
	}

	SECTION("Color operator +")
	{
		Color color1(30, 10, 55);
		Color color2(50, 0, 220);
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
		Color color1(70, 10, 55);
		Color color2(50, 0, 100);
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
		Color color1(70, 10, 55);
		Color color2(50, 0, 100);
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
		Color color(100, 55, 233);		
		
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
	}

	SECTION("Create ColorPalette with colors, number of colors == maximum")
	{
		std::list<Color> colors;
		const uint16_t correctNumberOfColors = ColorPalette::maxNumberOfColors;
		for (size_t i = 0; i < correctNumberOfColors; i++) {
			colors.push_back(Color(i, i, i));
		}
		INFO("Number of colors in palette should be equal " << colors.size());
		ColorPalette palette(colors);

		REQUIRE(palette.numberOfColors() == correctNumberOfColors);

		SECTION("Add in ColorPalette new color")
		{
			size_t numberOfColorsBefore = palette.numberOfColors();

			Color addableColor(100, 200, 50);
			palette.addColor(addableColor);
			size_t correctNumberOfColors = ColorPalette::maxNumberOfColors;

			auto addedColorIt = palette.findColor(addableColor);
			Color addedColor = addedColorIt->first;

			REQUIRE(palette.numberOfColors() == correctNumberOfColors);
			REQUIRE(addedColorIt == palette.colorEnd());
		}
	}

	SECTION("Create ColorPalette with colors, number of colors > maximum")
	{
		std::list<Color> colors;
		const uint16_t numberOfColors = ColorPalette::maxNumberOfColors + 3;
		for (size_t i = 0; i < numberOfColors; i++) {
			colors.push_back(Color(i, i, i));
		}
		INFO("Number of colors in palette should be equal " << ColorPalette::maxNumberOfColors);
		ColorPalette palette(colors);

		REQUIRE(palette.numberOfColors() < numberOfColors);
		REQUIRE(palette.numberOfColors() == ColorPalette::maxNumberOfColors);

		SECTION("Add in ColorPalette new color")
		{
			size_t numberOfColorsBefore = palette.numberOfColors();

			Color addableColor(100, 200, 50);
			palette.addColor(addableColor);
			size_t correctNumberOfColors = ColorPalette::maxNumberOfColors;

			auto addedColorIt = palette.findColor(addableColor);
			Color addedColor = addedColorIt->first;

			REQUIRE(palette.numberOfColors() == correctNumberOfColors);
			REQUIRE(addedColorIt == palette.colorEnd());
		}
	}

	SECTION("Create ColorPalette with colors, number of colors < maximum")
	{
		std::list<Color> colors;
		const uint16_t correctNumberOfColors = ColorPalette::maxNumberOfColors - 3;
		for (size_t i = 0; i < correctNumberOfColors; i++) {
			colors.push_back(Color(i, i, i));
		}
		INFO("Number of colors in palette should be equal " << colors.size());
		ColorPalette palette(colors);

		REQUIRE(palette.numberOfColors() == correctNumberOfColors);

		SECTION("Add in ColorPalette new color")
		{
			size_t numberOfColorsBefore = palette.numberOfColors();

			Color addableColor(100, 200, 50);
			palette.addColor(addableColor);
			size_t correctNumberOfColors = numberOfColorsBefore + 1;

			auto addedColorIt = palette.findColor(addableColor);
			Color addedColor = addedColorIt->first;

			REQUIRE(palette.numberOfColors() == correctNumberOfColors);

			REQUIRE(addedColor.r == addableColor.r);
			REQUIRE(addedColor.g == addableColor.g);
			REQUIRE(addedColor.b == addableColor.b);
		}
	}
}
