#pragma once

#include <cstdint>

namespace xcur {
/**
 * \brief Class for manipulating 2-dimensional vectors
 * \tparam T Type of vector components
 */
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
     * \brief Overload of the binary + operator.
     * This operator returns the component-wise sum of vector and value
     * \param right Right operand
     * \return Result of \a left + \a right
     */
    Vector3 operator+(const T& right);

    /**
     * \brief Overload of the binary - operator.
     * This operator returns the component-wise subtraction of vector and value
     * \param right Right operand
     * \return Result of \a left - \a right
     */
    Vector3 operator-(const T& right);

    /**
     * \brief Overload of the binary * operator.
     * This operator returns the component-wise multiplication of vector and value
     * \param right Right operand
     * \return Result of \a left * \a right
     */
    Vector3 operator*(const T& right);

    /**
     * \brief Overload of the binary * operator.
     * This operator returns the component-wise division of vector and value
     * \param right Right operand
     * \return Result of \a left * \a right
     */
    Vector3 operator/(const T& right);

    /**
     * \brief Overload of the binary + operator.
     * This operator returns the component-wise sum of two vectors
     * \param right Right operand
     * \return Result of \a left + \a right
     */
    Vector3 operator+(const Vector3<T>& right);

    /**
     * \brief Overload of the binary - operator.
     * This operator returns the component-wise subtraction of two vectors
     * \param right Right operand
     * \return Result of \a left - \a right
     */
    Vector3 operator-(const Vector3<T>& right);

    /**
     * \brief Overload of the binary * operator.
     * This operator returns the component-wise multiplication of two vectors
     * \param right Right operand
     * \return Result of \a left * \a right
     */
    Vector3 operator*(const Vector3<T>& right);

    /**
     * \brief Overload of the binary * operator.
     * This operator returns the component-wise division of two vectors
     * \param right Right operand
     * \return Result of \a left * \a right
     */
    Vector3 operator/(const Vector3<T>& right);

    /**
     * \brief Overload of the unary + operator
     * \return Result of \a +left
     */
    Vector3 operator+();

    /**
     * \brief Overload of the unary - operator
     * \return Result of \a -left
     */
    Vector3 operator-();

    /**
     * \brief Overload of the binary += operator
     * This operator computes the component-wise sum of vector and value,
     * and assigns the result to the left operand.
     * \param right Right operand
     * \return Reference to \a left
     */
    Vector3& operator+=(const T& right);

    /**
     * \brief Overload of the binary -= operator
     * This operator computes the component-wise subtraction of vector and value,
     * and assigns the result to the left operand.
     * \param right Right operand
     * \return Reference to \a left
     */
    Vector3& operator-=(const T& right);

    /**
     * \brief Overload of the binary *= operator
     * This operator computes the component-wise multiplication of vector and value,
     * and assigns the result to the left operand.
     * \param right Right operand
     * \return Reference to \a left
     */
    Vector3& operator*=(const T& right);

    /**
     * \brief Overload of the binary /= operator
     * This operator computes the component-wise division of vector and value,
     * and assigns the result to the left operand.
     * \param right Right operand
     * \return Reference to \a left
     */
    Vector3& operator/=(const T& right);

    /**
     * \brief Overload of the binary += operator
     * This operator computes the component-wise sum of two vectors,
     * and assigns the result to the left operand.
     * \param right Right operand
     * \return Reference to \a left
     */
    Vector3& operator+=(const Vector3<T>& right);

    /**
     * \brief Overload of the binary -= operator
     * This operator computes the component-wise subtraction of two vectors,
     * and assigns the result to the left operand.
     * \param right Right operand
     * \return Reference to \a left
     */
    Vector3& operator-=(const Vector3<T>& right);

    /**
     * \brief Overload of the binary *= operator
     * This operator computes the component-wise multiplication of two vectors,
     * and assigns the result to the left operand.
     * \param right Right operand
     * \return Reference to \a left
     */
    Vector3& operator*=(const Vector3<T>& right);

    /**
     * \brief Overload of the binary /= operator
     * This operator computes the component-wise division of two vectors,
     * and assigns the result to the left operand.
     * \param right Right operand
     * \return Reference to \a left
     */
    Vector3& operator/=(const Vector3<T>& right);

    /**
     * \brief Overload of the == operator
     * This operator compares two vectors and check if they are equal.
     * \param right Right operand
     * \return True if vectors are equal, false if they are different
     */
    bool operator==(const Vector3<T>& right);

    /**
     * \brief Overload of the != operator
     * This operator compares two vectors and check if they are different.
     * \param right Right operand
     * \return True if vectors are different, false if they are equal
     */
    bool operator!=(const Vector3<T>& right);

    /**
     * \brief Vector3 destructor
     */
    ~Vector3() = default;

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

#include <XCurses/System/Vector3.inl>

using Vector3u = Vector3<uint32_t>;
using Vector3f = Vector3<float>;
using Vector3i = Vector3<int32_t>;
}