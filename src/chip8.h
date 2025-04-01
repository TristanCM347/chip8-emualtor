#ifndef CHIP8_EMULATOR_H
#define CHIP8_EMULATOR_H

#include <stdint.h>
#include <string>


class Chip8 {
public:
    Chip8();

    ~Chip8();

    bool load(const char *file_path);

private:
    uint16_t stack[16];
    uint8_t sp;

    uint16_t pc;
    uint16_t I;
    uint16_t current_opcode;

    uint8_t memory[4096];
    uint8_t V[16];          // V registers (V0-VF)

    uint8_t delay_timer;
    uint8_t sound_timer;

    uint8_t keypad[16];
    uint8_t graphics_display[64 * 32];
    bool draw_flag;

    void initialise();
};

#endif //CHIP8_EMULATOR_H

