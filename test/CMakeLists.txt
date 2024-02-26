# Test the functionality
enable_testing()

add_executable(vectorTests 
    vector.cpp
    contains.cpp
    equals.cpp
    insertindex.cpp
    ) 

target_link_libraries(vectorTests PUBLIC SVector Catch2::Catch2WithMain m)

add_test(NAME vectorTests COMMAND vectorTests)
