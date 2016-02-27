#include "context.h"
#include "internal.h"

using namespace al;

namespace al {

class Context_impl {
  public:
    Context_impl();
    ~Context_impl();

  private:
    ALCdevice* _device;
    ALCcontext* _context;

};

}

Context_impl::Context_impl()
  : _device(alcOpenDevice(nullptr)) // TODO: non-default devices
  , _context(alcCreateContext(_device, nullptr))
{
  assert(_device);
  assert(_context);
  alcMakeContextCurrent(_context);
}

Context_impl::~Context_impl() {
  alcDestroyContext(_context);
  alcCloseDevice(_device);
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

