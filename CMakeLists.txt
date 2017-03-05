cmake_minimum_required(VERSION 3.0)

project(ualy)

set(REL_SRC_DIR     ./src)

file(GLOB_RECURSE SRC_FILES "${REL_SRC_DIR}/*.h" "${REL_SRC_DIR}/*.cpp")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Werror")

include_directories(SYSTEM /System/Library/Frameworks/OpenAL.framework/Headers)

include_directories(${REL_SRC_DIR})

add_library(ualy        STATIC ${SRC_FILES})
