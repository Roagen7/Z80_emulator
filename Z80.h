#pragma once

#include <cstdint>
#include <map>
#include <string>
#include "type.h"
#include "Memory.h"

#define CODE_START 0x0

namespace emulator::cpu {

    class Z80 {

    public:
        Z80(const Z80& other) = delete;
        Z80(Z80&& other) = delete;
        Z80& operator=(const Z80&) = delete;
        Z80& operator=(Z80&&) = delete;


        //static interface for CPU
        static void Load(const std::string&);
        static void Tick();
        static void Reset();
        static bool Run();
        static Z80& Instance(); // for debugging
    private:

        enum class FlagBit {
            C = 0b00000001,
            N = 0b00000010,
           PV = 0b00000100,
           X1 = 0b00001000,
            H = 0b00010000,
           X2 = 0b00100000,
            Z = 0b01000000,
            S = 0b10000000
        };

        memory::Memory ram{};
        uint8_t arg{};
        uint16_t argWord{};
        uint16_t addr{};
        bool run{true};

        uint8_t cycles{};
        type::registers_t registers{};
        type::registers_t alternate{};
        std::map<uint8_t, type::instruction_t> lookup;
        type::instruction_t instruction;

        void initLookup();
        Z80();

        void statusSet(const FlagBit& bit, bool value);
        [[nodiscard]] bool statusGet(const FlagBit& bit) const;

        //BYTE
        static void imm(), imp();
        //WORD
        static void immWord();

        static void nop(), lda(), ldbc(), ldb();

    };



}

