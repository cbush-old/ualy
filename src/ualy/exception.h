#pragma once

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <memory>

namespace al {

class exception : public std::exception {
  public:
    ~exception() {}

    template<typename... T>
    exception(const char* fmt, T const&... args)
      : _ss(new std::stringstream)
    {
      format(*_ss, fmt, args...);
    }

  public:
    const char* what() const noexcept override {
      return _ss->str().c_str();
    }

  protected:
    void format(std::ostream&, const char* fmt);

    template<typename T, typename... Args>
    void format(std::ostream&, const char* fmt, T const&, Args const&... args);

  protected:
    std::shared_ptr<std::stringstream> _ss;

};

inline void exception::format(std::ostream& os, const char* fmt) {
  os << fmt;
}

template<typename T, typename... Args>
inline void exception::format(std::ostream& os, const char* fmt, T const& value, Args const&... args) {
  while (*fmt) {  
    if (*fmt == '%') {
      if (fmt[1] == '%') {
        ++fmt;
      } else {
        // TODO: %x, %02d, etc.
        os << value;
        fmt += 2;
        format(os, fmt, args...);
        return;
      }
    }
    os << *fmt;
    ++fmt;
  }
}

} // namespace al

