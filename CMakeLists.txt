cmake_minimum_required(VERSION 3.0.0)
project(cpp_study VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(googletest)
include(CTest)
enable_testing()

add_executable(cpp_study main.cpp)
target_link_libraries(cpp_study gtest_main)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})



include(CPack)
