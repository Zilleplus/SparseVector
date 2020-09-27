## make sure the user is doing an our of source build:
if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "In-source builds are not allowed. use cmake -H. -Bbuild instead to build in the build folder" )
endif()
###

cmake_minimum_required (VERSION 2.6)
project (SparseVector)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    MESSAGE("using clang compiler -> setting c++ version to 17")
    SET (CMAKE_CXX_FLAGS "-Wall -std=c++17")
endif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
if(MSVC)
    SET (CMAKE_CXX_FLAGS "/std:c++17")
endif()

add_subdirectory(test)
#include_directories("${CMAKE_SOURCE_DIR}/lib/catch2")
#include_directories("${CMAKE_SOURCE_DIR}/include")

#enable_testing()

#add_test(NAME vectorTest COMMAND panocTests)
