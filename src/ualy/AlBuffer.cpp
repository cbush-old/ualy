#include "AlBuffer.h"
#include "AlInternal.h"

using namespace al;

namespace
{

ALenum format_to_enum(Format format)
{
    switch (format)
    {
    case Format::MONO8:
        return AL_FORMAT_MONO8;
    case Format::MONO16:
        return AL_FORMAT_MONO16;
    case Format::STEREO8:
        return AL_FORMAT_STEREO8;
    case Format::STEREO16:
        return AL_FORMAT_STEREO16;
    }
}

} // namespace

Buffer::Buffer()
    : _name(0)
{
    AL_CALL(alGenBuffers(1, &_name));
}

Buffer::~Buffer()
{
    AL_CALL(alDeleteBuffers(1, &_name));
    _name = 0;
}

unsigned Buffer::name() const
{
    return _name;
}

void Buffer::data(Format format, const void *data, size_t size, size_t frequency)
{
    AL_CALL(alBufferData(
        _name,
        format_to_enum(format),
        data,
        (ALsizei)size,
        (ALsizei)frequency)
    );
}

