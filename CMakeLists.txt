cmake_minimum_required (VERSION 3.20)
project (SparseVector)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2
)

FetchContent_MakeAvailable(Catch2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

add_library(SVector INTERFACE)
include_directories(SVector INTERFACE "${CMAKE_CURRENT_LIST_DIR}/src")

enable_testing()
add_subdirectory(test)
add_subdirectory(examples)
