template <typename Type>
std::string Object::getTypeName(const Type& obj)
{
    return typeid(obj).name();
}

template <typename Type>
std::string Object::getTypeName()
{
    return typeid(Type).name();
}