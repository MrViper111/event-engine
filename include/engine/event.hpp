#pragma once

#include <cstdint>

#include "payload.hpp"

namespace engine {

    struct Event {
        std::uint32_t sequence{};
        engine::Payload payload;
    };

} // namespace engine
