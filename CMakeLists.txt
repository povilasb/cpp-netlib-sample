cmake_minimum_required(VERSION 2.6)

# Configurable.

if (NOT DEFINED PROJECT_NAME)
	set(PROJECT_NAME "main")
endif(NOT DEFINED PROJECT_NAME)


project(${PROJECT_NAME} CXX)
set(PROJECT_EXEC "${PROJECT_NAME}")
set(PROJECT_LIB "lib${PROJECT_NAME}")


message(STATUS "Build type: ${CMAKE_BUILD_TYPE}.")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fstack-protector -s")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unused-parameter")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=unused-but-set-variable")

set(LIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

# cpp-netlib
set(BOOST_INCLUDEDIR "${LIBS_DIR}/boost")
include_directories("${BOOST_INCLUDEDIR}")
set(BOOST_LIBRARYDIR "${LIBS_DIR}/boost/libs")
set(CPP-NETLIB_BUILD_TESTS OFF)
set(CPP-NETLIB_BUILD_EXAMPLES OFF)
set(CPP-NETLIB_DISABLE_FEATURE_TESTS ON)
add_subdirectory("${LIBS_DIR}/cpp-netlib")
include_directories("${LIBS_DIR}/cpp-netlib")

message(STATUS "Boost thread lib: ${Boost_THREAD_LIBRARY}")


set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")

add_executable("${PROJECT_EXEC}" ${SRC_FILES})
target_link_libraries("${PROJECT_EXEC}" cppnetlib-client-connections
	cppnetlib-uri ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} pthread
	rt)
