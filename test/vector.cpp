#include<catch2/catch_test_macros.hpp>
#include<vector.hpp>

TEST_CASE("Create simple vector with values, and read out it's values again", "[vector]"){
    auto vec = spr::Vector<double, spr::Indexlist<1,2>>{double{3}, double{4}};

    REQUIRE(vec.get<0>() == 0);
    REQUIRE(vec.get<1>() == 3);
    REQUIRE(vec.get<2>() == 4);
    REQUIRE(vec.get<3>() == 0);
}

TEST_CASE("Add two vectors with overlapping range", "[vector]"){
    auto right = spr::Vector<double, spr::Indexlist<1,2>>{double{3}, double{4}};
    auto left =  spr::Vector<double, spr::Indexlist<2,3>>{double{3}, double{4}};
    auto result = left + right;

    REQUIRE(result.get<0>() == 0);
    REQUIRE(result.get<1>() == 3);
    REQUIRE(result.get<2>() == 7);
    REQUIRE(result.get<3>() == 4);
}
