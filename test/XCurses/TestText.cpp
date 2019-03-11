#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>

#include <XCurses/XCurses.h>

using namespace xcur;

TEST_CASE("Attribute init and edit", "[String]")
{
    SECTION("Construct empty attribute")
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

	SECTION("Operators")
	{
		SECTION("Attribute::operator=(uint32_t attr)")
		{
			Attribute attr;
			attr = 0x00650000;
			REQUIRE(static_cast<uint32_t>(attr.value) == 0x65);
		}

        SECTION("Attribute::operator==(const Attribute& right)")
		{
			Attribute attr1(0x00080000);
			Attribute attr2(0x00080000);
			REQUIRE(attr1 == attr2);
		}

		SECTION("Attribute::operator==(uint32_t right)")
		{
			Attribute attr(0x00080000);
			REQUIRE(attr == 0x00080000);
		}

		SECTION("Attribute::operator!=(const Attribute& right)")
		{
			Attribute attr1(0x00080000);
			Attribute attr2(0x00070000);
			REQUIRE(attr1 != attr2);
		}

		SECTION("Attribute::operator!=(uint32_t right)")
		{
			Attribute attr(0x00080000);
			REQUIRE(attr != 0x00070000);
		}

		SECTION("Attribute::operator|(const Attribute& right)")
		{
			Attribute attr1(0x00080000);
			Attribute attr2(0x00320000);
			Attribute resultAttr = attr1 | attr2;

			REQUIRE(resultAttr == 0x003a0000);
		}

		SECTION("Attribute::operator|(uint32_t right)")
		{
			Attribute attr(0x00080000);
			Attribute resultAttr = attr | 0x00320000;

			REQUIRE(resultAttr == 0x003a0000);
		}

		SECTION("Attribute::operator&(const Attribute& right)")
		{
			Attribute attr1(0x00250000);
			Attribute attr2(0x00320000);
			Attribute resultAttr = attr1 & attr2;

			REQUIRE(resultAttr == 0x00200000);
		}

		SECTION("Attribute::operator&(uint32_t right)")
		{
			Attribute attr(0x00250000);
			Attribute resultAttr = attr & 0x00320000;

			REQUIRE(resultAttr == 0x00200000);
		}

		SECTION("Attribute::operator|=(const Attribute& right)")
		{
			Attribute attr1(0x00080000);
			Attribute attr2(0x00320000);
			attr1 |= attr2;

			REQUIRE(attr1 == 0x003a0000);
		}

		SECTION("Attribute::operator|=(uint32_t right)")
		{
			Attribute attr(0x00080000);
			attr |= 0x00320000;

			REQUIRE(attr == 0x003a0000);
		}

		SECTION("Attribute::operator&=(const Attribute& right)")
		{
			Attribute attr1(0x00250000);
			Attribute attr2(0x00320000);
			attr1 &= attr2;

			REQUIRE(attr1 == 0x00200000);
		}

		SECTION("Attribute::operator&=(uint32_t right)")
		{
			Attribute attr(0x00250000);
			attr &= 0x00320000;

			REQUIRE(attr == 0x00200000);
		}
	}
}

TEST_CASE("Char init and edit", "[Char]")
{
	SECTION("Construct empty character") {
		Char ch;
        REQUIRE(ch.colorPairId == 0);
		REQUIRE(ch.attribute == Attribute::Normal);
		REQUIRE(ch.symbol == 0);

		ch.colorPairId = 10;
		ch.attribute = Attribute::Bold;
		ch.symbol = 25;

		REQUIRE(ch.toCursesChar() == 0x0A800019);
    }

    SECTION("Construct character from uint32_t")
	{
		SECTION("uint32_t char") {
			Char ch(54);
			REQUIRE(static_cast<uint32_t>(ch.colorPairId) == 0);
			REQUIRE(ch.attribute == Attribute::Normal);
			REQUIRE(ch.symbol == 54);
		}

		SECTION("Ansi char") {
			Char ch('B');
			REQUIRE(static_cast<uint32_t>(ch.colorPairId) == 0);
			REQUIRE(ch.attribute == Attribute::Normal);
			REQUIRE(ch.symbol == static_cast<uint16_t>('B'));
		}

		SECTION("Wide char") {
			Char ch(L'B');
			REQUIRE(static_cast<uint32_t>(ch.colorPairId) == 0);
			REQUIRE(ch.attribute == Attribute::Normal);
			REQUIRE(ch.symbol == static_cast<uint16_t>(L'B'));
		}
	}

	SECTION("Construct character from colorPairId, attr and char")
	{
		Char ch(10, Attribute::Bold, 25);
		REQUIRE(static_cast<uint32_t>(ch.colorPairId) == 10);
		REQUIRE(ch.attribute == Attribute::Bold);
		REQUIRE(ch.symbol == 25);
	}

	SECTION("Char::operator=(uint32_t ch)")
	{
		SECTION("uint32_t char") {
			Char ch;
			ch = 54;
			REQUIRE(static_cast<uint32_t>(ch.colorPairId) == 0);
			REQUIRE(ch.attribute == Attribute::Normal);
			REQUIRE(ch.symbol == 54);
		}

		SECTION("Ansi char") {
			Char ch;
			ch = 'B';
			REQUIRE(static_cast<uint32_t>(ch.colorPairId) == 0);
			REQUIRE(ch.attribute == Attribute::Normal);
			REQUIRE(ch.symbol == static_cast<uint16_t>('B'));
		}

		SECTION("Wide char") {
			Char ch;
			ch = L'B';
			REQUIRE(static_cast<uint32_t>(ch.colorPairId) == 0);
			REQUIRE(ch.attribute == Attribute::Normal);
			REQUIRE(ch.symbol == static_cast<uint16_t>(L'B'));
		}
	}
}

TEST_CASE("String init and edit", "[String][Char]")
{
    SECTION("Construct empty String")
    {
		String str;
		REQUIRE(str.size() == 0);
    }

    SECTION("Construct String from std::string")
    {
		std::string rawStr("abcdef");
		String str(rawStr);
		auto rawStrIt = rawStr.begin();
		for (auto& ch : str) {
			REQUIRE(ch.symbol == static_cast<uint16_t>(*rawStrIt));
			++rawStrIt;
		}
		REQUIRE(str.toString() == rawStr);
    }

	SECTION("Construct String from std::wstring")
	{
		std::wstring rawStr(L"abcdef");
		String str(rawStr);
		auto rawStrIt = rawStr.begin();
        for (auto& ch : str) {
			REQUIRE(ch.symbol == static_cast<uint16_t>(*rawStrIt));
			++rawStrIt;
        }
		REQUIRE(str.toWString() == rawStr);
	}

    SECTION("Construct String from const char*")
    {
		const char* rawStr = "abcdef";
		String str(rawStr);
		size_t i = 0;
		for (auto& ch : str) {
			REQUIRE(ch.symbol == static_cast<uint16_t>(rawStr[i]));
			++i;
		}
		REQUIRE(str.toString() == rawStr);
    }
}