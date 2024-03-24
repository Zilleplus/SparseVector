export module spr:intersection;

import :empty;
import :push_front;
import :head;
import :pop_front;

namespace spr{

template<typename List1, typename List2, bool = is_empty_v<List1>>
struct intersection;

template<typename List1, typename List2>
using intersection_t =  typename intersection<List1, List2>::Type;

template<
    typename ListLeft, 
    typename ListRight
>
struct intersection<ListLeft, ListRight, false>
{
    static constexpr auto current = head_v<ListLeft>;
    using recursive = intersection_t<pop_front_t<ListLeft>,ListRight>;
    using Type = std::conditional<contains_v<ListRight,current>,
        push_front_t<current, recursive>,
        recursive>;
};

template<
    typename ListLeft, 
    typename ListRight
>
struct intersection<ListLeft, ListRight, true>
{
    using Type = ListLeft;
};

}
