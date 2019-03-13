#pragma once

#include <string>

#include <XCurses/Text/Char.h>

namespace xcur {
/**
 * \brief Class for contain curses chars and operations over them.
 */
class String
{
public:
    /**
     * \brief Represents an invalid position in the string
     */
    static const size_t InvalidPosition;

    /**
     * \brief std::vector<Char>::iterator alias
     */
    using Iterator = std::basic_string<Char>::iterator;

    /**
     * \brief std::vector<Char>::const_iterator alias
     */
    using ConstIterator = std::basic_string<Char>::const_iterator;

    /**
     * \brief std::vector<Char>::reverse_iterator alias
     */
    using ReverseIterator = std::basic_string<Char>::reverse_iterator;

    /**
     * \brief std::vector<Char>::const_reverse_iterator alias
     */
    using ConstReverseIterator = std::basic_string<Char>::const_reverse_iterator;
   
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
     * \brief Overload of [] operator.
     * Get char by index. Can out of size
     * \param index Index
     * \return Const reference to \a char
     */
    const Char& operator [](size_t index) const;

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
    String operator +(uint32_t right) const;

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
    String& operator =(const String& right);

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
    String& operator =(const Char& right);

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
     * \brief Overload of the > operator
     * This operator compares two strings and check if symbol values \a this more than
     * symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is more than symbol values of \a right,
     * false otherwise
     */
    bool operator >(const String& right) const;

    /**
     * \brief Overload of the > operator
     * This operator compares String and std::string and check if symbol values \a this 
     * more than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is more than symbol values of \a right,
     * false otherwise
     */
    bool operator >(const std::string& right) const;

    /**
     * \brief Overload of the > operator
     * This operator compares String and std::wstring and check if symbol values \a this
     * more than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is more than symbol values of \a right,
     * false otherwise
     */
    bool operator >(const std::wstring& right) const;

    /**
     * \brief Overload of the > operator
     * This operator compares String and const char* and check if symbol values \a this 
     * more than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is more than symbol values of \a right,
     * false otherwise
     */
    bool operator >(const char* right) const;

    /**
     * \brief Overload of the > operator
     * This operator compares String and const wchar_t* and check if symbol values \a this
     * more than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is more than symbol values of \a right,
     * false otherwise
     */
    bool operator >(const wchar_t* right) const;

    /**
     * \brief Overload of the < operator
     * This operator compares two strings and check if symbol values \a this less than
     * symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is less than symbol values of \a right,
     * false otherwise
     */
    bool operator <(const String& right) const;

    /**
     * \brief Overload of the < operator
     * This operator compares String and std::string and check if symbol values \a this
     * less than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is less than symbol values of \a right,
     * false otherwise
     */
    bool operator <(const std::string& right) const;

    /**
     * \brief Overload of the < operator
     * This operator compares String and std::wstring and check if symbol values \a this
     * less than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is less than symbol values of \a right,
     * false otherwise
     */
    bool operator <(const std::wstring& right) const;

    /**
     * \brief Overload of the < operator
     * This operator compares String and const char* and check if symbol values \a this
     * less than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is less than symbol values of \a right,
     * false otherwise
     */
    bool operator <(const char* right) const;

    /**
     * \brief Overload of the < operator
     * This operator compares String and const wchar_t* and check if symbol values \a this
     * less than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is less than symbol values of \a right,
     * false otherwise
     */
    bool operator <(const wchar_t* right) const;

    /**
     * \brief Overload of the >= operator
     * This operator compares two strings and check if symbol values \a this more or equal than
     * symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is more or equal than symbol values of \a right,
     * false otherwise
     */
    bool operator >=(const String& right) const;

    /**
     * \brief Overload of the >= operator
     * This operator compares String and std::string and check if symbol values \a this
     * more or equal than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is more or equal than symbol values of \a right,
     * false otherwise
     */
    bool operator >=(const std::string& right) const;

    /**
     * \brief Overload of the >= operator
     * This operator compares String and std::wstring and check if symbol values \a this
     * more or equal than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is more or equal than symbol values of \a right,
     * false otherwise
     */
    bool operator >=(const std::wstring& right) const;

    /**
     * \brief Overload of the >= operator
     * This operator compares String and const char* and check if symbol values \a this
     * more or equal than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is more or equal than symbol values of \a right,
     * false otherwise
     */
    bool operator >=(const char* right) const;

    /**
     * \brief Overload of the >= operator
     * This operator compares String and const wchar_t* and check if symbol values \a this
     * more or equal than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is more or equal than symbol values of \a right,
     * false otherwise
     */
    bool operator >=(const wchar_t* right) const;

    /**
     * \brief Overload of the <= operator
     * This operator compares two strings and check if symbol values \a this less or equal than
     * symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is less or equal than symbol values of \a right,
     * false otherwise
     */
    bool operator <=(const String& right) const;

