#include "Memory.h"


namespace emulator::memory {
    void Memory::writeByte(const uint16_t& addr, const uint8_t& val) {
        ram[addr] = val;
    }

    uint8_t Memory::readByte(const uint16_t& addr) {
        return ram[addr];
    }

    uint8_t &Memory::operator[](const uint16_t& addr) {
        return ram[addr];
    }
}