#pragma once

#include <string>
#include <memory>
#include <cstdint>

namespace xcur {
class Object
{
public:
    /**
     * \brief Default object constructor
     */
    Object();

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
    uint64_t getId() const;

protected:
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

#include <XCurses/Graphics/Object.inl>
}
