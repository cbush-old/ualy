#pragma once

#include <vector>

namespace al {

enum class Format {
  MONO8,
  MONO16,
  STEREO8,
  STEREO16,
};

class Buffer {
  public:
    Buffer();
    ~Buffer();

  public:
    unsigned name() const;

    template<typename T>
    void data(Format format, std::vector<T> data, size_t frequency) {
      data(format, data.data(), data.size() * sizeof(T), frequency);
    }

  public:
    void data(
      Format format,
      const void* data,
      size_t size,
      size_t frequency
    );

  private:
    unsigned _name;

};



}
