#pragma once

#include <cstdint>

/////////////////////////////////////////////////////////////////////////////////////////
// Vector2
/////////////////////////////////////////////////////////////////////////////////////////
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
     * \brief X component
     */
    T x;

    /**
     * \brief Y component
     */
    T y;
};

template <typename T>
Vector2<T> operator+(const Vector2<T>& left, const T& right);
template <typename T>
Vector2<T> operator-(const Vector2<T>& left, const T& right);
template <typename T>
Vector2<T> operator*(const Vector2<T>& left, const T& right);
template <typename T>
Vector2<T> operator/(const Vector2<T>& left, const T& right);

template <typename T>
Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right);
template <typename T>
Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right);
template <typename T>
Vector2<T> operator*(const Vector2<T>& left, const Vector2<T>& right);
template <typename T>
Vector2<T> operator/(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T> operator+(const Vector2<T>& left);
template <typename T>
Vector2<T> operator-(const Vector2<T>& left);

template <typename T>
Vector2<T>& operator+=(Vector2<T>& left, const T& right);
template <typename T>
Vector2<T>& operator-=(Vector2<T>& left, const T& right);
template <typename T>
Vector2<T>& operator*=(Vector2<T>& left, const T& right);
template <typename T>
Vector2<T>& operator/=(Vector2<T>& left, const T& right);

template <typename T>
Vector2<T> operator+=(const Vector2<T>& left, const Vector2<T>& right);
template <typename T>
Vector2<T> operator-=(const Vector2<T>& left, const Vector2<T>& right);
template <typename T>
Vector2<T> operator*=(const Vector2<T>& left, const Vector2<T>& right);
template <typename T>
Vector2<T> operator/=(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
bool operator==(const Vector2<T>& left, const Vector2<T>& right);
template <typename T>
bool operator!=(const Vector2<T>& left, const Vector2<T>& right);

/////////////////////////////////////////////////////////////////////////////////////////
// Vector3
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class Vector3
{
public:
    /**
     * \brief Default Vector3 constructor. Construct vector with 0 components
     */
    Vector3();

	/**
	 * \brief Vector3 constructor. Construct vector with specific components
	 * \param x X component
	 * \param y Y component
	 * \param z Z component
	 */
    Vector3(T x, T y, T z);

	/**
	 * \brief Vector3 construct. Construct vector from another vector
	 * \tparam From Another vector type
	 * \param vector Another vector
	 */
	template<typename From>
	explicit Vector3(const Vector3<From>& vector);

    /**
	 * \brief Copy Vector3 constructor
	 */
	Vector3(const Vector3<T>&) = default;

    /**
	 * \brief Move Vector3 constructor
	 */
	Vector3(Vector3<T>&&) = default;

	/**
	 * \brief Default copy assignment operator
	 * \return Reference to \a this
	 */
	Vector3& operator =(const Vector3<T>&) = default;

	/**
	 * \brief Default move assignment operator
	 * \return Reference to \a this
	 */
	Vector3& operator =(Vector3<T>&&) = default;

    /**
     * \brief X component
     */
    T x;

    /**
     * \brief Y component
     */
    T y;

    /**
     * \brief Z component
     */
    T z;
};

template <typename T>
Vector3<T> operator+(const Vector3<T>& left, const T& right);
template <typename T>
Vector3<T> operator-(const Vector3<T>& left, const T& right);
template <typename T>
Vector3<T> operator*(const Vector3<T>& left, const T& right);
template <typename T>
Vector3<T> operator/(const Vector3<T>& left, const T& right);

template <typename T>
Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right);
template <typename T>
Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right);
template <typename T>
Vector3<T> operator*(const Vector3<T>& left, const Vector3<T>& right);
template <typename T>
Vector3<T> operator/(const Vector3<T>& left, const Vector3<T>& right);

template <typename T>
Vector3<T> operator+(const Vector3<T>& left);
template <typename T>
Vector3<T> operator-(const Vector3<T>& left);

template <typename T>
Vector3<T>& operator+=(Vector3<T>& left, const T& right);
template <typename T>
Vector3<T>& operator-=(Vector3<T>& left, const T& right);
template <typename T>
Vector3<T>& operator*=(Vector3<T>& left, const T& right);
template <typename T>
Vector3<T>& operator/=(Vector3<T>& left, const T& right);

template <typename T>
Vector3<T> operator+=(const Vector3<T>& left, const Vector3<T>& right);
template <typename T>
Vector3<T> operator-=(const Vector3<T>& left, const Vector3<T>& right);
template <typename T>
Vector3<T> operator*=(const Vector3<T>& left, const Vector3<T>& right);
template <typename T>
Vector3<T> operator/=(const Vector3<T>& left, const Vector3<T>& right);

template <typename T>
bool operator==(const Vector3<T>& left, const Vector3<T>& right);
template <typename T>
bool operator!=(const Vector3<T>& left, const Vector3<T>& right);

#include <XCurses/Vector.inl>

using Vector2u = Vector2<uint32_t>;
using Vector2f = Vector2<float>;
using Vector2i = Vector2<int32_t>;

using Vector3u = Vector3<uint32_t>;
using Vector3f = Vector3<float>;
using Vector3i = Vector3<int32_t>;
}