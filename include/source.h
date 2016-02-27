#pragma once

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
     * @bruef detach a buffer from the source
     **/
    void unqueue(Buffer const&);


  private:
    unsigned _name;

};


}

