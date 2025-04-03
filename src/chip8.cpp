#include "chip8.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <string>

unsigned char chip8_fontset[80] =
{
    0xF0, 0x90, 0x90, 0x90, 0xF0, //0
    0x20, 0x60, 0x20, 0x20, 0x70, //1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, //2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, //3
    0x90, 0x90, 0xF0, 0x10, 0x10, //4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, //5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, //6
    0xF0, 0x10, 0x20, 0x40, 0x40, //7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, //8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, //9
    0xF0, 0x90, 0xF0, 0x90, 0x90, //A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, //B
    0xF0, 0x80, 0x80, 0x80, 0xF0, //C
    0xE0, 0x90, 0x90, 0x90, 0xE0, //D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, //E
    0xF0, 0x80, 0xF0, 0x80, 0x80  //F
};

Chip8::Chip8() {}

Chip8::~Chip8() {}

void Chip8::initialise() {
    pc = 0x200;
    current_opcode = 0;
    I = 0;
    sp = 0;

    for (int i = 0; i < 2048; ++i) {
        graphics_display[i] = 0;
    }

    for (int i = 0; i < 16; ++i) {
        stack[i] = 0;
        keypad[i] = 0;
        V[i] = 0;
    }

    for (int i = 0; i < 4096; ++i) {
        memory[i] = 0;
    }

    for (int i = 0; i < 80; ++i) {
        memory[i] = chip8_fontset[i];
    }

    delay_timer = 0;
    sound_timer = 0;
}

bool Chip8::load(const char *file_path) {
    initialise();

    if (file_path == nullptr) {
        std::cerr << "Invalid file path" << std::endl;
        return false;
    }

    std::ifstream rom(file_path, std::ios::binary | std::ios::ate);
    if (!rom.is_open()) {
        std::cerr << "Failed to open ROM" << std::endl;
        return false;
    }

    std::streamsize rom_size = rom.tellg();
    rom.seekg(0, std::ios::beg);

    std::vector<uint8_t> rom_buffer(rom_size);
    if (!rom.read(reinterpret_cast<char*>(rom_buffer.data()), rom_size)) {
        std::cerr << "Failed to read ROM" << std::endl;
        return false;
    }

    constexpr size_t load_address = 0x200;
    constexpr size_t max_rom_size = 4096 - load_address;

    if (rom_size > max_rom_size) {
        std::cerr << "ROM too large to fit in memory" << std::endl;
        return false;
    }

    std::copy(rom_buffer.begin(), rom_buffer.end(), memory.begin() + load_address);

    return true;
}

void Chip8::cycle(){

}