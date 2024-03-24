# Test the functionality
enable_testing()

add_executable(vectorTests 
    vector.cpp
    contains.cpp
    equals.cpp
    insertindex.cpp
    ) 

target_link_libraries(vectorTests PUBLIC SVector Catch2::Catch2WithMain m)
set_property(TARGET vectorTests PROPERTY CXX_STANDARD 20)

add_test(NAME vectorTests COMMAND vectorTests)
