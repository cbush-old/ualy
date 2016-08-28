#pragma once

namespace al {

struct vec3 {
  vec3() {}
  vec3(float v): x(v), y(v), z(v) {}
  vec3(float x, float y, float z): x(x), y(y), z(z) {}
  float x { 0.f };
  float y { 0.f };
  float z { 0.f };
};

struct orientation {
  orientation() {}
  orientation(vec3 const& at, vec3 const& up)
    : at(at), up(up) {}
  vec3 at;
  vec3 up;
};

}
