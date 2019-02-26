#pragma once

#include <vector>
#include <string>

#include <XCurses/Char.h>

namespace xcur {
class String
{
public:
	using Iterator = std::vector<Char>::iterator;

	using ConstIterator = std::vector<Char>::const_iterator;
   
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
	Char& operator [](size_t index) const;

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
	 * This operator inserts char in back of this String
	 * \param right Right operand
	 * \return Reference to \a this
	 */
	String& operator +=(const char& right);

	/**
	 * \brief Overload of the binary += operator.
	 * This operator inserts wchar in back of this String
	 * \param right Right operand
	 * \return Reference to \a this
	 */
	String& operator +=(const wchar_t& right);

	/**
	 * \brief Overload of the binary += operator.
	 * This operator inserts uint16_t (wchar) in back of this String
	 * \param right Right operand
	 * \return Reference to \a this
	 */
	String& operator +=(const uint16_t& right);

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
	 * \brief Get string for curses
	 * \return Curses string
	 */
	uint32_t* toCursesStr();

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

private:
    /**
	 * \brief Data of string
	 */
	std::vector<Char> m_data;
};
}
