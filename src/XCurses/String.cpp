#include <XCurses/String.h>

namespace xcur {
String::String(const std::string& str) :
    m_data(str.begin(), str.end() + 1)
{
}

String::String(const std::wstring& str) :
	m_data(str.begin(), str.end() + 1)
{
}

Char& String::operator[](size_t index) const
{
	return m_data.at[index];
}

String& String::operator+=(const String& right)
{
	m_data.insert(m_data.end(), right.begin(), right.end());
	return *this;
}

String& String::operator+=(const Char& right)
{
	if (right.getChar() != 0) {
		m_data.push_back(right);
	}
	return *this;
}

String& String::operator+=(const std::string& right)
{
	m_data.insert(m_data.end(), right.begin(), right.end() + 1);
	return *this;
}

String& String::operator+=(const std::wstring& right)
{
	m_data.insert(m_data.end(), right.begin(), right.end() + 1);
	return *this;
}

String& String::operator+=(const char& right)
{
	if (right != 0) {
		m_data.emplace_back(right);
	}
	return *this;
}

String& String::operator+=(const wchar_t& right)
{
	if (right != 0) {
		m_data.emplace_back(right);
	}
	return *this;
}

String& String::operator+=(const uint16_t& right)
{
	if (right != 0) {
		m_data.emplace_back(right);
	}
	return *this;
}

uint32_t* String::toCursesStr()
{
	return reinterpret_cast<uint32_t*>(m_data.data());
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
}
