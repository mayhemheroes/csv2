cmake_minimum_required(VERSION 3.16)
project(csv2)

IF (NOT MSVC)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
ENDIF (NOT MSVC)

add_executable(fuzz_csv2parse fuzz_csv2parse.cpp)
target_include_directories(fuzz_csv2parse PUBLIC ../include)
## Uncomment these lines after converting fuzzme.c into a libFuzzer target
if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(FATAL_ERROR "Clang is required for libFuzzer!")
endif() 
target_compile_options(fuzz_csv2parse PUBLIC -fsanitize=fuzzer,address)
target_link_options(fuzz_csv2parse PUBLIC -fsanitize=fuzzer,address)

