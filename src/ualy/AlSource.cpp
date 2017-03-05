#include "AlSource.h"

#include "AlBuffer.h"
#include "AlContext.h"
#include "AlInternal.h"

using namespace al;

Source::Source()
{
    AL_CALL(alGenSources(1, &_name));
}

Source::~Source()
{
    AL_CALL(alDeleteSources(1, &_name));
    _name = 0;
}

void Source::play()
{
    AL_CALL(alSourcePlay(_name));
}

void Source::pause()
{
    AL_CALL(alSourcePause(_name));
}

void Source::stop()
{
    AL_CALL(alSourceStop(_name));
}

void Source::rewind()
{
    AL_CALL(alSourceRewind(_name));
}

void Source::queue(Buffer const &buffer)
{
    ALuint buffer_name = buffer.name();
    AL_CALL(alSourceQueueBuffers(_name, 1, &buffer_name));
}

void Source::unqueue(Buffer const &buffer)
{
    ALuint buffer_name = buffer.name();
    AL_CALL(alSourceUnqueueBuffers(_name, 1, &buffer_name));
}

void Source::set_position(vec3 const &position)
{
    AL_CALL(alSource3f(_name, AL_POSITION, XYZ(position)));
}

void Source::set_direction(vec3 const &direction)
{
    AL_CALL(alSource3f(_name, AL_DIRECTION, XYZ(direction)));
}

void Source::set_velocity(vec3 const &velocity)
{
    AL_CALL(alSource3f(_name, AL_VELOCITY, XYZ(velocity)));
}

void Source::set_gain(float gain)
{
    assert(gain >= 0.f);
    AL_CALL(alSourcef(_name, AL_GAIN, gain));
}
