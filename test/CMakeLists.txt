# Test the functionality
enable_testing()

add_executable(vectorTests 
    vectorTests.cpp # file containing main method of tests 
    vector.cpp
    contains.cpp
    equals.cpp
    insertindex.cpp
    ) 

target_link_libraries(vectorTests PUBLIC SVector Catch2::Catch2 m)

add_test(NAME vectorTests COMMAND vectorTests)
