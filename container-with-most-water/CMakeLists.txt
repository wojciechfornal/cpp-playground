cmake_minimum_required(VERSION 4.3.2)
project(cpp-project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    solution_test
    src/solution.cc
    tests/solution_test.cc
)

target_link_libraries(
    solution_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(solution_test)