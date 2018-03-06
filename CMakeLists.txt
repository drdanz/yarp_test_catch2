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


include(ParseAndAddCatchTests)
set(PARSE_CATCH_TESTS_VERBOSE OFF CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_NO_HIDDEN_TESTS ON CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_ADD_TARGET_IN_TEST_NAME OFF CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_ADD_FIXTURE_IN_TEST_NAME ON CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_ADD_TO_CONFIGURE_DEPENDS ON CACHE INTERNAL "")
ParseAndAddCatchTests(harness_os_catch2)
