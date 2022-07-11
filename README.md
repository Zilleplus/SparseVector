# SparseVector: A sparse vector algebra

## What is this?
- Sparse vector library.
- Sparcity is saved at compile time in a compile time list.
- The values in the vectors itself are stored on the heap at run time.
- Basic element wise runtime operations are supported.
- Witten in C++17.

## Example code
- Create 2 vectors:
    - left: index=1 has value=1 and index=2 has value=2
    - right: index=2 has value=3 and index=3 has value=4
- If the two vector were not sparse we would get:
    - left =[0; 1; 2; 0;]
    - right=[0; 0; 3; 4;]
    - left + right = [0; 1; 5; 4]
- By not saving the zero's we know at compile time, we save memory and lose not performance.

```
    std::cout << "creating 2 vectors" << std::endl;

    auto right = spr::Vector<double, spr::Indexlist<1,2>>{ double{1}, double{2}};
    auto left =  spr::Vector<double, spr::Indexlist<2,3>>{ double{3}, double{4}};
    auto result = left + right;

    // Print out the results:
    std::cout << "result: " std::endl;
    std::cout << "[index=" << 0 << "; value=" << result.get<0>() << "]" << std::endl;
    std::cout << "[index=" << 1 << "; value=" << result.get<1>() << "]" << std::endl;
    std::cout << "[index=" << 2 << "; value=" << result.get<2>() << "]" << std::endl;
    std::cout << "[index=" << 3 << "; value=" << result.get<3>() << "]" << std::endl;

    // special case: the sparse vector has no size!
    // 1000 was not set by either left or right -> returns 0
    std::cout << "[index=" << 1000 << "; value=" << result.get<1000>() << "]" << std::endl;
```

output:
```
creating 2 vectors
result: 
[index=0; value=0]
[index=1; value=1]
[index=2; value=5]
[index=3; value=4]
[index=1000; value=0]
```