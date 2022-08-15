#pragma once

#include <cstdint>
#include <map>
#include <string>
#include "type.h"
#include "Memory.h"

#define CODE_START 0x0

#define I_R Instance().registers
#define I_P Instance().alternate

#define A_ I_R.A
#define B_ I_R.B
#define C_ I_R.C
#define D_ I_R.D
#define E_ I_R.E
#define H_ I_R.H
#define L_ I_R.L
#define F_ I_R.F
#define PC_ I_R.PC
#define AF_ I_R.AF
#define BC_ I_R.BC
#define DE_ I_R.DE
#define HL_ I_R.HL

#define A__ I_P.A
#define B__ I_P.B
#define C__ I_P.C
#define D__ I_P.D
#define E__ I_P.E
#define H__ I_P.H
#define L__ I_P.L
#define F__ I_P.F

#define AF__ I_P.AF
#define BC__ I_P.BC
#define DE__ I_P.DE
#define HL__ I_P.HL

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
            C = 0b00000001, // Carry
            N = 0b00000010, // Add/Subtract
           PV = 0b00000100, // Parity/Overflow
           X1 = 0b00001000, // Not used
            H = 0b00010000, // Half Carry
           X2 = 0b00100000, // Not used
            Z = 0b01000000, // Zero
            S = 0b10000000 // Sign
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
        static void imm(), imp(), ind();
        //WORD
        static void immWord();

        static void nop(), ld_a(), ld_bc(), ld_b(),
                    inc_bc(), inc_b(), dec_b(),
                    rlca(), ex_af(), ld_bc_a();

        static void inc(uint8_t& reg);
        static void dec(uint8_t& reg);
        static bool IsOverflowAdd(uint8_t x, uint8_t y);
        static bool IsOverflowSub(uint8_t x, uint8_t y);
        static bool IsHalfCarryAdd(uint8_t x, uint8_t y);
        static bool IsHalfCarrySub(uint8_t x, uint8_t y);

    };



}

