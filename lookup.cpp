#include "Z80.h"

namespace emulator::cpu {

    void Z80::initLookup() {
        lookup = {
                {0x00, {imp, nop, 4}},
                {0x3e, {imm,  lda, 7}}
        };
    }
}