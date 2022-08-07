#include "Z80.h"

namespace emulator::cpu {
    void Z80::nop() {

    }

    void Z80::lda() {
        Instance().registers.A = Instance().arg;
    }

    void Z80::ldbc() {
        Instance().registers.BC = Instance().argWord;
    }

    void Z80::ldb() {
        Instance().registers.B = Instance().arg;
    }
}