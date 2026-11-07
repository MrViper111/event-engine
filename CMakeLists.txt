cmake_minimum_required(VERSION 3.20)
project(event_engine VERSION 0.1.0 LANGUAGES CXX)

add_library(engine STATIC src/engine.cpp
        include/engine/ring_buffer.hpp
        include/engine/event.hpp
        include/engine/payload.hpp
        include/engine/ring_buffer.hpp
        src/ring_buffer.cpp
)
add_library(engine::engine ALIAS engine)
target_include_directories(engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_compile_features(engine PUBLIC cxx_std_20)
set_target_properties(engine PROPERTIES CXX_EXTENSIONS OFF)

add_executable(event-engine src/main.cpp)
target_link_libraries(event-engine PRIVATE engine::engine)
set_target_properties(event-engine PROPERTIES CXX_EXTENSIONS OFF)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
