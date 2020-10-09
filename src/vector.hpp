#ifndef VECTOR_HPP
#define VECTOR_HPP

#include<utility>
#include<type_traits>
#include"basics.hpp"

namespace spr{

template<
    typename DataType,
    typename Tindexes
        >
struct Vector{
    bool isDeleted = false;
    DataType* data;
    using indexes = Tindexes;
    using data_type = DataType;

    template<typename... Elements>
    Vector(Elements... els) :
        data(new DataType[]{els...})
    {
    }

    Vector(Vector<DataType, Tindexes>& other) = delete;

    ~Vector()
    {
        delete[] data;
        isDeleted = true;
    }

    template<
        auto index,
        auto relativeIndex = relative_index_v<index, indexes>
            >
    auto get() const
    {
        if constexpr(relativeIndex != -1)
        {
            return data[relativeIndex];
        }
        return DataType{0};
    }
};

template<
    typename TLeftRef,
    typename TRightRef,
    typename OperationPolicy,
    typename TLeft = std::remove_reference_t<TLeftRef>,
    typename TRight = std::remove_reference_t<TRightRef>,
    typename data_type_left = typename TLeft::data_type,
    typename data_type_right = typename TRight::data_type,
    typename LeftIndexes = typename TLeft::indexes,
    typename RightIndexes = typename TRight::indexes,
    typename = typename std::enable_if_t<std::is_same_v<data_type_left,data_type_right>>,
    typename = typename std::enable_if_t<has_same_index_type_v<LeftIndexes, RightIndexes>>
    >
struct BinOperation
{
    using indexes = join_t<LeftIndexes,RightIndexes>;
    using data_type = data_type_left;

    TLeftRef left;
    TRightRef right;

    BinOperation(TLeftRef&& left, TRightRef&& right): 
        left(std::forward<TLeftRef>(left)),
        right(std::forward<TRightRef>(right)){}

    ~BinOperation(){}

    template<auto index>
    auto get() const
    {
        return OperationPolicy::Eval(
                left.template get<index>(),
                right.template get<index>());
    }
};

struct AddPolicy{
    static constexpr auto Eval = [](auto left, auto right)
    {
        return left + right;
    };
};

struct SubPolicy{
    static constexpr auto Eval = [](auto left, auto right)
    {
        return left - right;
    };
};

template<typename Left, typename Right>
using SumOperation = BinOperation<Left, Right, AddPolicy>;

template<typename Left, typename Right>
using SubOperation = BinOperation<Left, Right, SubPolicy>;

template<
    typename TLeftRef,
    typename TRightRef,
    typename TLeft = std::remove_reference_t<TLeftRef>,
    typename TRight = std::remove_reference_t<TRightRef>,
    typename data_type_left = typename TLeft::data_type,
    typename data_type_right = typename TRight::data_type,
    typename LeftIndexes = typename TLeft::indexes,
    typename RightIndexes = typename TRight::indexes,
    typename = typename std::enable_if_t<std::is_same_v<data_type_left,data_type_right>>,
    typename = typename std::enable_if_t<has_same_index_type_v<LeftIndexes, RightIndexes>>
    >
auto operator+(
        TLeftRef&& left,
        TRightRef&& right)
{
    return SumOperation<TLeftRef, TRightRef>(
        std::forward<TLeftRef>(left),
        std::forward<TRightRef>(right));
}

template<
    typename TLeftRef,
    typename TRightRef,
    typename TLeft = std::remove_reference_t<TLeftRef>,
    typename TRight = std::remove_reference_t<TRightRef>,
    typename data_type_left = typename TLeft::data_type,
    typename data_type_right = typename TRight::data_type,
    typename LeftIndexes = typename TLeft::indexes,
    typename RightIndexes = typename TRight::indexes,
    typename = typename std::enable_if_t<std::is_same_v<data_type_left,data_type_right>>,
    typename = typename std::enable_if_t<has_same_index_type_v<LeftIndexes, RightIndexes>>
    >
auto operator-(
        TLeftRef&& left,
        TRightRef&& right)
{
    return SubOperation<TLeftRef, TRightRef>(
        std::forward<TLeftRef>(left),
        std::forward<TRightRef>(right));
}

}

#endif
