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
        REQUIRE(str.toAnsiString() == rawStr);
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
        REQUIRE(str.toWideString() == rawStr);
    }

    SECTION("Construct String from const char*")
    {
        const char* rawStr = "abcdef";
        String str(rawStr);
        size_t i = 0;
        REQUIRE(str.size() == std::strlen(rawStr));
        for (auto& ch : str) {
            REQUIRE(ch.symbol == static_cast<uint16_t>(rawStr[i]));
            ++i;
        }
        REQUIRE(str.toAnsiString() == rawStr);
    }

    SECTION("Construct String from const wchar_t*")
    {
        const wchar_t* rawStr = L"abcdef";
        String str(rawStr);
        size_t i = 0;
        REQUIRE(str.size() == std::wcslen(rawStr));
        for (auto& ch : str) {
            REQUIRE(ch.symbol == static_cast<uint16_t>(rawStr[i]));
            ++i;
        }
        REQUIRE(str.toWideString() == rawStr);
    }

    SECTION("Construct String from Char")
    {
        Char ch = 'A';
        String str(ch);
        REQUIRE(str.size() == 1);
        REQUIRE(str[0] == ch);
    }

    SECTION("Construct String from uint32_t")
    {
        uint32_t ch = 'A';
        String str(ch);
        REQUIRE(str.size() == 1);
        REQUIRE(str[0] == ch);
    }

    SECTION("Operations")
    {
        SECTION("String::toCursesString()")
        {
            String str("abcdefg");

            SECTION("Nonconst")
            {
                uint32_t* rawStr = str.toCursesString();
                size_t i = 0;
                for (auto& ch : str) {
                    REQUIRE(ch.toCursesChar() == rawStr[i]);
                    ++i;
                }
            }

            SECTION("Const")
            {
                const uint32_t* rawStr = str.toCursesString();
                size_t i = 0;
                for (auto& ch : str) {
                    REQUIRE(ch.toCursesChar() == rawStr[i]);
                    ++i;
                }
            }
        }

        SECTION("String::toAnsiString()")
        {
            String str("abcdefg");
            std::string ansiString = str.toAnsiString();
            REQUIRE(ansiString == "abcdefg");
        }

        SECTION("String::toWideString()")
        {
            String str("abcdefg");
            std::wstring wideString = str.toWideString();
            REQUIRE(wideString == L"abcdefg");
        }

        SECTION("String::find(...)")
        {
            SECTION("Existed substring")
            {
                String str("abcdefghijklmnop");
                String substring("ijklm");

                REQUIRE(str.find(substring, -5) == String::InvalidPosition);
                REQUIRE(str.find(substring) == 8);
                REQUIRE(str.find(substring, 8) == 8);
                REQUIRE(str.find(substring, 50) == String::InvalidPosition);
            }

            SECTION("Nonexisted substring")
            {
                String str("abcdefghijklmnop");
                String substring("hello");

                REQUIRE(str.find(substring, -5) == String::InvalidPosition);
                REQUIRE(str.find(substring) == String::InvalidPosition);
                REQUIRE(str.find(substring, 50) == String::InvalidPosition);
            }
        }

        SECTION("String::isEmpty()")
        {
            String str;
            REQUIRE(str.isEmpty() == true);
            str = "abcd";
            REQUIRE(str.isEmpty() == false);
            str = "";
            REQUIRE(str.isEmpty() == true);
        }

        SECTION("String::clear()")
        {
            String str("abcdefghij");
            str.clear();
            REQUIRE(str.isEmpty() == true);
        }

        SECTION("String::insert(...)")
        {
            String str("abcdefg");
            std::string correctStr("abcd_HELLO_efg");
            SECTION("Position is valid")
            {
                str.insert(4, "_HELLO_");
                REQUIRE(str.toAnsiString() == correctStr);
            }
            SECTION("Position is invalid")
            {
                bool isExcepted = false;
                try {
                    str.insert(50, "_HELLO_");
                }
                catch (...) {
                    isExcepted = true;
                }

                REQUIRE(isExcepted == true);
            }
        }

        SECTION("String::erase(...)")
        {
            SECTION("Position is valid")
            {
                String str1("abcdefg");
                str1.erase(3, 3);
                REQUIRE(str1.toAnsiString() == "abcg");

                String str2("abcdefg");
                str2.erase(3, -5);
                REQUIRE(str2.toAnsiString() == "abc");

                String str3("abcdefg");
                str3.erase(3, String::InvalidPosition);
                REQUIRE(str3.toAnsiString() == "abc");
            }

            SECTION("Position is invalid")
            {
                String str("abcdefg");
                bool isExcepted = false;
                try {
                    str.erase(50);
                }
                catch (...) {
                    isExcepted = true;
                }

                REQUIRE(isExcepted == true);
            }
        }

        SECTION("String::replace(...)")
        {
            SECTION("Replace by position and length")
            {
                SECTION("Position is valid")
                {
                    String replaceWith("_HELLO_");

                    String str1("abcdefg");
                    str1.replace(3, 3, replaceWith);
                    REQUIRE(str1.toAnsiString() == "abc_HELLO_g");

                    String str2("abcdefg");
                    str2.replace(3, 50, replaceWith);
                    REQUIRE(str2.toAnsiString() == "abc_HELLO_");

                    String str3("abcdefg");
                    str3.replace(3, String::InvalidPosition, replaceWith);
                    REQUIRE(str3.toAnsiString() == "abc_HELLO_");
                }

                SECTION("Position is invalid")
                {
                    String str("abcdefg");
                    bool isExcepted = false;
                    try {
                        str.replace(50, 3, String());
                    }
                    catch (...) {
                        isExcepted = true;
                    }

                    REQUIRE(isExcepted == true);
                }
            }

            SECTION("Replace by search for string")
            {
                SECTION("Existed substring")
                {
                    String str("abcdefghij");
                    String replaceWith("_HELLO_");
                    String searchFor("fgh");

                    str.replace(searchFor, replaceWith);
                    REQUIRE(str.toAnsiString() == "abcde_HELLO_ij");
                }

                SECTION("Several existed substring")
                {

                    String str("abcABCqwertyABCaABC12ABC");
                    String replaceWith("_HELLO_");
                    String searchFor("ABC");

                    str.replace(searchFor, replaceWith);
                    REQUIRE(str.toAnsiString() == "abc_HELLO_qwerty_HELLO_a_HELLO_12_HELLO_");
                }

                SECTION("Nonexisted substring")
                {
                    String str("abcdefghij");
                    String replaceWith("_HELLO_");
                    String searchFor("hello");

                    str.replace(searchFor, replaceWith);
                    REQUIRE(str.toAnsiString() == "abcdefghij");
                }
            }
        }

        SECTION("String::substring(...)")
        {
            SECTION("Position is valid")
            {
                String str("abcdefghij");

                String substring1 = str.substring(3, 3);
                REQUIRE(substring1.toAnsiString() == "def");

                String substring2 = str.substring(3, -5);
                REQUIRE(substring2.toAnsiString() == "defghij");

                String substring3 = str.substring(3, String::InvalidPosition);
                REQUIRE(substring3.toAnsiString() == "defghij");
            }

            SECTION("Position is invalid")
            {
                String str("abcdefg");
                bool isExcepted = false;
                try {
                    str.substring(50, 3);
                }
                catch (...) {
                    isExcepted = true;
                }

                REQUIRE(isExcepted == true);
            }
        }
    }

    SECTION("Operators")
    {
        SECTION("")
        {
            
        }
    }
}