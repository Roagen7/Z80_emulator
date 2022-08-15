#include "Z80.h"

namespace emulator::cpu {

    Z80 &Z80::Instance() {
        static Z80 instance;

        return instance;
    }

    Z80::Z80() {
        initLookup();
    }


    void Z80::Load(const std::string& location) {

        auto file = fopen(location.c_str(),"rb");

        fseek(file,0,SEEK_END);

        long size = ftell(file);

        fseek(file, 0, SEEK_SET);

        auto* buffer = new uint8_t[size];

        fread(buffer,size,1,file);

        fclose(file);

        for(int i = 0; i < size; i++){

            Instance().ram.writeByte(i + CODE_START, buffer[i]);

        }

        delete[] buffer;

    }

    void Z80::Tick() {

        if(Instance().cycles == 0){
            auto opc = Instance().ram[Instance().registers.PC];
            Instance().instruction = Instance().lookup[opc];
            Instance().instruction.addressingMode();
            Instance().cycles++;
        } else if(Instance().cycles < Instance().instruction.cycles){
            Instance().cycles++;
        } else {
            Instance().instruction.opcode();
            Instance().cycles = 0;
        }
    }

    void Z80::Reset() {

    }

    bool Z80::Run() {
        return Instance().run;
    }

    bool Z80::statusGet(const Z80::FlagBit& bit) const {
        return (registers.F & (uint8_t) bit) > 0;
    }

    void Z80::statusSet(const Z80::FlagBit& bit, bool value) {

        if(value)
            registers.F |= (uint8_t)bit;
        else
            registers.F &= ~(uint8_t)bit;
    }

    void Z80::inc(uint8_t& reg) {
        Instance().statusSet(Z80::FlagBit::N, false);
        Instance().statusSet(Z80::FlagBit::PV, Z80::IsOverflowAdd(reg, 1));
        Instance().statusSet(Z80::FlagBit::H, Z80::IsHalfCarryAdd(reg,1));
        Instance().statusSet(Z80::FlagBit::Z, (reg + 1) == 0x00);
        Instance().statusSet(Z80::FlagBit::S, (bool) ((reg + 1) & 0x80));
        reg++;
    }

    void Z80::dec(uint8_t &reg) {
        Instance().statusSet(Z80::FlagBit::N, true);
        Instance().statusSet(Z80::FlagBit::PV, Z80::IsOverflowSub(reg, 1u));
        Instance().statusSet(Z80::FlagBit::H, Z80::IsHalfCarrySub(reg,1u));
        Instance().statusSet(Z80::FlagBit::Z, (reg - 1) == 0x00);
        Instance().statusSet(Z80::FlagBit::S, (bool) ((reg - 1) & 0x80));
        reg--;
    }

    bool Z80::IsOverflowAdd(uint8_t x, uint8_t y) {
        uint8_t sign_x = x & 0x80;
        uint8_t sign_y = y & 0x80;
        uint8_t sign_addxy = (x+y) & 0x80;

        return (!(sign_x ^ sign_y)) & (sign_x ^ sign_addxy);
    }

    bool Z80::IsOverflowSub(uint8_t x, uint8_t y) {
        uint8_t sign_x = x & 0x80;
        uint8_t sign_y = y & 0x80;
        uint8_t sign_addxy = (x-y) & 0x80;

        return (!(sign_x ^ sign_y)) & (sign_x ^ sign_addxy);
    }

    bool Z80::IsHalfCarryAdd(uint8_t x, uint8_t y) {
        return ((x&0xf) + (y&0xf) & 0x10) == 0x10;
    }

    bool Z80::IsHalfCarrySub(uint8_t x, uint8_t y) {
        return ((x&0xf) - (y&0xf) & 0x10) == 0x10;
    }
}


