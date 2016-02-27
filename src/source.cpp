#include "source.h"
#include "buffer.h"
#include "internal.h"

using namespace al;

Source::Source() {
  AL_CALL(alGenSources(1, &_name));
}

Source::~Source() {
  AL_CALL(alDeleteSources(1, &_name));
}

void Source::play() {
  AL_CALL(alSourcePlay(_name));
}

void Source::pause() {
  AL_CALL(alSourcePause(_name));
}

void Source::stop() {
  AL_CALL(alSourceStop(_name));
}

void Source::rewind() {
  AL_CALL(alSourceRewind(_name));
}

void Source::queue(Buffer const& buffer) {
  ALuint buffers[1] { buffer.name() };
  AL_CALL(alSourceQueueBuffers(_name, 1, buffers));
}

void Source::unqueue(Buffer const& buffer) {
  ALuint buffers[1] { buffer.name() };
  AL_CALL(alSourceUnqueueBuffers(_name, 1, buffers));
}

