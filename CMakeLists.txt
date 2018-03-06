cmake_minimum_required(VERSION 3.0)
project(test_catch2)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(YARP REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(harness_os_catch2 harness.cpp
                                 BinPortableTest.cpp
                                 BottleTest.cpp)
target_link_libraries(harness_os_catch2 YARP::YARP_OS
                                        YARP::YARP_init
                                        YARP::YARP_serversql)


enable_testing()

include(Catch)
catch_discover_tests(harness_os_catch2)
