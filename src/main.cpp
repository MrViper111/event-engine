#include <iostream>
#include "engine/event.hpp"

int main() {
    const engine::Payload payload{.topic = engine::EventTopic::RANDOM, .message = "test"};
    const engine::Event event{.sequence = 1, .payload = payload};

    std::cout << "event-engine: project skeleton; pub/sub is not implemented yet.\n";
    return 0;
}
