#pragma once

#include "spatial.h"

namespace al {

struct Listener {
  vec3 position;
  vec3 velocity;
  float gain { 1.f };
  orientation orientation;
};

class Context {
  public:
    Context();
    ~Context();

  public:
    void set_listener(Listener const&);
  
  public:
    void process();
    void suspend();

  private:
    class Context_impl* _impl;

};


}


