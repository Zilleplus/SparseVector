namespace spr{

template<typename List>
struct is_empty;

template<auto... vals>
struct is_empty<Indexlist<vals...>>{
    static constexpr bool value = (sizeof...(vals) == 0);
};

template<typename List>
static constexpr bool is_empty_v = is_empty<List>::value;

}
