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
        static Z80& Instance();
    private:

        memory::Memory ram{};
        uint8_t arg{};
        uint16_t argWord{};
        uint16_t addr{};
        bool run{true};

        type::registers_t registers{};
        type::registers_t alternate{};
        std::map<uint8_t, type::instruction_t> lookup;

        void initLookup();
        Z80();


        //BYTE
        static void imm(), imp();
        //WORD
        static void immWord();

        static void nop(), lda(), ldbc(), ldb();

    };



}

