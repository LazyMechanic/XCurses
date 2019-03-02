#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>

#include <XCurses/XCurses.h>

using namespace xcur;

TEST_CASE("Attribute init and edit", "[String]")
{
    SECTION("Empty attribute")
    {
		Attribute attr;
		REQUIRE(attr.value == 0);
		REQUIRE(attr.has(Attribute::Normal) == true);
    }

    SECTION("Construct attribute from uint32_t")
    {
		Attribute attr(0x00080000);
		REQUIRE(attr.toCursesAttr() == 0x00080000);
		REQUIRE(attr.has(Attribute::Italic) == true);
    }
}

TEST_CASE("Char init and edit", "[Char]")
{
	SECTION("Empty character") {
		Char ch;
        REQUIRE(ch.toCursesChar() == 0);

		ch.setAttr(Attribute::Bold);
		REQUIRE(ch.getAttr() == Attribute::Bold);

		ch.setColorPairId(10);
		REQUIRE(static_cast<uint32_t>(ch.getColorPairId()) == 10);

		ch.setChar(25);
		REQUIRE(static_cast<uint32_t>(ch.getChar()) == 25);

		REQUIRE(ch.toCursesChar() == 0x0A800019);
    }

    SECTION("Construct character from uint16_t")
	{
		Char ch(54);
		REQUIRE(ch.getChar() == 54);
	}

	SECTION("Construct character from colorPairId, attr and char")
	{
		Char ch(10, Attribute::Bold, 25);

		REQUIRE(ch.getAttr() == Attribute::Bold);
		REQUIRE(static_cast<uint32_t>(ch.getColorPairId()) == 10);
		REQUIRE(static_cast<uint32_t>(ch.getChar()) == 25);
		REQUIRE(ch.toCursesChar() == 0x0A800019);
	}
}

TEST_CASE("String init and edit", "[String]")
{
    SECTION("Empty string")
    {
		String str;
		REQUIRE(str.size() == 0);
    }
}