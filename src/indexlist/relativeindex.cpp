export module spr:relativeindex;

import :contains;

namespace spr{
    template<
        auto indexSparse,
        typename List,
        auto startIndex = -1,
        bool = contains_v<List, indexSparse>>
    struct relative_ink

    template<
        auto indexSparse,
        typename List,
        auto startIndex>
    struct relative_index<indexSparse, List, startIndex, false>
    : std::integral_constant<decltype(indexSparse), startIndex>
    {
    };

    template<
        auto indexSparse,
        typename List,
        auto startIndex>
    struct relative_index<indexSparse, List, startIndex, true>
    : relative_index<indexSparse, pop_front_t<List>, startIndex + 1>
    {
    };

    template<auto indexSparse, typename List>
    static constexpr auto relative_index_v 
        = relative_index<indexSparse, List>::value;
}