    /**
     * \brief Overload of the <= operator
     * This operator compares String and std::string and check if symbol values \a this
     * less or equal than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is less or equal than symbol values of \a right,
     * false otherwise
     */
    bool operator <=(const std::string& right) const;

    /**
     * \brief Overload of the <= operator
     * This operator compares String and std::wstring and check if symbol values \a this
     * less or equal than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is less or equal than symbol values of \a right,
     * false otherwise
     */
    bool operator <=(const std::wstring& right) const;

    /**
     * \brief Overload of the <= operator
     * This operator compares String and const char* and check if symbol values \a this
     * less or equal than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is less or equal than symbol values of \a right,
     * false otherwise
     */
    bool operator <=(const char* right) const;

    /**
     * \brief Overload of the <= operator
     * This operator compares String and const wchar_t* and check if symbol values \a this
     * less or equal than symbol values of \a right
     * \param right Right operand
     * \return True if symbol values of \a this is less or equal than symbol values of \a right,
     * false otherwise
     */
    bool operator <=(const wchar_t* right) const;

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
     * \brief Check if \a left and \a right is equal including color pair id and attribute
     * \param left Left operand
     * \param right Left operand
     * \return True if color pair id, attribute and symbol are equal in all characters in
     * strings, false if they different
     */
    static bool isFullEqual(const String& left, const String& right);

    /**
     * \brief Convert String to std::string (ansi string).
     * Characters that do not fit in the target encoding are
     * discarded from the returned string.
     * \return Ansi string
     */
    std::string toAnsiString() const;

    /**
     * \brief Convert String to std::wstring (wide string).
     * Characters that do not fit in the target encoding are
     * discarded from the returned string.
     * \return Wide string
     */
    std::wstring toWideString() const;

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
     * \brief Get begin const iterator
     * \return Const iterator
     */
    ConstIterator cbegin() const;

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
     * \brief Get end const iterator
     * \return Const iterator
     */
    ConstIterator cend() const;

    /**
     * \brief Get begin reverse iterator
     * \return Iterator
     */
    ReverseIterator rbegin();

    /**
     * \brief Get begin const reverse iterator
     * \return Const iterator
     */
    ConstReverseIterator rbegin() const;

    /**
     * \brief Get begin const reverse iterator
     * \return Const iterator
     */
    ConstReverseIterator crbegin() const;

    /**
     * \brief Get end reverse iterator
     * \return Iterator
     */
    ReverseIterator rend();

    /**
     * \brief Get end const reverse iterator
     * \return Const iterator
     */
    ConstReverseIterator rend() const;

    /**
     * \brief Get end const reverse iterator
     * \return Const iterator
     */
    ConstReverseIterator crend() const;

    /**
     * \brief Find substring into the string
     * \param str String which we need to find
     * \param startPosition Starting position for search
     * \return Position of substring
     */
    size_t find(const String& str, size_t startPosition = 0) const;

    /**
     * \brief Check whether the string is empty or not
     * \return True if string is empty, false if it is not
     */
    bool isEmpty() const;

    /**
     * \brief Clear string
     */
    void clear();

    /**
     * \brief Insert string into the string
     * \param position Starting position for insert
     * \param str String which we need to insert
     */
    void insert(size_t position, const String& str);

    /**
     * \brief Erase one or more character from string
     * \param position Starting position for erase
     * \param count Count of characters
     */
    void erase(size_t position, size_t count = 1);

    /**
     * \brief Replace a substring with another string
     * \param position Position of the first character to be replaced
     * \param length Length of the substring to be replaced
     * \param replaceWith String that replaces the given substring
     */
    void replace(size_t position, size_t length, const String& replaceWith);

    /**
     * \brief Replace a substring with another string.
     * This function replaces all occurrences of \a searchFor in this string
     * with the string \a replaceWith.
     * \param searchFor The value being searched for
     * \param replaceWith The value that replaces found \a searchFor values
     */
    void replace(const String& searchFor, const String& replaceWith);

    /**
     * \brief Return a part of the string
     * \param position Position of the first character
     * \param length Number of characters to include in the substring (if
     * the string is shorter, as many characters as possible are included). 
     * \a InvalidPos can be used to include all characters until the end of the string.
     * \return String object containing a substring of this object
     */
    String substring(size_t position, size_t length = InvalidPosition) const;

    /**
     * \brief Get size (length) of string
     * \return Size
     */
    size_t size() const;

    /**
     * \brief Get ptr to data of string
     * \return Ptr to data
     */
    Char* data();

    /**
     * \brief Get ptr to data of string
     * \return Const ptr to data
     */
    const Char* data() const;

    /**
     * \brief Get basic_string which is base of xcur::String
     * \return Reference to basic_string
     */
    std::basic_string<Char>& getBasicString();

    /**
     * \brief Get basic_string which is base of xcur::String
     * \return Const reference to basic_string
     */
    const std::basic_string<Char>& getBasicString() const;

private:
    /**
     * \brief Internal string
     */
    std::basic_string<Char> m_string;
};
}
