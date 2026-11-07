#pragma once

#include <cstdint>
#include <string>

namespace engine {

    enum class EventTopic {
        RANDOM
    };

    struct Payload {
        EventTopic topic;
        std::string message;
    };

} // namespace engine
