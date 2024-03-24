cmake_minimum_required (VERSION 3.28) # 3.28 as we need module support
project (SparseVector)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.5.2
)

FetchContent_MakeAvailable(Catch2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)


add_library(SVector)
target_sources(
  SVector
  PUBLIC
  FILE_SET CXX_MODULES FILES

  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/contains.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/equals.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/hassameindextype.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/head.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/indextype.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/insert_index.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/intersection.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/isempty.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/join.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/length.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/pop_front.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/push_back.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/push_front.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/relativeindex.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist/tostring.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/indexlist.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/vector.cpp
)

# enable_testing()
# add_subdirectory(test)
# add_subdirectory(examples)
