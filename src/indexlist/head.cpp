export module spr:head;
import :indexlist;

namespace spr{
template<typename List>
struct head;

template<auto val, auto... tail>
struct head<Indexlist<val, tail...>>
{
    static constexpr auto value = val;
};

export template<typename List>
static constexpr auto head_v = head<List>::value;

}