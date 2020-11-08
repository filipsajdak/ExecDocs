cmake_minimum_required(VERSION 3.13)
project(ExecDocs)
set (CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

add_library(ExecDocsLib ExecDocs.cpp ExecDocs.hpp)
target_include_directories(ExecDocsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(ExecDocsLib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()

find_package(GTest REQUIRED)
add_executable(tests tests.cpp) 
target_link_libraries(tests ExecDocsLib GTest::gmock GTest::gmock_main)
add_test(UnitTests tests)

#find_package(benchmark REQUIRED)
#add_executable(bench benchmark.cpp)
#target_link_libraries(bench helpers pixelsum benchmark::benchmark)
#add_test(Benchmarks bench)
