#ifndef CHIP8_EMULATOR_H
#define CHIP8_EMULATOR_H

#include <stdint.h>
#include <string>
#include <array>


class Chip8 {
public:
    Chip8();

    ~Chip8();

    bool load(const char *file_path);
    void cycle();

private:
    std::array<uint16_t, 16> stack{};
    uint8_t sp;

    uint16_t pc;
    uint16_t I;
    uint16_t current_opcode;

    std::array<uint8_t, 4096> memory{};
    std::array<uint8_t, 16> V{};

    uint8_t delay_timer;
    uint8_t sound_timer;

    std::array<uint8_t, 16> keypad{};
    std::array<uint8_t, 64 * 32> graphics_display{};
    bool draw_flag;

    void initialise();
};

#endif //CHIP8_EMULATOR_H

