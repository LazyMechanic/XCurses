#include <XCurses/Text/String.h>
#include <utility>

namespace xcur {
String::String(const std::string& str) :
    m_data(str.begin(), str.end())
{
}

String::String(const std::wstring& str) :
	m_data(str.begin(), str.end())
{
}

String::String(const char* str) :
    String(std::string(str))
{
}

String::String(const wchar_t* str) :
	String(std::wstring(str))
{
}

String::String(const Char& ch) :
	m_data(1, ch)
{
}

String::String(uint32_t ch) :
	String(Char(ch))
{
}

String::String(const std::basic_string<Char>& data) :
    m_data(data)
{
}

Char& String::operator[](size_t index)
{
    return m_data[index];
}

String String::operator+(const String& right) const
{
	return String(m_data + right.m_data);
}

String String::operator+(const std::string& right) const
{
	return *this + String(right);
}

String String::operator+(const std::wstring& right) const
{
	return *this + String(right);
}

String String::operator+(const char* right) const
{
	return *this + String(right);
}

String String::operator+(const wchar_t* right) const
{
	return *this + String(right);
}

String String::operator+(const Char& right) const
{
	return String(m_data + right);
}

String String::operator+(uint32_t right)
{
	return *this + Char(right);
}

String& String::operator+=(const String& right)
{
	return *this = *this + right;
}

String& String::operator+=(const Char& right)
{
	return *this = *this + right;
}

String& String::operator+=(const std::string& right)
{
	return *this = *this + right;
}

String& String::operator+=(const std::wstring& right)
{
	return *this = *this + right;
}

String& String::operator+=(const char* right)
{
	return *this = *this + right;
}

String& String::operator+=(const wchar_t* right)
{
	return *this = *this + right;
}

String& String::operator+=(uint32_t right)
{
	return *this = *this + right;
}

String& String::operator=(const Char& right)
{
	m_data = right;
    return *this;
}

String& String::operator=(const std::string& right)
{
	return *this = String(right);
}

String& String::operator=(const std::wstring& right)
{
	return *this = String(right);
}

String& String::operator=(const char* right)
{
	return *this = String(right);
}

String& String::operator=(const wchar_t* right)
{
	return *this = String(right);
}

String& String::operator=(uint32_t right)
{
	return *this = Char(right);
}

bool String::operator==(const String& right) const
{
	return m_data == right.m_data;
}

bool String::operator==(const std::string& right) const
{
	return toString() == right;
}

bool String::operator==(const std::wstring& right) const
{
	return toWString() == right;
}

bool String::operator==(const char* right) const
{
	return toString() == right;
}

bool String::operator==(const wchar_t* right) const
{
	return toWString() == right;
}

bool String::operator!=(const String& right) const
{
	return !(*this == right);
}

bool String::operator!=(const std::string& right) const
{
	return !(*this == right);
}

bool String::operator!=(const std::wstring& right) const
{
	return !(*this == right);
}

bool String::operator!=(const char* right) const
{
	return !(*this == right);
}

bool String::operator!=(const wchar_t* right) const
{
	return !(*this == right);
}

uint32_t* String::toCursesStr()
{
    return reinterpret_cast<uint32_t*>(m_data.data());
}

std::string String::toString() const
{
	std::string result(m_data.size(), '\0');
	auto strIt = m_data.begin();
	for (auto& ch : result) {
		ch = static_cast<uint8_t>(strIt->toCursesChar());
		++strIt;
	}
	return result;
}

std::wstring String::toWString() const
{
	std::wstring result(m_data.size(), L'\0');
	auto strIt = m_data.begin();
	for (auto& ch : result) {
		ch = static_cast<uint16_t>(strIt->toCursesChar());
		++strIt;
	}
	return result;
}

String::Iterator String::begin()
{
    return m_data.begin();
}

String::ConstIterator String::begin() const
{
    return m_data.begin();
}

String::Iterator String::end()
{
    return m_data.end();
}

String::ConstIterator String::end() const
{
    return m_data.end();
}

size_t String::size() const
{
    return m_data.size();
}

std::basic_string<Char>& String::getData()
{
	return m_data;
}
}
