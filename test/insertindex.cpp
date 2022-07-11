#include<catch2/catch.hpp>
#include"basics.hpp"

TEST_CASE("Insert index in empty list", "[Indexlist]"){
    using namespace spr;
    using list = Indexlist<>;
    using res = insert_index<1,list>::Type;
    using exp = Indexlist<1>;
    INFO(std::string("result: ") + spr::to_string_v<res>());
    INFO(std::string("expected: ") + spr::to_string_v<exp>());

    REQUIRE(equals_v<res, exp>);
}

TEST_CASE("Insert index in list with one lower element", "[Indexlist]"){
    using namespace spr;
    using list = Indexlist<1>;
    using res = insert_index<2, list>::Type;
    using exp = Indexlist<1, 2>;
    INFO(std::string("result: ") + spr::to_string_v<res>());
    INFO(std::string("expected: ") + spr::to_string_v<exp>());

    REQUIRE(equals_v<res, exp>);
}

TEST_CASE("Insert index in list with one higher element", "[Indexlist]"){
    using namespace spr;
    using list = Indexlist<3>;
    using res = insert_index<2, list>::Type;
    using exp = Indexlist<2, 3>;
    INFO(std::string("result: ") + spr::to_string_v<res>());
    INFO(std::string("expected: ") + spr::to_string_v<exp>());

    REQUIRE(equals_v<res, exp>);
}

TEST_CASE("Insert index in list with both lower and higher element", "[Indexlist]"){
    using namespace spr;
    using list = Indexlist<1,3>;
    using res = insert_index<2,list>::Type;
    using exp = Indexlist<1, 2, 3>;
    INFO(std::string("result: ") + spr::to_string_v<res>());
    INFO(std::string("expected: ") + spr::to_string_v<exp>());

    REQUIRE(equals_v<res, exp>);
}

TEST_CASE("Insert index in list with same element", "[Indexlist]"){
    using namespace spr;
    using list = Indexlist<1, 2, 3>;

    using res = insert_index<2,list>::Type;
    using exp = Indexlist<1, 2, 3>;
    INFO(std::string("result: ") + spr::to_string_v<res>());
    INFO(std::string("expected: ") + spr::to_string_v<exp>());

    REQUIRE(equals_v<res, exp>);
}
