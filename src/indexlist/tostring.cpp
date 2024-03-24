export module spr:string;

import :lenght;
import :head;
import :pop_front_t

#include <cstddef>
#include <string>

namespace spr{

template<typename List, bool firstCall = true, size_t = length_v<List>>
struct to_string;

template<typename List, std::size_t length>
struct to_string<List, true, length>
{
    static const std::size_t l = length;
    std::string value = std::string("[") 
        + to_string<List, false>().value;
};

template<typename List>
struct to_string<List, false, std::size_t{0}>
{
    static_assert(length_v<List> == 0,"list is of length 0");
    std::string value  = std::string("]");
};

template<typename List>
struct to_string<List, false, std::size_t{1}>
{
    static_assert(length_v<List> == 1,"list is of length 1");
    std::string value = std::to_string(head_v<List>)
        + spr::to_string<pop_front_t<List>, false>().value;
};

template<typename List, std::size_t length>
struct to_string<List, false, length>
{
    std::string value = std::to_string(head_v<List>)
            + std::string(", ")
            + to_string<pop_front_t<List>, false>().value;
};

template<typename List>
std::string to_string_v(){return to_string<List>().value;}

}
