#include "context.h"
#include "internal.h"

using namespace al;

namespace al {

struct Context_impl {
  Context_impl();
  ~Context_impl();
  ALCdevice* device;
  ALCcontext* context;
};

}

Context_impl::Context_impl()
  : device(alcOpenDevice(nullptr)) // TODO: non-default devices
  , context(alcCreateContext(device, nullptr))
{
  assert(device);
  assert(context);
  alcMakeContextCurrent(context);
}

Context_impl::~Context_impl() {
  alcDestroyContext(context);
  alcCloseDevice(device);
}


Context::Context()
  : _impl(new Context_impl)
  {}

Context::~Context() {
  delete _impl;
}

void Context::set_listener(Listener const& listener) {
  float orientation[6] {
    XYZ(listener.orientation.at),
    XYZ(listener.orientation.up) };
  AL_CALL(alListenerfv(AL_ORIENTATION, orientation));
  AL_CALL(alListener3f(AL_POSITION, XYZ(listener.position)));
  AL_CALL(alListener3f(AL_VELOCITY, XYZ(listener.velocity)));
}

void Context::process() {
  AL_CALL(alcProcessContext(_impl->context));
}

void Context::suspend() {
  AL_CALL(alcSuspendContext(_impl->context));
}


