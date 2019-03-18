template <typename T>
const Vector3<T> Vector3<T>::Zero = Vector3<T>(0, 0);

template<typename T>
Vector3<T>::Vector3() :
    x(0),
    y(0),
    z(0)
{

}

template<typename T>
Vector3<T>::Vector3(T x, T y, T z) :
    x(x),
    y(y),
    z(z)
{

}

template<typename T>
template<typename From>
Vector3<T>::Vector3(const Vector3<From>& vector) :
    x(static_cast<T>(vector.x)),
    y(static_cast<T>(vector.y)),
    z(static_cast<T>(vector.z))
{

}

template<typename T>
Vector3<T> Vector3<T>::operator+(const T& right)
{
    return Vector3<T>(this->x + right, this->y + right, this->z + right);
}

template<typename T>
Vector3<T> Vector3<T>::operator-(const T& right)
{
    return Vector3<T>(this->x - right, this->y - right, this->z - right);
}

template<typename T>
Vector3<T> Vector3<T>::operator*(const T& right)
{
    return Vector3<T>(this->x * right, this->y * right, this->z * right);
}

template<typename T>
Vector3<T> Vector3<T>::operator/(const T& right)
{
    return Vector3<T>(this->x / right, this->y / right, this->z / right);
}

template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T>& right)
{
    return Vector3<T>(this->x + right.x, this->y + right.y, this->z + right.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T>& right)
{
    return Vector3<T>(this->x - right.x, this->y - right.y, this->z - right.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator*(const Vector3<T>& right)
{
    return Vector3<T>(this->x * right.x, this->y * right.y, this->z * right.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator/(const Vector3<T>& right)
{
    return Vector3<T>(this->x / right.x, this->y / right.y, this->z / right.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator+()
{
    return *this;
}

template<typename T>
Vector3<T> Vector3<T>::operator-()
{
    return Vector3<T>(-this->x, -this->y, -this->z);
}

template<typename T>
Vector3<T>& Vector3<T>::operator+=(const T& right)
{
    return *this = *this + right;
}

template<typename T>
Vector3<T>& Vector3<T>::operator-=(const T& right)
{
    return *this = *this - right;
}

template<typename T>
Vector3<T>& Vector3<T>::operator*=(const T& right)
{
    return *this = *this * right;
}

template<typename T>
Vector3<T>& Vector3<T>::operator/=(const T& right)
{
    return *this = *this / right;
}

template<typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& right)
{
    return *this = *this + right;
}

template<typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& right)
{
    return *this = *this - right;
}

template<typename T>
Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& right)
{
    return *this = *this * right;
}

template<typename T>
Vector3<T>& Vector3<T>::operator/=(const Vector3<T>& right)
{
    return *this = *this / right;
}

template<typename T>
bool Vector3<T>::operator==(const Vector3<T>& right)
{
    return (this->x == right.x) && (this->y == right.y) && (this->z == right.z);
}

template<typename T>
bool Vector3<T>::operator!=(const Vector3<T>& right)
{
    return !(*this == right);
}