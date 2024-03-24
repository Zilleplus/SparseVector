export module spr:insert_index;

import :isempty;
import :push_front;
import :indexlist

namespace spr{

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
    using recursive = insert_index_t<element, pop_front_t<List>>;
    using InsertBack = push_front_t<head_v<List>, recursive>;
    using InsertFront = push_front_t<element, List>;
    using Add = std::conditional_t<(element > head_v<List>),
          InsertBack,
          InsertFront>;
    using Type = std::conditional_t<(element == head_v<List>), List, Add>;
};

}
