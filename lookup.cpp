#include "Z80.h"

namespace emulator::cpu {

    void Z80::initLookup() {
        lookup = {
                {0x00, {imp, nop, 4}},
                {0x01, {immWord, ldbc, 10}},
                {0x06, {imm, ldb, 7}},
                {0x3e, {imm,  lda, 7}}
        };
    }
}