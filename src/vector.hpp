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
    DataType* data;
    using indexes = Tindexes;
    using data_type = DataType;

    template<typename... Elements>
    Vector(Elements... els)
    {
        data = new DataType[]{els...};
    }

    ~Vector()
    {
        if(data!=nullptr)
        {
            delete data;
        }
    }
};

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
    typename = typename std::enable_if_t<has_same_index_type_v<TLeft, TRight>>
    >
struct Sumoperation
{
    using indexes = join_t<LeftIndexes,RightIndexes>;
    using data_type = data_type_left;

    TLeft left;
    TRight right;

    Sumoperation(TLeftRef&& left, TRightRef&& right): 
        left(std::forward<TLeftRef>(left)),
        right(std::forward<TRightRef>(right))
    {}

    template<typename TIndex>
    auto operator[] (const TIndex index)
    {
        data_type_left buffer = 0;
        if constexpr (contains_v<LeftIndexes, index>)
        {
            buffer += left[index];
        }
        if constexpr (contains_v<RightIndexes, index>)
        {
            buffer += right[index];
        }

        return buffer;
    }
};

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
    typename = typename std::enable_if_t<has_same_index_type_v<TLeft, TRight>>
    >
auto operator+(TLeftRef left, TRightRef right)
{
    return Sumoperation(
        std::forward<TLeftRef>(left),
        std::forward<TRightRef>(right));
}

}

#endif
