#include <XCurses/Text/String.h>
#include <utility>

namespace xcur {
const size_t String::InvalidPosition = std::basic_string<Char>::npos;

String::String(const std::string& str) :
    m_string(str.begin(), str.end())
{
}

String::String(const std::wstring& str) :
	m_string(str.begin(), str.end())
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
	m_string(1, ch)
{
}

String::String(uint32_t ch) :
	String(Char(ch))
{
}

String::String(const std::basic_string<Char>& data) :
    m_string(data)
{
}

Char& String::operator[](size_t index)
{
    return m_string[index];
}

String String::operator+(const String& right) const
{
	return String(m_string + right.m_string);
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
	return String(m_string + right);
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

String& String::operator=(const Char& right)
{
	m_string = right;
	return *this;
}

String& String::operator=(uint32_t right)
{
	return *this = Char(right);
}

bool String::operator==(const String& right) const
{
	return m_string == right.m_string;
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
    return reinterpret_cast<uint32_t*>(m_string.data());
}

std::string String::toString() const
{
	std::string result(m_string.size(), '\0');
	auto strIt = m_string.begin();
	for (auto& ch : result) {
		ch = static_cast<uint8_t>(strIt->toCursesChar());
		++strIt;
	}
	return result;
}

std::wstring String::toWString() const
{
	std::wstring result(m_string.size(), L'\0');
	auto strIt = m_string.begin();
	for (auto& ch : result) {
		ch = static_cast<uint16_t>(strIt->toCursesChar());
		++strIt;
	}
	return result;
}

String::Iterator String::begin()
{
    return m_string.begin();
}

String::ConstIterator String::begin() const
{
    return m_string.begin();
}

String::ConstIterator String::cbegin() const
{
	return m_string.cbegin();
}

String::Iterator String::end()
{
    return m_string.end();
}

String::ConstIterator String::end() const
{
    return m_string.end();
}

String::ConstIterator String::cend() const
{
	return m_string.cend();
}

String::ReverseIterator String::rbegin()
{
	return m_string.rbegin();
}

String::ConstReverseIterator String::rbegin() const
{
	return m_string.rbegin();
}

String::ConstReverseIterator String::crbegin() const
{
	return m_string.crbegin();
}

String::ReverseIterator String::rend()
{
	return m_string.rend();
}

String::ConstReverseIterator String::rend() const
{
	return m_string.rend();
}

String::ConstReverseIterator String::crend() const
{
	return m_string.crend();
}

size_t String::find(const String& str, size_t startPosition) const
{
	return m_string.find(str.getBasicString(), startPosition);
}

bool String::isEmpty() const
{
	return m_string.empty();
}

void String::clear()
{
	m_string.clear();
}

void String::insert(size_t position, const String& str)
{
	m_string.insert(position, str.getBasicString());
}

void String::erase(size_t position, size_t count)
{
	m_string.erase(position, count);
}

void String::replace(size_t position, size_t length, const String& replaceWith)
{
	m_string.replace(position, length, replaceWith.getBasicString());
}

void String::replace(const String& searchFor, const String& replaceWith)
{
	std::size_t step = replaceWith.size();
	std::size_t len = searchFor.size();
	std::size_t pos = find(searchFor);

	// Replace each occurrence of search
	while (pos != InvalidPosition)
	{
		replace(pos, len, replaceWith);
		pos = find(searchFor, pos + step);
	}
}

String String::substring(size_t position, size_t length) const
{
	return m_string.substr(position, length);
}

size_t String::size() const
{
    return m_string.size();
}

const Char* String::data() const
{
	return m_string.data();
}

std::basic_string<Char>& String::getBasicString()
{
	return m_string;
}

const std::basic_string<Char>& String::getBasicString() const
{
	return m_string;
}
}
