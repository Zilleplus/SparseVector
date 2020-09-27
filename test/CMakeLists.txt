# Test the functionality
enable_testing()

add_executable(vectorTests 
    vectorTests.cpp # file containing main method of tests 
    vector.cpp
    contains.cpp
    equals.cpp
    insertindex.cpp
    ) 

if(NOT MSVC)
    target_link_libraries(vectorTests m) # link with the math lib, some toolchains need this
endif()

target_include_directories(vectorTests PUBLIC ../src)
add_test(NAME vectorTests COMMAND vectorTests)
