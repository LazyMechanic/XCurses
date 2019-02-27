#pragma once

/////////////////////////////////////////////////////////////////////////////////////////
// Vector2
/////////////////////////////////////////////////////////////////////////////////////////
namespace xcur {
template <typename T>
class Vector2
{
public:
    Vector2();
    Vector2(T x, T y);

    template<typename From>
    explicit Vector2(const Vector2<From>& vector);

    T x;
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
    Vector3();
    Vector3(T x, T y, T z);

    template<typename From>
    explicit Vector3(const Vector3<From>& vector);

    T x;
    T y;
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
bool operator==(const Vector3<T>& left, const Vector3<T>& right);
template <typename T>
bool operator!=(const Vector3<T>& left, const Vector3<T>& right);

#include <XCurses/Vector.inl>

using Vector2u = Vector2<unsigned int>;
using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;

using Vector3u = Vector3<unsigned int>;
using Vector3f = Vector3<float>;
using Vector3i = Vector3<int>;
}