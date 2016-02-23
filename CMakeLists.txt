cmake_minimum_required (VERSION 2.6)
project (apostle)

set (SOURCES
     src/main.cpp
     src/objects.cpp
     src/world.cpp
     src/window.cpp
     src/noise.cpp
     src/tools.cpp
     src/viewport.cpp)

set (HEADERS
     src/objects.hpp
     src/entity.hpp
     src/actor.hpp
     src/world.hpp
     src/window.hpp
     src/noise.hpp
     src/tools.hpp
     src/viewport.hpp)

add_executable (apostle ${SOURCES} ${HEADERS})
find_package (SDL2 REQUIRED)
include_directories (${SDL2_INCLUDE_DIRS})
target_link_libraries (apostle ${LIBS} ${SDL2_LIBRARIES})
