cmake_minimum_required (VERSION 3.20)
project (SparseVector)

include(${CMAKE_CURRENT_LIST_DIR}/conan_cmake/conan.cmake)
conan_cmake_configure(REQUIRES
        catch2/2.13.6
        GENERATORS
        ycm
        cmake_find_package
        cmake
        cmake_paths)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        REMOTE conancenter
        SETTINGS ${settings})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

find_package(Catch2 REQUIRED)

add_library(SVector INTERFACE)
include_directories(SVector INTERFACE "${CMAKE_CURRENT_LIST_DIR}/src")

enable_testing()
add_subdirectory(test)
add_subdirectory(examples)
