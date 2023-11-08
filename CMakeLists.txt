cmake_minimum_required(VERSION 3.18.4)

project(feature_tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# see: https://github.com/cucumber/cucumber-cpp/issues/36
function(add_cucumber_executable)
	add_executable(steps ${ARGV})
	foreach(file_name ${ARGN})
		get_filename_component(prefix ${file_name} NAME_WE)
		set_source_files_properties(${file_name} PROPERTIES COMPILE_FLAGS "-DCUKE_OBJECT_PREFIX=_${prefix}")
        endforeach()
endfunction()

file(GLOB_RECURSE cpp_files CONFIGURE_DEPENDS "IO-Link Interface and System/*.cpp")
file(GLOB_RECURSE h_files CONFIGURE_DEPENDS "IO-Link Interface and System/*.h")

set(include_dirs "")
foreach(h_file_path ${h_files})
	get_filename_component(dir_path ${h_file_path} PATH)
	set(include_dirs ${include_dirs} ${dir_path})
endforeach()

add_cucumber_executable(${cpp_files})
target_include_directories(steps PRIVATE ${include_dirs})
target_include_directories(steps PRIVATE "/usr/src/cucumber-cpp/build/gmock/src/gmock/googletest/include")
target_include_directories(steps PRIVATE "/usr/src/cucumber-cpp/include")
target_include_directories(steps PRIVATE "/usr/src/cucumber-cpp/build/src")
target_link_libraries(steps PRIVATE
	"/lib/libcucumber-cpp.a"
	"/usr/src/cucumber-cpp/build/gmock/src/gmock-build/lib/libgtest.a"
	boost_iostreams boost_system boost_filesystem boost_regex boost_program_options
)
target_compile_options(steps PRIVATE -Wall -Wextra -Wpedantic -Werror -Wno-deprecated -Wno-deprecated-declarations)
