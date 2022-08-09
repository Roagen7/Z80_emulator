/*
 * Zilog Z80 emulator in C++
 * author: Roagen7
 * WORK IN PROGRESS
 */

#include <iostream>
#include "Z80.h"

using namespace emulator::cpu;

int main() {

    Z80::Reset();
    Z80::Load("../a.out");
    auto& ins = Z80::Instance();

    while(Z80::Run())
        Z80::Tick();

    return 0;
}
