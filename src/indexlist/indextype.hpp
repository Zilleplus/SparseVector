namespace spr{

// undefined for empty lists, as they have no index type
template<typename List, bool = is_empty_v<List>>
struct index_type;

template<typename List>
struct index_type<List, false>{
    using Type = decltype(head_v<List>);
};

}
