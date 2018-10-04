cmake_minimum_required(VERSION 3.0)
project(test_catch2)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(YARP 3.1 REQUIRED COMPONENTS OS
                                          sig
                                          dev
                                          math
                                          serversql
                                          companion
                                          gsl)

find_package(ACE REQUIRED)

set(CMAKE_C_FLAGS ${YARP_C_FLAGS})
set(CMAKE_CXX_FLAGS ${YARP_CXX_FLAGS})

option(USE_SYSTEM_CATCH "Use system catch.hpp" OFF)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}
                    ${ACE_INCLUDE_DIRS})
add_executable(harness_os_catch2 harness.cpp
                                 BinPortableTest.cpp
                                 BottleTest.cpp
                                 ContactTest.cpp
                                 ElectionTest.cpp
                                 EventTest.cpp
                                 LogStreamTest.cpp
                                 LogTest.cpp
                                 NetTypeTest.cpp
                                 NetworkTest.cpp
                                 NodeTest.cpp
                                 PeriodicThreadTest.cpp
                                 PortablePairTest.cpp
                                 PortReaderBufferTest.cpp
                                 PortTest.cpp
                                 PropertyTest.cpp
                                 PublisherTest.cpp
                                 ResourceFinderTest.cpp
                                 RFModuleTest.cpp
                                 RouteTest.cpp)

target_link_libraries(harness_os_catch2 PRIVATE YARP::YARP_OS
                                                YARP::YARP_init
                                                YARP::YARP_sig
                                                YARP::YARP_dev
                                                YARP::YARP_serversql
                                                YARP::YARP_companion)
target_compile_definitions(harness_os_catch2 PRIVATE $<IF:$<BOOL:${USE_SYSTEM_CATCH}>,USE_SYSTEM_CATCH,>)


add_executable(harness_os_impl_catch2 harness.cpp
                                      BufferedConnectionWriterTest.cpp
                                      DgramTwoWayStreamTest.cpp
                                      NameConfigTest.cpp
                                      NameServerTest.cpp
                                      PortCommandTest.cpp
                                      PortCoreTest.cpp
                                      ProtocolTest.cpp)

target_link_libraries(harness_os_impl_catch2 PRIVATE YARP::YARP_OS
                                                     YARP::YARP_init
                                                     YARP::YARP_sig
                                                     YARP::YARP_serversql
                                                     ${ACE_LIBRARIES})
target_compile_definitions(harness_os_impl_catch2 PRIVATE $<IF:$<BOOL:${USE_SYSTEM_CATCH}>,USE_SYSTEM_CATCH,>)


add_executable(harness_math_catch2 harness.cpp
                                   MathTest.cpp)
target_link_libraries(harness_math_catch2 PRIVATE YARP::YARP_OS
                                                  YARP::YARP_init
                                                  YARP::YARP_serversql
                                                  YARP::YARP_sig
                                                  YARP::YARP_math
                                                  ${ACE_LIBRARIES})
target_compile_definitions(harness_math_catch2 PRIVATE $<IF:$<BOOL:${USE_SYSTEM_CATCH}>,USE_SYSTEM_CATCH,>)

add_executable(harness_sig_catch2 harness.cpp
                                  libYARP_sig/ImageTest.cpp
                                  libYARP_sig/MatrixTest.cpp
                                  libYARP_sig/PointCloudTest.cpp
                                  libYARP_sig/SoundTest.cpp
                                  libYARP_sig/VectorOfTest.cpp
                                  libYARP_sig/VectorTest.cpp)
target_link_libraries(harness_sig_catch2 PRIVATE YARP::YARP_OS
                                                 YARP::YARP_init
                                                 YARP::YARP_serversql
                                                 YARP::YARP_sig
                                                 YARP::YARP_gsl)
target_compile_definitions(harness_sig_catch2 PRIVATE $<IF:$<BOOL:${USE_SYSTEM_CATCH}>,USE_SYSTEM_CATCH,>)


enable_testing()


include(ParseAndAddCatchTests)
set(PARSE_CATCH_TESTS_VERBOSE OFF CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_NO_HIDDEN_TESTS ON CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_ADD_TARGET_IN_TEST_NAME OFF CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_ADD_FIXTURE_IN_TEST_NAME ON CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_ADD_TO_CONFIGURE_DEPENDS ON CACHE INTERNAL "")
ParseAndAddCatchTests(harness_os_catch2)
ParseAndAddCatchTests(harness_os_impl_catch2)
ParseAndAddCatchTests(harness_math_catch2)
ParseAndAddCatchTests(harness_sig_catch2)

