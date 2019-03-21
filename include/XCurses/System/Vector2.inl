template<typename T>
const Vector2<T> Vector2<T>::Zero = Vector2<T>(0, 0);

template<typename T>
Vector2<T>::Vector2() :
    x(0),
    y(0)
{

}

template<typename T>
Vector2<T>::Vector2(T x, T y) :
    x(x),
    y(y)
{

}

template<typename T>
template<typename From>
Vector2<T>::Vector2(const Vector2<From>& vector) :
    x(static_cast<T>(vector.x)),
    y(static_cast<T>(vector.y))
{

}

template <typename T>
Vector2<T> Vector2<T>::operator+(const T& right) const
{
    return Vector2<T>(this->x + right, this->y + right);
}

template<typename T>
Vector2<T> Vector2<T>::operator-(const T& right) const
{
    return Vector2<T>(this->x - right, this->y - right);
}

template<typename T>
Vector2<T> Vector2<T>::operator*(const T& right) const
{
    return Vector2<T>(this->x * right, this->y * right);
}

template<typename T>
Vector2<T> Vector2<T>::operator/(const T& right) const
{
    return Vector2<T>(this->x / right, this->y / right);
}

template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& right) const
{
    return Vector2<T>(this->x + right.x, this->y + right.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& right) const
{
    return Vector2<T>(this->x - right.x, this->y - right.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator*(const Vector2<T>& right) const
{
    return Vector2<T>(this->x * right.x, this->y * right.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator/(const Vector2<T>& right) const
{
    return Vector2<T>(this->x / right.x, this->y / right.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator+() const
{
    return *this;
}

template<typename T>
Vector2<T> Vector2<T>::operator-() const
{
    return Vector2<T>(-this->x, -this->y);
}

template<typename T>
Vector2<T>& Vector2<T>::operator+=(const T& right)
{
    return *this = *this + right;
}

template<typename T>
Vector2<T>& Vector2<T>::operator-=(const T& right)
{
    return *this = *this - right;
}

template<typename T>
Vector2<T>& Vector2<T>::operator*=(const T& right)
{
    return *this = *this * right;
}

template<typename T>
Vector2<T>& Vector2<T>::operator/=(const T& right)
{
    return *this = *this / right;
}

template<typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& right)
{
    return *this = *this + right;
}

template<typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& right)
{
    return *this = *this - right;
}

template<typename T>
Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& right)
{
    return *this = *this * right;
}

template<typename T>
Vector2<T>& Vector2<T>::operator/=(const Vector2<T>& right)
{
    return *this = *this / right;
}

template<typename T>
bool Vector2<T>::operator==(const Vector2<T>& right)
{
    return (this->x == right.x) && (this->y == right.y);
}

template<typename T>
bool Vector2<T>::operator!=(const Vector2<T>& right)
{
    return !(*this == right);
}