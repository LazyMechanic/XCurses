#pragma once

#include <cstdint>

namespace xcur {
template <typename T>
class Vector2
{
public:
	/**
	 * \brief Default Vector2 constructor. Construct vector with 0 components
	 */
	Vector2();

	/**
	 * \brief Vector2 constructor. Construct vector with specific components
	 * \param x X component
	 * \param y Y component
	 */
	Vector2(T x, T y);

	/**
	 * \brief Vector2 construct. Construct vector from another vector
	 * \tparam From Another vector type
	 * \param vector Another vector
	 */
	template<typename From>
	explicit Vector2(const Vector2<From>& vector);

	/**
	 * \brief Copy Vector2 constructor
	 */
	Vector2(const Vector2<T>&) = default;

	/**
	 * \brief Move Vector2 constructor
	 */
	Vector2(Vector2<T>&&) = default;

	/**
	 * \brief Default copy assignment operator
	 * \return Reference to \a this
	 */
	Vector2& operator =(const Vector2<T>&) = default;

	/**
	 * \brief Default move assignment operator
	 * \return Reference to \a this
	 */
	Vector2& operator =(Vector2<T>&&) = default;

	/**
	 * \brief Overload of the binary + operator.
	 * This operator returns the component-wise sum of vector and value
	 * \param right Right operand
	 * \return Result of \a left + \a right
	 */
	Vector2 operator+(const T& right);

	/**
	 * \brief Overload of the binary - operator.
	 * This operator returns the component-wise subtraction of vector and value
	 * \param right Right operand
	 * \return Result of \a left - \a right
	 */
	Vector2 operator-(const T& right);

	/**
	 * \brief Overload of the binary * operator.
	 * This operator returns the component-wise multiplication of vector and value
	 * \param right Right operand
	 * \return Result of \a left * \a right
	 */
	Vector2 operator*(const T& right);

	/**
	 * \brief Overload of the binary * operator.
	 * This operator returns the component-wise division of vector and value
	 * \param right Right operand
	 * \return Result of \a left * \a right
	 */
	Vector2 operator/(const T& right);

	/**
	 * \brief Overload of the binary + operator.
	 * This operator returns the component-wise sum of two vectors
	 * \param right Right operand
	 * \return Result of \a left + \a right
	 */
	Vector2 operator+(const Vector2& right);

	/**
	 * \brief Overload of the binary - operator.
	 * This operator returns the component-wise subtraction of two vectors
	 * \param right Right operand
	 * \return Result of \a left - \a right
	 */
	Vector2 operator-(const Vector2& right);

	/**
	 * \brief Overload of the binary * operator.
	 * This operator returns the component-wise multiplication of two vectors
	 * \param right Right operand
	 * \return Result of \a left * \a right
	 */
	Vector2 operator*(const Vector2& right);

	/**
	 * \brief Overload of the binary * operator.
	 * This operator returns the component-wise division of two vectors
	 * \param right Right operand
	 * \return Result of \a left * \a right
	 */
	Vector2 operator/(const Vector2& right);

    /**
	 * \brief Overload of the unary + operator
	 * \return Result of \a +left
	 */
	Vector2 operator+();

	/**
	 * \brief Overload of the unary - operator
	 * \return Result of \a -left
	 */
	Vector2 operator-();

	/**
	 * \brief Overload of the binary += operator
	 * This operator computes the component-wise sum of vector and value,
	 * and assigns the result to the left operand.
	 * \param right Right operand
	 * \return Reference to \a left
	 */
	Vector2& operator+=(const T& right);

	/**
	 * \brief Overload of the binary -= operator
	 * This operator computes the component-wise subtraction of vector and value,
	 * and assigns the result to the left operand.
	 * \param right Right operand
	 * \return Reference to \a left
	 */
	Vector2& operator-=(const T& right);

	/**
	 * \brief Overload of the binary *= operator
	 * This operator computes the component-wise multiplication of vector and value,
	 * and assigns the result to the left operand.
	 * \param right Right operand
	 * \return Reference to \a left
	 */
	Vector2& operator*=(const T& right);

	/**
	 * \brief Overload of the binary /= operator
	 * This operator computes the component-wise division of vector and value,
	 * and assigns the result to the left operand.
	 * \param right Right operand
	 * \return Reference to \a left
	 */
	Vector2& operator/=(const T& right);

	/**
	 * \brief Overload of the binary += operator
	 * This operator computes the component-wise sum of two vectors,
	 * and assigns the result to the left operand.
	 * \param right Right operand
	 * \return Reference to \a left
	 */
	Vector2& operator+=(const Vector2& right);

	/**
	 * \brief Overload of the binary -= operator
	 * This operator computes the component-wise subtraction of two vectors,
	 * and assigns the result to the left operand.
	 * \param right Right operand
	 * \return Reference to \a left
	 */
	Vector2& operator-=(const Vector2& right);

	/**
	 * \brief Overload of the binary *= operator
	 * This operator computes the component-wise multiplication of two vectors,
	 * and assigns the result to the left operand.
	 * \param right Right operand
	 * \return Reference to \a left
	 */
	Vector2& operator*=(const Vector2& right);

	/**
	 * \brief Overload of the binary /= operator
	 * This operator computes the component-wise division of two vectors,
	 * and assigns the result to the left operand.
	 * \param right Right operand
	 * \return Reference to \a left
	 */
	Vector2& operator/=(const Vector2& right);

	/**
	 * \brief Overload of the == operator
	 * This operator compares two vectors and check if they are equal.
	 * \param right Right operand
	 * \return True if vectors are equal, false if they are different
	 */
	bool operator==(const Vector2& right);

	/**
	 * \brief Overload of the != operator
	 * This operator compares two vectors and check if they are different.
	 * \param right Right operand
	 * \return True if vectors are different, false if they are equal
	 */
	bool operator!=(const Vector2& right);

	/**
	 * \brief X component
	 */
	T x;

	/**
	 * \brief Y component
	 */
	T y;
};

#include <XCurses/Vector2.inl>

using Vector2u = Vector2<uint32_t>;
using Vector2f = Vector2<float>;
using Vector2i = Vector2<int32_t>;
}
