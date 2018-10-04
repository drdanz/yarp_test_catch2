cmake_minimum_required(VERSION 3.0)
project(test_catch2)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(YARP 3.1 REQUIRED COMPONENTS OS sig serversql)

option(USE_SYSTEM_CATCH "Use system catch.hpp" OFF)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(harness_os_catch2 harness.cpp
                                 BinPortableTest.cpp
                                 BottleTest.cpp
                                 BufferedConnectionWriterTest.cpp
                                 ContactTest.cpp
                                 DgramTwoWayStreamTest.cpp
                                 ElectionTest.cpp
                                 EventTest.cpp
                                 LogStreamTest.cpp
                                 LogTest.cpp)

target_link_libraries(harness_os_catch2 PRIVATE YARP::YARP_OS
                                                YARP::YARP_init
                                                YARP::YARP_sig
                                                YARP::YARP_serversql
                                                YARP::YARP_sig
                                                ACE)

target_compile_definitions(harness_os_catch2 PRIVATE $<IF:$<BOOL:${USE_SYSTEM_CATCH}>,USE_SYSTEM_CATCH,>)

enable_testing()


include(ParseAndAddCatchTests)
set(PARSE_CATCH_TESTS_VERBOSE OFF CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_NO_HIDDEN_TESTS ON CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_ADD_TARGET_IN_TEST_NAME OFF CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_ADD_FIXTURE_IN_TEST_NAME ON CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_ADD_TO_CONFIGURE_DEPENDS ON CACHE INTERNAL "")
ParseAndAddCatchTests(harness_os_catch2)
