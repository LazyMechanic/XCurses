#pragma once

#include <string>
#include <memory>
#include <cstdint>

namespace xcur {
class Object
{
public:
    /**
     * \brief std::shared_ptr<Type> alias
     * \tparam Type Object type
     */
	template <typename Type>
	using Ptr = std::shared_ptr<Type>;

	/**
	 * \brief std::shared_ptr<const Type> alias
	 * \tparam Type Object type
	 */
	template <typename Type>
	using PtrConst = std::shared_ptr<const Type>;

	/**
	 * \brief std::weak_ptr<Type> alias
	 * \tparam Type Object type
	 */
	template <typename Type>
	using WeakPtr = std::weak_ptr<Type>;

	/**
	 * \brief Create object and return smart ptr
	 * \tparam Type Object type
	 * \tparam Args Arguments to constructor
	 * \param args Arguments
	 * \return Shared ptr
	 */
	template <class Type, typename ... Args>
	static Object::Ptr<Type> create(Args&& ... args);

    /**
     * \brief Get type name from object
     * \tparam Type Object type
     * \param obj Object
     * \return Type name
     */
    template <typename Type>
	static std::string getTypeName(const Type& obj);

    /**
	 * \brief Object destructor
	 */
	virtual ~Object() = default;

    /**
     * \brief Get type name from template type
     * \tparam Type Type
     * \return Type name
     */
    template <typename Type>
	static std::string getTypeName();

    /**
	 * \brief Get id
	 * \return Object id
	 */
	virtual uint64_t getId() const final;

protected:
    /**
	 * \brief Default object constructor
	 */
	Object();

	/**
	 * \brief Object id
	 */
	const uint64_t m_id;

private:

    /**
	 * \brief Next id
	 */
	static uint64_t nextId;
};

template <class Type, typename ... Args>
Object::Ptr<Type> Object::create(Args&&... args)
{
	static_assert(std::is_base_of<Type, Object>::value == true, "Object type in Object::create(...) must be base of Object class");
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
}
