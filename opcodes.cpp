#include "Z80.h"

namespace emulator::cpu {
    void Z80::nop() {}

    void Z80::ld_a() {
       A_ = Instance().arg;
    }

    void Z80::ld_bc() {
       BC_ = Instance().argWord;
    }

    void Z80::ld_b() {
        B_ = Instance().arg;
    }

    void Z80::inc_bc() {
        BC_++;
    }

    void Z80::inc_b() {
       Z80::inc(B_);
    }

    void Z80::dec_b() {
        Z80::dec(B_);
    }

    void Z80::rlca() {
        Instance().statusSet(Z80::FlagBit::Z, false);
        Instance().statusSet(Z80::FlagBit::N,false);
        Instance().statusSet(Z80::FlagBit::C,Instance().registers.A & 0x80);
        A_ = (A_ << 1) + Instance().statusGet(Z80::FlagBit::C);
    }

    void Z80::ex_af() {
        std::swap(AF_, AF__);
    }

    void Z80::ld_bc_a(){
        Instance().ram.writeByte(Instance().registers.BC, A_);
    };

}