#include "Z80.h"

namespace emulator::cpu {

    void Z80::imm() {
        Instance().arg = Instance().ram[PC_ + 1];
        PC_ += 2;
    }

    void Z80::imp(){
        Instance().registers.PC += 1;
    }

    void Z80::immWord() {
        Instance().argWord = Instance().ram[PC_ + 1]
                + Instance().ram[PC_+2] * 256;
        PC_ += 3;
    }

    void Z80::ind() {
        PC_ += 1;
    }

}