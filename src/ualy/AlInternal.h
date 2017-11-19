#pragma once

#include "ualy/AlException.h"
#include "ualy/AlContext.h"

#include <al.h>
#include <alc.h>
#include <cassert>

#define XYZ(param) param.x, param.y, param.z

#define AL_CALL(...)                                                           \
    __VA_ARGS__;                                                               \
    {                                                                          \
        ALenum error = alGetError();                                           \
        if (error != AL_NO_ERROR && error != -1)                               \
        {                                                                      \
            throw al::exception("al call " #__VA_ARGS__ " failed: %d", error); \
        }                                                                      \
    }
