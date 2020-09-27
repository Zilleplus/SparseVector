namespace spr{

template<typename List, auto element, bool = is_empty_v<List>>
struct contains;

template<
    auto... elements,
    auto element>
struct contains<Indexlist<elements...>,element,false>
: std::negation<std::conjunction<std::integral_constant<bool, element != elements>...>>
{
};

template<typename List, auto element>
struct contains<List, element, true> 
: public std::false_type {};

template<typename List, auto element>
static constexpr bool contains_v = contains<List, element>::value;

}
