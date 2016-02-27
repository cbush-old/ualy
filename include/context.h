#pragma once

#include "spatial.h"

namespace al {

struct Source {
  vec3 position;
  vec3 velocity;
  float gain { 1.f };
};

struct Listener : public Source {
  orientation orientation;
};

class Context {
  public:
    Context();
    ~Context();

  public:
    void set_listener(Listener const&);

  private:
    class Context_impl* _impl;

};


}


