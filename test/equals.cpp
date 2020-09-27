#include"catch.hpp"
#include"basics.hpp"

TEST_CASE("Check if [1]==[1]", "[Indexlist]"){
    using leftList = spr::Indexlist<1>;
    using rightList = spr::Indexlist<1>;

    REQUIRE(spr::equals_v<leftList, rightList>);
}

TEST_CASE("Different lists should not be equal", "[Indexlist]"){
    using leftList = spr::Indexlist<1,3>;
    using rightList = spr::Indexlist<1,2>;

    REQUIRE(!spr::equals_v<leftList, rightList>);
}

TEST_CASE("The same lists should be equal", "[Indexlist]"){
    using leftList = spr::Indexlist<1,2>;
    using rightList = spr::Indexlist<1,2>;

    REQUIRE(spr::equals_v<leftList, rightList>);
}

