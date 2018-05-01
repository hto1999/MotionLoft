
cmake_minimum_required(VERSION 3.2)
set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 11)
project(MotionLoft.out)

set(GTEST_ROOT "${PROJECT_SOURCE_DIR}/googletest/googletest")
include_directories("/usr/lib" "${GTEST_ROOT}/include/")

add_executable(MotionLoft.out RandomCount.cpp main.cpp)

add_library(gtestlib STATIC IMPORTED)
set_property(TARGET gtestlib PROPERTY IMPORTED_LOCATION ${GTEST_ROOT}/libgtest.a)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(MotionLoft.out gtestlib Threads::Threads)

