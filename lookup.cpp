#include "Z80.h"

namespace emulator::cpu {

    void Z80::initLookup() {
        lookup = {
                {0x00, {imp, nop, 4}},
                {0x01, {immWord, ld_bc, 10}},

                {0x03, {imp, inc_bc, 6}},
                {0x04, {imp, inc_b, 4}},
                {0x05, {imp, dec_b, 4}},
                {0x06, {imm, ld_b, 7}},
                {0x07, {imp, rlca, 4}},
                {0x08, {imp, ex_af, 4}},

                {0x3e, {imm,  ld_a, 7}}
        };
    }
}