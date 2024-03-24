export module spr:equals;

#include <type_traits>
import :length;

namespace spr{
    template<
        typename LeftList,
        typename RightList,
        bool = length_v<LeftList> == length_v<RightList>,
        bool = is_empty_v<LeftList>
        >
    struct equals: std::integral_constant<bool, false>{};;

    // two empty lists must be equal
    template< typename Left, typename Right >
    struct equals<Left, Right, true, true> : std::integral_constant<bool, true>{};

    template< typename Left, typename Right>
    struct equals<Left, Right, true, false>
    {
        static constexpr bool headEqual = 
            (head_v<Left> == head_v<Right>);
        using tailEqual = equals<
            pop_front_t<Left>,
            pop_front_t<Right>>;

        static constexpr bool value = headEqual 
            && tailEqual::value;
    };

    export template<typename Left, typename Right>
    constexpr bool equals_v = equals<Left, Right>::value;
}
