cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "Do not build in-source. Please remove CMakeCache.txt and the CMakeFiles/ directory. Then build out-of-source.")
endif()

project(
    "DSASolutions"
    VERSION 1.0 
    LANGUAGES C CXX
)

add_executable(ArraySolutions ArraySolutions.cpp)
target_link_libraries(ArraySolutions PRIVATE stdc++exp)

add_executable(BinarySolutions BinarySolutions.cpp)
target_link_libraries(BinarySolutions PRIVATE stdc++exp)

add_executable(StringSolutions StringSolutions.cpp)
target_link_libraries(StringSolutions PRIVATE stdc++exp)