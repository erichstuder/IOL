cmake_minimum_required(VERSION 3.18.4)

project(simulator VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "" FORCE)



#add_definitions(-DCUCUMBER)

#add_library(simulator_lib STATIC ../simulator.cpp)
#target_sources(simulator_lib PRIVATE "../../firmware/lib/LedPatterns/Wave.cpp")
#target_include_directories(simulator_lib PRIVATE "../gnuplot-iostream/")
#target_include_directories(simulator_lib PRIVATE "../../firmware/lib/LedPatterns/")
#target_link_libraries(simulator_lib boost_iostreams boost_system boost_filesystem)




#add_library(dummy_lib STATIC "IO-Link Interface and System/Annex A/A.2 M-sequence types/A.2 M-sequence types.cpp")
#add_library(dummy_lib2 STATIC "IO-Link Interface and System/9 System Management/9.3 System Management of the Device/9.3.2 SM Device services/9.3.2.2 SM_SetDeviceCom/9.3.2.2 SM_SetDeviceCom.cpp")

#target_compile_options(dummy_lib PRIVATE -Wall -Wextra -Wpedantic -Werror -Wno-deprecated -Wno-deprecated-declarations)




# see: https://github.com/cucumber/cucumber-cpp/issues/36
function(add_cucumber_executable)
	add_executable(steps ${ARGV})
	foreach(file_name ${ARGN})
		get_filename_component(prefix ${file_name} NAME_WE)
		set_source_files_properties(${file_name} PROPERTIES COMPILE_FLAGS "-DCUKE_OBJECT_PREFIX=_${prefix}")
        endforeach()
endfunction()


add_cucumber_executable(
	"IO-Link Interface and System/Annex A/A.2/M_sequence_types.cpp"
	"IO-Link Interface and System/9/9.3/9.3.2/9.3.2.2/SM_SetDeviceCom.cpp"
	"IO-Link Interface and System/Annex A/A.2/features/step_definitions/M_sequence_types__steps.cpp"
	"IO-Link Interface and System/9/9.3/9.3.2/9.3.2.2/features/step_definitions/SM_SetDeviceCom__steps.cpp"
	"IO-Link Interface and System/8/8.3/8.3.2/8.3.2.3/features/step_definitions/Figure_61__steps.cpp"
	
	"IO-Link Interface and System/7/7.3/7.3.6/7.3.6.3/State_machine_of_the_Master_ISDU_handler.cpp"
	"IO-Link Interface and System/7/7.3/7.3.6/7.3.6.3/components/States.cpp"
	"IO-Link Interface and System/7/7.3/7.3.6/7.3.6.3/components/Transitions.cpp"
	"IO-Link Interface and System/7/7.3/7.3.6/7.3.6.3/features/steps/State_machine_of_the_Master_ISDU_handler__steps.cpp"
	"IO-Link Interface and System/7/7.3/7.3.6/7.3.6.3/features/steps/Transitions_mock.cpp"
)
target_include_directories(steps PRIVATE "/usr/src/cucumber-cpp/build/gmock/src/gmock/googletest/include")
target_include_directories(steps PRIVATE "/usr/src/cucumber-cpp/build/gmock/src/gmock/googlemock/include")
target_include_directories(steps PRIVATE "/usr/src/cucumber-cpp/include")
target_include_directories(steps PRIVATE "/usr/src/cucumber-cpp/build/src")
target_include_directories(steps PRIVATE "IO-Link Interface and System/Annex A/A.2")
target_include_directories(steps PRIVATE "IO-Link Interface and System/9/9.3/9.3.2/9.3.2.2")
target_include_directories(steps PRIVATE "IO-Link Interface and System/7/7.3/7.3.6/7.3.6.3")
target_include_directories(steps PRIVATE "IO-Link Interface and System/7/7.3/7.3.6/7.3.6.3/components")
target_include_directories(steps PRIVATE "IO-Link Interface and System/7/7.3/7.3.6/7.3.6.3/features/steps")
target_link_libraries(steps PRIVATE
	#dummy_lib
	#dummy_lib2
	"/lib/libcucumber-cpp.a"
	"/usr/src/cucumber-cpp/build/gmock/src/gmock-build/lib/libgtest.a"
	"/usr/src/cucumber-cpp/build/gmock/src/gmock-build/lib/libgmock.a"
	boost_iostreams boost_system boost_filesystem boost_regex boost_program_options
)
target_compile_options(steps PRIVATE -Wall -Wextra -Wpedantic -Werror -Wno-deprecated -Wno-deprecated-declarations)
