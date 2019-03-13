#pragma once

#include <string>
#include <memory>
#include <cstdint>

namespace xcur {
/**
 * \brief Base class. It contain object id and and operations to get the class name
 * from type
 */
class Object
{
public:
    /**
     * \brief std::shared_ptr<Type> alias
     * \tparam Type Type of ptr object
     */
    template <class Type>
    using Ptr = std::shared_ptr<Type>;

    /**
     * \brief std::shared_ptr<const Type> alias
     * \tparam Type Type of ptr object
     */
    template <class Type>
    using PtrConst = std::shared_ptr<const Type>;

    /**
     * \brief std::weak_ptr<Type> alias
     * \tparam Type Type of ptr object
     */
    template <class Type>
    using WeakPtr = std::weak_ptr<Type>;

    /**
     * \brief Create Object
     * \return Smart ptr to Object
     */
    static Object::Ptr<Object> create();

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
    uint64_t getId() const;

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

#include <XCurses/System/Object.inl>
}
