cmake_minimum_required(VERSION 2.6)

# Configurable.


project(main CXX)
set(project_exec "${PROJECT_NAME}")


message(STATUS "Build type: ${CMAKE_BUILD_TYPE}.")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fstack-protector -s")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unused-parameter")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unused-but-set-variable")

set(LIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

# cpp-netlib
set(CPP-NETLIB_BUILD_TESTS OFF)
set(CPP-NETLIB_BUILD_EXAMPLES OFF)
set(CPP-NETLIB_DISABLE_FEATURE_TESTS ON)
add_subdirectory("${LIBS_DIR}/cpp-netlib")

find_package(cppnetlib REQUIRED)
include_directories(${CPPNETLIB_INCLUDE_DIRS})

# Boost
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTI_THREADED ON)
find_package(Boost REQUIRED system thread)


set(src_dir "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB_RECURSE src_files "${src_dir}/*.cpp")

add_executable("${project_exec}" ${src_files})
target_link_libraries("${project_exec}" ${CPPNETLIB_LIBRARIES}
	${Boost_LIBRARIES} pthread rt)
