#pragma once

#include <string>

#include <XCurses/Text/Char.h>

namespace xcur {
class String
{
public:
    /**
     * \brief std::vector<Char>::iterator alias
     */
    using Iterator = std::basic_string<Char>::iterator;

	/**
	 * \brief std::vector<Char>::const_iterator alias
	 */
    using ConstIterator = std::basic_string<Char>::const_iterator;
   
    /**
     * \brief String constructor. Construct String from std::string
     * \param str String
     */
    String(const std::string& str);

    /**
     * \brief String constructor. Construct String from std::wstring
     * \param str Wide string
     */
    String(const std::wstring& str);

	/**
	 * \brief String constructor. Construct String from wchar_t*
	 * \param str String
	 */
	String(const char* str);

	/**
	 * \brief String constructor. Construct String from wchar_t*
	 * \param str Wide string
	 */
	String(const wchar_t* str);

	/**
	 * \brief String constructor. Construct String from Char
	 * \param ch Char
	 */
	String(const Char& ch);

	/**
	 * \brief String constructor. Construct String from uint32_t.
	 * Character may be ansi char, wide char or curses char
	 * \param ch Char
	 */
	String(uint32_t ch);

    /**
	 * \brief String constructor. Construct String from basic_string<Char>
	 * \param data Vector of Char's
	 */
	String(const std::basic_string<Char>& data);

    /**
     * \brief Default String constructor
     */
    String() = default;

    /**
     * \brief Copy String constructor
     */
    String(const String&) = default;

    /**
     * \brief Move String constructor
     */
    String(String&&) = default;

    /**
     * \brief Overload of [] operator.
     * Get char by index. Can out of size
     * \param index Index
     * \return Reference to \a char
     */
    Char& operator [](size_t index);

	/**
	 * \brief Overload of the binary + operator.
     * This operator returns the sum of two strings.
	 * \param right Right operand
	 * \return Result of \a left + \a right
	 */
	String operator +(const String& right) const;

	/**
	 * \brief Overload of the binary + operator.
     * This operator returns the sum of two strings.
	 * \param right Right operand
	 * \return Result of \a left + \a right
	 */
	String operator +(const std::string& right) const;

	/**
	 * \brief Overload of the binary + operator.
     * This operator returns the sum of two strings.
	 * \param right Right operand
	 * \return Result of \a left + \a right
	 */
	String operator +(const std::wstring& right) const;

	/**
	 * \brief Overload of the binary + operator.
     * This operator returns the sum of two strings.
	 * \param right Right operand
	 * \return Result of \a left + \a right
	 */
	String operator +(const char* right) const;

	/**
	 * \brief Overload of the binary + operator.
     * This operator returns the sum of two strings.
	 * \param right Right operand
	 * \return Result of \a left + \a right
	 */
	String operator +(const wchar_t* right) const;

	/**
	 * \brief Overload of the binary + operator.
	 * This operator returns the sum of string and char.
	 * \param right Right operand
	 * \return Result of \a left + \a right
	 */
	String operator +(const Char& right) const;

	/**
	 * \brief Overload of the binary + operator.
     * This operator returns the sum of string and char.
	 * Character may be ansi char, wide char or curses char
	 * \param right Right operand
	 * \return Result of \a left + \a right
	 */
	String operator +(uint32_t right);

    /**
     * \brief Overload of the binary += operator.
     * This operator inserts String in back of this String
     * \param right Right operand
     * \return Reference to \a this
     */
    String& operator +=(const String& right);

    /**
     * \brief Overload of the binary += operator.
     * This operator inserts Char in back of this String
     * \param right Right operand
     * \return Reference to \a this
     */
    String& operator +=(const Char& right);

    /**
     * \brief Overload of the binary += operator.
     * This operator inserts std::string in back of this String
     * \param right Right operand
     * \return Reference to \a this
     */
    String& operator +=(const std::string& right);

    /**
     * \brief Overload of the binary += operator.
     * This operator inserts std::wstring in back of this String
     * \param right Right operand
     * \return Reference to \a this
     */
    String& operator +=(const std::wstring& right);

	/**
	 * \brief Overload of the binary += operator.
	 * This operator inserts ansi string in back of this String
	 * \param right Right operand
	 * \return Reference to \a this
	 */
	String& operator +=(const char* right);

	/**
	 * \brief Overload of the binary += operator.
	 * This operator inserts wide string in back of this String
	 * \param right Right operand
	 * \return Reference to \a this
	 */
	String& operator +=(const wchar_t* right);

    /**
     * \brief Overload of the binary += operator.
     * This operator inserts char in back of this String.
	 * Character may be ansi char, wide char or curses char
     * \param right Right operand
     * \return Reference to \a this
     */
    String& operator +=(uint32_t right);

