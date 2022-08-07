#pragma once

#include <cstdint>
#include <functional>

namespace emulator::type {

    struct instruction_t {

        std::function<void()> addressingMode;
        std::function<void()> opcode;

        uint8_t cycles;

    };

    struct registers_t {

        uint16_t PC, SP, IX, IY;
        uint8_t I, R;

        union {
            struct {
                uint8_t F, A;
            };
            uint16_t AF;
        };
        union {
            struct {
                uint8_t C, B;
            };
            uint16_t BC;
        };
        union {
            struct {
                uint8_t E, D;
            };
            uint16_t DE;
        };
        union {
            struct {
                uint8_t L, H;
            };
            uint16_t HL;
        };
    };

}