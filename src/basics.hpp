#ifndef BASICS_HPP
#define BASICS_HPP

#include "indexlist.hpp"
#include <type_traits>

namespace spr{

template<typename List>
struct is_empty;

template<auto... vals>
struct is_empty<Indexlist<vals...>>{
    static constexpr bool value = sizeof...(vals) == 0;
};

template<typename List>
static constexpr bool is_empty_v = is_empty<List>::value;

template<typename List>
struct pop_front;

template<auto head, auto... elements>
struct pop_front<Indexlist<head, elements...>>
{
    using Type = Indexlist<elements...>;
};

template<typename List>
using pop_front_t = typename pop_front<List>::Type;

template<auto element, typename List>
struct push_front;

template<auto head, auto... elements>
struct push_front<head, Indexlist<head, elements...>>
{
    using Type = Indexlist<head, elements...>;
};

template<auto element, typename List>
using push_front_t = typename push_front<element, List>::Type;

template<auto element, typename List>
struct push_back_t;

template<auto element, auto... elements>
struct push_back_t<element, Indexlist<elements...>>
{
    using Type = Indexlist<elements..., element>;
};

template<auto element, typename List>
using push_back = push_back_t<element, List>;

template<typename List>
struct head;

template<auto val, auto... tail>
struct head<Indexlist<val, tail...>>
{
    static constexpr auto value = val;
};

template<typename List>
static constexpr auto head_v = head<List>::value;

template<auto element, typename List, bool = is_empty_v<List>>
struct insert_index;

template<auto element, typename List>
using insert_index_t = typename insert_index<element, List>::Type;

template<auto element, typename List>
struct insert_index<element, List, true>
{
    using Type = Indexlist<element>;
};

template<auto element, typename List>
struct insert_index<element, List, false>
{
    using recursive = insert_index_t<element, pop_front<List>>;
    using InsertBack = push_front<head_v<List>, recursive>;
    using InsertFront = push_front<element, List>;
    using Add = std::conditional<(element > head_v<List>),
          InsertBack,
          InsertFront>;
    using Type = std::conditional<(element == head_v<List>), 
          List,
          Add>;
};

template<typename List, auto element, bool = is_empty_v<List>>
struct contains;

template<
    auto... elements,
    auto element>
struct contains<Indexlist<elements...>,element,false>
{
    static constexpr bool value = 
        std::conjunction_v<std::negation_v<std::is_same_v<elements, element>>...>;
};

template<typename List, auto element>
struct contains<List, element, true> 
: public std::false_type {};

template<typename List, auto element>
static constexpr bool contains_v = contains<List, element>::value;

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

template<typename left, typename right, bool = is_empty_v<left>>
struct join;

template<typename left, typename right>
struct join<left,right,false>{
    using new_right = insert_index_t<head_v<left>,right>;
    using Type = join<pop_front<left>,new_right>;
};

template<typename left, typename right>
struct join<left,right,true>{
    using Type = right;
};

template<typename left, typename right>
using join_t = typename join<left, right>::Type;

// undefined for empty lists, as they have no index type
template<typename List, bool = is_empty_v<List>>
struct index_type;

template<typename List>
struct index_type<List, false>{
    using Type = decltype(head_v<List>);
};

template<
    typename left,
    typename right,
    bool = is_empty_v<left>,
    bool = is_empty_v<right>
    >
struct has_same_index_type;

template<
    typename left,
    typename right>
static constexpr bool has_same_index_type_v =  has_same_index_type<left, right>::value;

template<typename left,typename right>
struct has_same_index_type<left, right, false, false> 
    : std::is_same<
        decltype(head_v<left>),
        decltype(head_v<right>)>{
};

template<
    typename left,
    typename right,
    bool is_left_empty,
    bool is_right_empty>
struct has_same_index_type : std::true_type{}; 

}

#endif
