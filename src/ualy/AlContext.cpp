#include "AlContext.h"
#include "AlInternal.h"

using namespace al;

Context::Context(char const *device_name)
    : _device(alcOpenDevice(device_name))
    , _context(alcCreateContext(_device, nullptr))
{
    if (!_context)
    {
        throw exception("failed to create context!");
    }
    AL_CALL(alcMakeContextCurrent(_context));
}

Context::Context()
    : Context(nullptr)
{}

Context::Context(std::string const &device_name)
    : Context(device_name.c_str())
{}

Context::~Context()
{
    AL_CALL(alcMakeContextCurrent(nullptr));
    AL_CALL(alcDestroyContext(_context));
    _context = nullptr;
    
    AL_CALL(alcCloseDevice(_device));
}

void Context::set_listener(Listener const &listener)
{
    float orientation[6]
    {
        XYZ(listener.orientation.at),
        XYZ(listener.orientation.up)
    };
    AL_CALL(alListenerf(AL_GAIN, listener.gain));
    AL_CALL(alListenerfv(AL_ORIENTATION, orientation));
    AL_CALL(alListener3f(AL_POSITION, XYZ(listener.position)));
    AL_CALL(alListener3f(AL_VELOCITY, XYZ(listener.velocity)));
}

void Context::process()
{
    AL_CALL(alcProcessContext(_context));
}

void Context::suspend()
{
    AL_CALL(alcSuspendContext(_context));
}

void Context::set_doppler_factor(float factor)
{
    AL_CALL(alDopplerFactor(factor));
}

void Context::set_speed_of_sound(float meters_per_sec)
{
    AL_CALL(alSpeedOfSound(meters_per_sec));
}
