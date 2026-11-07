#include "engine/ring_buffer.hpp"

namespace engine {

    bool RingBuffer::push(const Event& event) {
        if (full()) {
            return false;
        }

        buffer[write] = event;
        write = (write + 1) % BUFFER_SIZE;

        count++;
        return true;
    }

    bool RingBuffer::pop(Event& event) {
        if (empty()) {
            return false;
        }

        event = buffer[read];
        read = (read + 1) % BUFFER_SIZE;

        count--;
        return true;
    }

    bool RingBuffer::empty() const {
        return count == 0;
    }

    bool RingBuffer::full() const {
        return count == BUFFER_SIZE;
    }

    std::size_t RingBuffer::size() const {
        return count;
    }

} // namespace engine