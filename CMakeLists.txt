cmake_minimum_required(VERSION 3.0)

project(ualy)

set(REL_SRC_DIR     ./src)

file(GLOB_RECURSE SRC_FILES "${REL_SRC_DIR}/*.h" "${REL_SRC_DIR}/*.cpp")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Werror")

find_package(OpenAL REQUIRED)

include_directories(SYSTEM ${OPENAL_INCLUDE_DIR})

include_directories(${REL_SRC_DIR})

add_library(ualy        STATIC ${SRC_FILES})

target_link_libraries(ualy ${OPENAL_LIBRARY})

message(STATUS "OpenAL include dir: ${OPENAL_INCLUDE_DIR}")
message(STATUS "OpenAL library: ${OPENAL_LIBRARY}")
