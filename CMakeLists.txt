cmake_minimum_required(VERSION 3.16)
project(CHIP8_Emulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCE_FILES
  src/main.cpp
  src/chip8.cpp
)

add_executable(chip8_emulator ${SOURCE_FILES})

find_package(SDL2 REQUIRED)

target_include_directories(chip8_emulator PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(chip8_emulator PRIVATE ${SDL2_LIBRARIES})
