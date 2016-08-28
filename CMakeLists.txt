cmake_minimum_required(VERSION 3.0)

project(ualy)

set(REL_SRC_DIR     ./src)

set(SRC_FILES
  ${REL_SRC_DIR}/ualy/buffer.cpp
  ${REL_SRC_DIR}/ualy/context.cpp
  ${REL_SRC_DIR}/ualy/source.cpp
)

set(INCLUDE_FILES
  ${REL_SRC_DIR}/ualy/buffer.h
  ${REL_SRC_DIR}/ualy/context.h
  ${REL_SRC_DIR}/ualy/exception.h
  ${REL_SRC_DIR}/ualy/internal.h
  ${REL_SRC_DIR}/ualy/source.h
  ${REL_SRC_DIR}/ualy/spatial.h
  ${REL_SRC_DIR}/ualy/ualy.h
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(SYSTEM /System/Library/Frameworks/OpenAL.framework/Headers)

include_directories(${REL_SRC_DIR})

add_library(ualy        STATIC ${SRC_FILES} ${INCLUDE_FILES})

