#include "Z80.h"

namespace emulator::cpu {

    void Z80::lda() {
        Instance().registers.A = Instance().arg;
    }

    void Z80::nop() {

    }
}