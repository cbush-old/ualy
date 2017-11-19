#pragma once

#include "ualy/AlSpatial.h"

#include <string>

struct ALCcontext_struct;
struct ALCdevice_struct;

namespace al
{

struct Listener
{
    vec3 position;
    vec3 velocity;
    float gain{ 1.f };
    orientation orientation;
};

class Context
{
public:
    /*!
     \details Instantiate a context with the default device.
    */
    Context();
    
    /*!
     \details Instantiate a context using the given device name.
    */
    Context(char const *device_name);
    
    Context(std::string const &device_name);

    Context(Context const &) = delete;
    Context &operator=(Context const &) = delete;
    ~Context();

    void set_listener(Listener const &);

    void process();

    void suspend();
    
    void set_doppler_factor(float factor);

    /*!
     \brief Set the speed of sound.
    */
    void set_speed_of_sound(float meters_per_sec);

private:
    ALCdevice_struct *_device;
    ALCcontext_struct *_context;
    
    friend class ScopeGuard;
};

} // namespace al
