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
add_definitions("-DBUILDING_YARP")

option(USE_SYSTEM_CATCH "Use system catch.hpp" OFF)

enable_testing()


include(ParseAndAddCatchTests)
set(PARSE_CATCH_TESTS_VERBOSE OFF CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_NO_HIDDEN_TESTS ON CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_ADD_TARGET_IN_TEST_NAME OFF CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_ADD_FIXTURE_IN_TEST_NAME ON CACHE INTERNAL "")
set(PARSE_CATCH_TESTS_ADD_TO_CONFIGURE_DEPENDS ON CACHE INTERNAL "")
set(AdditionalCatchParameters "-s" "--use-colour" "yes")


include_directories("${CMAKE_CURRENT_SOURCE_DIR}/extern")


################################################################################
# OS

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
                                 libYARP_OS/StampTest.cpp
                                 libYARP_OS/StringInputStreamTest.cpp
                                 libYARP_OS/StringOutputStreamTest.cpp
                                 libYARP_OS/SystemInfoTest.cpp
                                 libYARP_OS/TerminatorTest.cpp
                                 libYARP_OS/ThreadTest.cpp
                                 libYARP_OS/TimerTest.cpp
                                 libYARP_OS/TimeTest.cpp
                                 libYARP_OS/ValueTest.cpp
                                 libYARP_OS/VocabTest.cpp)

target_link_libraries(harness_os_catch2 PRIVATE YARP::YARP_OS
                                                YARP::YARP_init
                                                YARP::YARP_sig
                                                YARP::YARP_dev
                                                YARP::YARP_serversql
                                                YARP::YARP_companion)

target_compile_definitions(harness_os_catch2 PRIVATE $<IF:$<BOOL:${USE_SYSTEM_CATCH}>,USE_SYSTEM_CATCH,>)

ParseAndAddCatchTests(harness_os_catch2)


################################################################################
# OS/impl

add_executable(harness_os_impl_catch2 harness.cpp
                                      libYARP_OS/impl/BufferedConnectionWriterTest.cpp
                                      libYARP_OS/impl/DgramTwoWayStreamTest.cpp
                                      libYARP_OS/impl/NameConfigTest.cpp
                                      libYARP_OS/impl/NameServerTest.cpp
                                      libYARP_OS/impl/PortCommandTest.cpp
                                      libYARP_OS/impl/PortCoreTest.cpp
                                      libYARP_OS/impl/ProtocolTest.cpp
                                      libYARP_OS/impl/StreamConnectionReaderTest.cpp)

target_include_directories(harness_os_impl_catch2 PRIVATE ${ACE_INCLUDE_DIRS})

target_link_libraries(harness_os_impl_catch2 PRIVATE YARP::YARP_OS
                                                     YARP::YARP_init
                                                     YARP::YARP_sig
                                                     YARP::YARP_serversql
                                                     ${ACE_LIBRARIES})

target_compile_definitions(harness_os_impl_catch2 PRIVATE $<IF:$<BOOL:${USE_SYSTEM_CATCH}>,USE_SYSTEM_CATCH,>)

ParseAndAddCatchTests(harness_os_impl_catch2)


################################################################################
# sig

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

ParseAndAddCatchTests(harness_sig_catch2)


################################################################################
# math

add_executable(harness_math_catch2 harness.cpp
                                   libYARP_math/MathTest.cpp)
target_link_libraries(harness_math_catch2 PRIVATE YARP::YARP_OS
                                                  YARP::YARP_init
                                                  YARP::YARP_serversql
                                                  YARP::YARP_sig
                                                  YARP::YARP_math)

target_compile_definitions(harness_math_catch2 PRIVATE $<IF:$<BOOL:${USE_SYSTEM_CATCH}>,USE_SYSTEM_CATCH,>)

ParseAndAddCatchTests(harness_math_catch2)


################################################################################
# dev

add_executable(harness_dev_catch2 harness.cpp
                                  libYARP_dev/AnalogWrapperTest.cpp
                                  libYARP_dev/ControlBoardRemapperTest.cpp
                                  libYARP_dev/FrameTransformClientTest.cpp
                                  libYARP_dev/MapGrid2DTest.cpp
                                  libYARP_dev/MultipleAnalogSensorsInterfacesTest.cpp
                                  libYARP_dev/PolyDriverTest.cpp
                                  libYARP_dev/robotDescriptionTest.cpp
                                  libYARP_dev/TestFrameGrabberTest.cpp)

target_link_libraries(harness_dev_catch2 PRIVATE YARP::YARP_OS
                                                 YARP::YARP_init
                                                 YARP::YARP_serversql
                                                 YARP::YARP_sig
                                                 YARP::YARP_math
                                                 YARP::YARP_dev)

target_compile_definitions(harness_dev_catch2 PRIVATE $<IF:$<BOOL:${USE_SYSTEM_CATCH}>,USE_SYSTEM_CATCH,>)

ParseAndAddCatchTests(harness_dev_catch2)


################################################################################
# devices

add_executable(harness_devices harness_devices.cpp)

target_link_libraries(harness_devices PRIVATE YARP::YARP_OS
                                              YARP::YARP_init
                                              YARP::YARP_dev)



################################################################################
# print value table

add_executable(print_value_table print_value_table.cpp)

target_link_libraries(print_value_table PRIVATE YARP::YARP_OS
                                                YARP::YARP_init)


