export module spr:length;
import :indexlist;

#include<type_traits>

namespace spr{
    template<typename List>
    struct length;

    template<auto... args>
    struct length<Indexlist<args...>>
    : std::integral_constant<unsigned, sizeof...(args)>
    {
    };

    template<typename List>
    static constexpr std::size_t length_v = length<List>::value;
}
