export module spr:push_front;

import :indexlist;

namespace spr{

template<auto element, typename List>
struct push_front;

template<auto head, auto... elements>
struct push_front<head, Indexlist<elements...>>
{
    using Type = Indexlist<head, elements...>;
};

template<auto element, typename List>
using push_front_t = typename push_front<element, List>::Type;

}
