cmake_minimum_required(VERSION 3.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


project(CHIP8_Emulator)

# Source files
set(SOURCE_FILES
  src/main.cpp
  src/chip8.cpp
)

# Include headers
include_directories(src)

# Create executable
add_executable(chip8_emulator ${SOURCE_FILES})