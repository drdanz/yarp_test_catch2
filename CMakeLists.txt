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


include_directories("${CMAKE_CURRENT_SOURCE_DIR}/extern"
                    ${ACE_INCLUDE_DIRS})
add_executable(harness_os_catch2 harness.cpp
                                 libYARP_OS/BinPortableTest.cpp
                                 libYARP_OS/BottleTest.cpp
                                 libYARP_OS/ContactTest.cpp
                                 libYARP_OS/ElectionTest.cpp
                                 libYARP_OS/EventTest.cpp
                                 libYARP_OS/LogStreamTest.cpp
                                 libYARP_OS/LogTest.cpp
                                 libYARP_OS/NetTypeTest.cpp
                                 libYARP_OS/NetworkTest.cpp
                                 libYARP_OS/NodeTest.cpp
                                 libYARP_OS/PeriodicThreadTest.cpp
                                 libYARP_OS/PortablePairTest.cpp
                                 libYARP_OS/PortReaderBufferTest.cpp
                                 libYARP_OS/PortTest.cpp
                                 libYARP_OS/PropertyTest.cpp
                                 libYARP_OS/PublisherTest.cpp
                                 libYARP_OS/ResourceFinderTest.cpp
                                 libYARP_OS/RFModuleTest.cpp
                                 libYARP_OS/RouteTest.cpp
                                 libYARP_OS/SemaphoreTest.cpp
                                 libYARP_OS/StampTest.cpp)

target_link_libraries(harness_os_catch2 PRIVATE YARP::YARP_OS
                                                YARP::YARP_init
                                                YARP::YARP_sig
                                                YARP::YARP_dev
                                                YARP::YARP_serversql
                                                YARP::YARP_companion)
target_compile_definitions(harness_os_catch2 PRIVATE $<IF:$<BOOL:${USE_SYSTEM_CATCH}>,USE_SYSTEM_CATCH,>)


add_executable(harness_os_impl_catch2 harness.cpp
                                      libYARP_OS/impl/BufferedConnectionWriterTest.cpp
                                      libYARP_OS/impl/DgramTwoWayStreamTest.cpp
                                      libYARP_OS/impl/NameConfigTest.cpp
                                      libYARP_OS/impl/NameServerTest.cpp
                                      libYARP_OS/impl/PortCommandTest.cpp
                                      libYARP_OS/impl/PortCoreTest.cpp
                                      libYARP_OS/impl/ProtocolTest.cpp)

target_link_libraries(harness_os_impl_catch2 PRIVATE YARP::YARP_OS
                                                     YARP::YARP_init
                                                     YARP::YARP_sig
                                                     YARP::YARP_serversql
                                                     ${ACE_LIBRARIES})
target_compile_definitions(harness_os_impl_catch2 PRIVATE $<IF:$<BOOL:${USE_SYSTEM_CATCH}>,USE_SYSTEM_CATCH,>)


add_executable(harness_math_catch2 harness.cpp
                                   libYARP_math/MathTest.cpp)
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

