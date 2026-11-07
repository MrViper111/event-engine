#pragma once

#include <array>
#include <cstddef>

#include "engine/event.hpp"

namespace engine {

    class RingBuffer {
        public:
            bool push(const Event& event);
            bool pop(Event& event);

            [[nodiscard]] bool empty() const;
            [[nodiscard]] bool full() const;
            [[nodiscard]] std::size_t size() const;

        private:
            static constexpr std::size_t BUFFER_SIZE = 1024;
            std::array<Event, BUFFER_SIZE> buffer{};

            std::size_t read = 0;
            std::size_t write = 0;
            std::size_t count = 0;
    };

} // namespace engine