	/**
	 * \brief Overload of the binary = operator.
	 * \param right Right operand
	 * \return Reference to \a this
	 */
	String& operator =(const Char& right);

	/**
	 * \brief Overload of the binary = operator.
	 * \param right Right operand
	 * \return Reference to \a this
	 */
	String& operator =(const std::string& right);

	/**
	 * \brief Overload of the binary = operator.
	 * \param right Right operand
	 * \return Reference to \a this
	 */
	String& operator =(const std::wstring& right);

	/**
	 * \brief Overload of the binary = operator.
	 * \param right Right operand
	 * \return Reference to \a this
	 */
	String& operator =(const char* right);

	/**
	 * \brief Overload of the binary = operator.
	 * \param right Right operand
	 * \return Reference to \a this
	 */
	String& operator =(const wchar_t* right);

	/**
	 * \brief Overload of the binary = operator.
	 * \param right Right operand
	 * \return Reference to \a this
	 */
	String& operator =(uint32_t right);

	/**
	 * \brief Overload of the == operator
	 * This operator compares two Strings and check if they are equal.
	 * \param right Right operand
	 * \return True if strings are equal, false if they are different
	 */
	bool operator ==(const String& right) const;

	/**
	 * \brief Overload of the == operator
	 * This operator compares String and std::string and check if they are equal.
	 * \param right Right operand
	 * \return True if strings are equal, false if they are different
	 */
	bool operator ==(const std::string& right) const;

	/**
	 * \brief Overload of the == operator
	 * This operator compares String and std::wstring and check if they are equal.
	 * \param right Right operand
	 * \return True if strings are equal, false if they are different
	 */
	bool operator ==(const std::wstring& right) const;

	/**
	 * \brief Overload of the == operator
	 * This operator compares String and ansi string and check if they are equal.
	 * \param right Right operand
	 * \return True if strings are equal, false if they are different
	 */
	bool operator ==(const char* right) const;

	/**
	 * \brief Overload of the == operator
	 * This operator compares String and wide string and check if they are equal.
	 * \param right Right operand
	 * \return True if strings are equal, false if they are different
	 */
	bool operator ==(const wchar_t* right) const;

	/**
	 * \brief Overload of the != operator
	 * This operator compares two Strings and check if they are equal.
	 * \param right Right operand
	 * \return True if strings are different, false if they are equal
	 */
	bool operator !=(const String& right) const;

	/**
	 * \brief Overload of the != operator
	 * This operator compares String and std::string and check if they are equal.
	 * \param right Right operand
	 * \return True if strings are different, false if they are equal
	 */
	bool operator !=(const std::string& right) const;

	/**
	 * \brief Overload of the != operator
	 * This operator compares String and std::wstring and check if they are equal.
	 * \param right Right operand
	 * \return True if strings are different, false if they are equal
	 */
	bool operator !=(const std::wstring& right) const;

	/**
	 * \brief Overload of the != operator
	 * This operator compares String and ansi string and check if they are equal.
	 * \param right Right operand
	 * \return True if strings are different, false if they are equal
	 */
	bool operator !=(const char* right) const;

	/**
	 * \brief Overload of the != operator
	 * This operator compares String and wide string and check if they are equal.
	 * \param right Right operand
	 * \return True if strings are different, false if they are equal
	 */
	bool operator !=(const wchar_t* right) const;

    /**
     * \brief Default copy assignment operator
     * \return Reference to \a this
     */
    String& operator =(const String&) = default;

    /**
     * \brief Default move assignment operator
     * \return Reference to \a this
     */
    String& operator =(String&&) = default;

    /**
     * \brief String destructor
     */
    ~String() = default;

    /**
     * \brief Convert String to chtype* (it is equal uint32_t*) 
     * \return uint32_t*
     */
    uint32_t* toCursesStr();

    /**
	 * \brief Convert String to std::string
	 * \return std::string
	 */
	std::string toString() const;

	/**
	 * \brief Convert String to std::wstring
	 * \return std::wstring
	 */
	std::wstring toWString() const;

    /**
     * \brief Get begin iterator
     * \return Iterator
     */
    Iterator begin();

    /**
     * \brief Get begin const iterator
     * \return Const iterator
     */
    ConstIterator begin() const;

    /**
     * \brief Get end iterator
     * \return Iterator
     */
    Iterator end();

    /**
     * \brief Get end const iterator
     * \return Const iterator
     */
    ConstIterator end() const;

    /**
     * \brief Get size (length) of string
     * \return Size
     */
    size_t size() const;

    /**
	 * \brief Get raw data
	 * \return Reference to data
	 */
	std::basic_string<Char>& getData();

private:
    /**
     * \brief Data of string
     */
    std::basic_string<Char> m_data;
};
}
