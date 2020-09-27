namespace spr{
template<typename List>
struct head;

template<auto val, auto... tail>
struct head<Indexlist<val, tail...>>
{
    static constexpr auto value = val;
};

template<typename List>
static constexpr auto head_v = head<List>::value;

}
