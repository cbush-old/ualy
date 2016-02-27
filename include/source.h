#pragma once

#include "spatial.h"

namespace al {

class Buffer;

class Source {
  public:
    Source();
    ~Source();
  
  public:
    /**
     * @brief play the source
     */
    void play();

    /**
     * @brief pause the source
     */
    void pause();
  
    /**
     * @brief stop the source
     */
    void stop();
  
    /**
     * @brief stop the source and reset the state
     */
    void rewind();

    /**
     * @brief attach a buffer to the source
     */
    void queue(Buffer const&);
  
    /**
     * @brief detach a buffer from the source
     **/
    void unqueue(Buffer const&);
  
    /**
     * @brief set the source position
     */
    void set_position(vec3 const& position);

    /**
     * @brief set the source direction vector
     */
    void set_direction(vec3 const& direction);

    /**
     * @brief set the source velocity
     */
    void set_velocity(vec3 const& velocity);
  
    /**
     * @brief set the source gain. default is 1.f
     */
    void set_gain(float gain);

  private:
    unsigned _name;

};


}

