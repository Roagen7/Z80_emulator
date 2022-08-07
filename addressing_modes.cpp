#include "Z80.h"

namespace emulator::cpu {

    void Z80::imm() {
        Instance().arg = Instance().ram[Instance().registers.PC + 1];
        Instance().registers.PC += 2;
    }

    void Z80::imp(){
        Instance().registers.PC += 1;
    }

    void Z80::immWord() {
        Instance().argWord = Instance().ram[Instance().registers.PC + 1]
                + Instance().ram[Instance().registers.PC+2] * 256;
        Instance().registers.PC += 3;
    }

}