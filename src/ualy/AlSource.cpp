#include "AlSource.h"

#include "AlBuffer.h"
#include "AlContext.h"
#include "AlInternal.h"

using namespace al;

Source::Source()
    : _name(0)
    , _pitch_multiplier(1.f)
{
    AL_CALL(alGenSources(1, &_name));
}

Source::~Source()
{
    if (_name)
    {
        AL_CALL(alDeleteSources(1, &_name));
        _name = 0;
    }
}

Source &Source::operator=(Source &&other)
{
    assert(&other != this);
    std::swap(_name, other._name);
    std::swap(_pitch_multiplier, other._pitch_multiplier);
    return *this;
}

Source::Source(Source &&other)
    : _name(other._name)
    , _pitch_multiplier(other._pitch_multiplier)
{
    other._name = 0;
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

void Source::set_pitch(float multiplier)
{
    assert(multiplier >= 0.f);
    if (_pitch_multiplier != multiplier)
    {
        AL_CALL(alSourcef(_name, AL_PITCH, multiplier));
    }
}

bool Source::is_playing() const
{
    ALint state;
    AL_CALL(alGetSourcei(_name, AL_SOURCE_STATE, &state));
    return state == AL_PLAYING;
}
