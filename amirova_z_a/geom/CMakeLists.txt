cmake_minimum_required (VERSION 3.8)

project(geom)
include_directories(.)

# Add source to this project's executable.
add_executable (geom "geom.cpp" "geom.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET geom PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
