export module spr:push_back;

import :indexlist;

namespace spr{

template<auto element, typename List>
struct push_back_t;

template<auto element, auto... elements>
struct push_back_t<element, Indexlist<elements...>>
{
    using Type = Indexlist<elements..., element>;
};

template<auto element, typename List>
using push_back = push_back_t<element, List>;

}
