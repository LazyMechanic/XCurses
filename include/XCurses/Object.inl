template <class Type, typename ... Args>
Object::Ptr<Type> Object::create(Args&&... args)
{
	static_assert(std::is_base_of<Object, Type>::value, "Type must be base of Object class");
	return std::make_shared<Type>(std::forward<Args>(args)...);
}

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