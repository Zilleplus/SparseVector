#include<iostream>
#include<vector.hpp>

int main(){
    std::cout << "creating 2 vectors" << std::endl;

    auto right = spr::Vector<double, spr::Indexlist<1,2>>{double{1}, double{2}};
    auto left =  spr::Vector<double, spr::Indexlist<2,3>>{double{3}, double{4}};
    auto result = left + right;

    std::cout << "result: " ;
    // nothing was set on index 0 -> return zero
    std::cout << "[index=" << 0 << "; value=" << result.get<0>() << "]" << std::endl;

    // only left(value=1) has a value -> return 1
    std::cout << "[index=" << 1 << "; value=" << result.get<1>() << "]" << std::endl;

    // both left(value=2) and right(value=3) have a value -> return 2+3=5
    std::cout << "[index=" << 2 << "; value=" << result.get<2>() << "]" << std::endl;

    // Only left(value=4) has a value -> return 4
    std::cout << "[index=" << 3 << "; value=" << result.get<3>() << "]" << std::endl;

    // 1000 was not set by either left or right -> returns 0
    std::cout << "[index=" << 1000 << "; value=" << result.get<1000>() << "]" << std::endl;

    // CONSOLE OUTPUT:
    // 
    // creating 2 vectors
    // result: [index=0; value=0]
    // [index=1; value=1]
    // [index=2; value=5]
    // [index=3; value=4]
    // [index=1000; value=0]

}
