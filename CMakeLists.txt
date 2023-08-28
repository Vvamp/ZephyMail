cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Zephymail)

# Include header files
include_directories(include)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add executable
add_executable(Zephymail ${SOURCES})
