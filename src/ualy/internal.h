#pragma once

#include <al.h>
#include <alc.h>
#include <assert.h>

#include "ualy/exception.h"

#define XYZ(param) param.x, param.y, param.z

#define AL_CALL(...) \
    __VA_ARGS__; {\
    ALenum error = alGetError(); \
    if (error != AL_NO_ERROR) { \
      throw al::exception("al call " #__VA_ARGS__ " failed: %d", error); \
    } \
  }


