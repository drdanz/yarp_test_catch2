cmake_minimum_required(VERSION 3.0)
project(test_catch2)

find_package(YARP REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(harness_os_catch2 harness.cpp
                                 BinPortableTest.cpp)
target_link_libraries(harness_os_catch2 YARP::YARP_OS
                                        YARP::YARP_init
                                        YARP::YARP_serversql)
