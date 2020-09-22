#ifndef INDEXLIST_HPP
#define INDEXLIST_HPP

#include<type_traits>

namespace spr{
    template<auto... indexes>
    struct Indexlist{};
}

#endif
