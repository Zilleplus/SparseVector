namespace spr{

template<
    typename left,
    typename right,
    bool = is_empty_v<left>
        >
struct join;

template<typename left, typename right>
struct join<left,right,false>{
    using new_right = insert_index_t<head_v<left>,right>;
    using Type = join<pop_front_t<left>,new_right>;
};

template<typename left, typename right>
struct join<left,right,true>{
    using Type = right;
};

template<typename left, typename right>
using join_t = typename join<left, right>::Type;

}
