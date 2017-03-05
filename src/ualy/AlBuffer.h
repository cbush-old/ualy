#pragma once

#include <vector>

namespace al
{

enum class Format
{
    MONO8,
    MONO16,
    STEREO8,
    STEREO16,
};

class Buffer
{
public:
    /*!
     \brief Instantiates a new buffer using alGenBuffers. The buffer is released
        when this instance is destroyed.
    */
    Buffer();

    Buffer(Buffer const &) = delete;
    Buffer &operator=(Buffer const &) = delete;
    ~Buffer();

    /*!
     \return The OpenAL name of the buffer.
    */
    unsigned name() const;

    /*!
     \brief Assign buffer data to the buffer. Calls alBufferData.
    */
    template <typename T, typename Allocator>
    void data(Format format, std::vector<T, Allocator> const &buffer, size_t frequency)
    {
        data(format, buffer.data(), buffer.size() * sizeof(T), frequency);
    }

    /*!
     \brief Assign buffer data to the buffer. Calls alBufferData.
    */
    void data(Format format, const void *data, size_t size, size_t frequency);

private:
    unsigned _name;
};

} // namespace al
