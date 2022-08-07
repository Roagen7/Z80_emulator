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

        auto opc = Instance().ram[Instance().registers.PC];
        auto& instr = Instance().lookup[opc];

        instr.addressingMode();
        instr.opcode();

    }

    void Z80::Reset() {

    }

    bool Z80::Run() {
        return Instance().run;
    }

}


