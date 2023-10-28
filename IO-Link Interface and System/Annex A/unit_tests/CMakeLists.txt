cmake_minimum_required(VERSION 3.18.4)

project(unit_tests_with_gtest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#later we may replace dummy.cpp with a real file from the project
add_executable(unit_tests example_test.cpp)
target_include_directories(unit_tests PRIVATE /usr/src/gtest/googletest/include/)
target_link_libraries(unit_tests /usr/lib/libgtest_main.a)
target_link_libraries(unit_tests /usr/lib/libgtest.a)
#target_link_libraries(unit_tests /usr/lib/libgmock_main.a)
#target_link_libraries(unit_tests /usr/lib/libgmock.a)






#add_library(simulator_lib STATIC ../simulator.cpp)
#target_sources(simulator_lib PRIVATE "../../firmware/lib/LedPatterns/Wave.cpp")
#target_include_directories(simulator_lib PRIVATE "../gnuplot-iostream/")
#target_include_directories(simulator_lib PRIVATE "../../firmware/lib/LedPatterns/")
#target_link_libraries(simulator_lib boost_iostreams boost_system boost_filesystem)

#add_library(dummy_lib STATIC "../M-sequence types.cpp")
#
#add_executable(steps "step_definitions/M-sequence types for the OPERATE mode.cpp")
#target_include_directories(steps PRIVATE "/usr/src/cucumber-cpp/build/gmock/src/gmock/googletest/include")
#target_include_directories(steps PRIVATE "/usr/src/cucumber-cpp/include")
#target_include_directories(steps PRIVATE "/usr/src/cucumber-cpp/build/src")
#target_include_directories(steps PRIVATE "..")
#target_link_libraries(steps PRIVATE
#    dummy_lib
#    "/lib/libcucumber-cpp.a"
#    "/usr/src/cucumber-cpp/build/gmock/src/gmock-build/lib/libgtest.a"
#    "/usr/src/cucumber-cpp/build/gmock/src/gmock-build/lib/libgmock.a"
#    boost_iostreams boost_system boost_filesystem boost_regex boost_program_options
#)
