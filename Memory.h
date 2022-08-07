#pragma once

#include <cstdint>
#include <array>

#define RAM_SIZE 0x10000


namespace emulator::memory {

    class Memory {

    public:
        Memory() = default;
        void writeByte(const uint16_t& addr, const uint8_t& val);
        uint8_t readByte(const uint16_t& addr);

        uint8_t& operator[](const uint16_t& addr);

    private:
        std::array<uint8_t, RAM_SIZE> ram{};

    };
}