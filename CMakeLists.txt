cmake_minimum_required(VERSION 3.26)
project(Uzduotis_nr_1)

set(CMAKE_CXX_STANDARD 14)

# Your main executable
add_executable(Uzduotis_nr_1
        src/main.cpp
        src/Studentai.cpp
        src/funkcijos.cpp
        Include/Studentai.h
        Include/funkcijos.h
        Include/bibliotekos.h)

# Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Test executable
add_executable(UzduotisTest
        test.cpp
        src/Studentai.cpp
        src/funkcijos.cpp
        Include/Studentai.h
        Include/funkcijos.h
        Include/bibliotekos.h)

target_link_libraries(UzduotisTest gtest_main)

include(GoogleTest)
gtest_discover_tests(UzduotisTest)